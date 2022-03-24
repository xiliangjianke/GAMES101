#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <eigen3/Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;

Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
	Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

	Eigen::Matrix4f translate;
	translate << 1, 0, 0, -eye_pos[0],
				0, 1, 0, -eye_pos[1], 
				0, 0, 1, -eye_pos[2], 
				0, 0, 0, 1;

	view = translate * view;

	return view;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
	Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

	// TODO: Implement this function
	// Create the model matrix for rotating the triangle around the Z axis.
	// Then return it.
	double theta = rotation_angle / 180.0 * MY_PI;

	model << std::cos(theta), std::sin(theta), 0, 0,
		-std::sin(theta), std::cos(theta), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1;

	return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
	float zNear, float zFar)
{
	// Students will implement this function

	Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

	// TODO: Implement this function
	// Create the projection matrix for the given parameters.
	// Then return it.

	// Transformation matrix of perspective projection to orthographic projection
	Eigen::Matrix4f PerspToOrth;
	PerspToOrth << zNear, 0, 0, 0,
		0, zNear, 0, 0,
		0, 0, zNear + zFar, -zNear * zFar,
		0, 0, 0, 1;

	// Tan(fov/2) = height/2, aspect = weight / height
	float Height = std::atan(eye_fov / 2 / 180 * MY_PI) * 2;
	float Width = aspect_ratio * Height;

	Eigen::Matrix4f ViewPort;
	ViewPort << Width / 2, 0, 0, Width / 2,
		0, Height / 2, 0, Height / 2,
		0, 0, 1, 0,
		0, 0, 0, 1;

	projection = ViewPort * PerspToOrth;

	return projection;
}

Eigen::Matrix4f get_rotation(Vector3f axis, float angle)
{
	// https://www.bilibili.com/read/cv11925407
	Eigen::Matrix4f model = Eigen::Matrix4f::Identity();
	angle = angle / 180.f * MY_PI;
	axis.normalize();
	/*
	float = square = axis[0]*axis[0] + axis[1]*axis[1] + axis[2]*axis[2];
	axis[0] /= std::sqrt(square);
	axis[1] /= std::sqrt(square);
	axis[2] /= std::sqrt(square);
	*/
	Eigen::Matrix3f k;
	k << 0.f, -axis[2], axis[1],
		axis[2], 0.f, -axis[0],
		-axis[1], axis[0], 0.f;
	Eigen::Matrix3f E = Eigen::Matrix3f::Identity();
	Eigen::Matrix3f rotation_matrix;
	rotation_matrix = E * std::cos(angle) + std::sin(angle) * k + (1 - std::cos(angle)) * axis * axis.transpose();

	model.block<3, 3>(0, 0) = rotation_matrix;
	return model;

}
int main(int argc, const char** argv)
{
	float angle = 45.0f;
	Eigen::Vector3f axis(0, 0, 1);
	bool command_line = false;
	std::string filename = "output.png";

	if (argc >= 3) {
		command_line = true;
		angle = std::stof(argv[2]); // -r by default
		if (argc == 4) {
			filename = std::string(argv[3]);
		}
	}

	rst::rasterizer r(700, 700);

	Eigen::Vector3f eye_pos = { 0, 0, 5 };

	std::vector<Eigen::Vector3f> pos{ {2, 0, -2}, {0, 2, -2}, {-2, 0, -2} };

	std::vector<Eigen::Vector3i> ind{ {0, 1, 2} };

	auto pos_id = r.load_positions(pos);
	auto ind_id = r.load_indices(ind);

	int key = 0;
	int frame_count = 0;

	if (command_line) {
		r.clear(rst::Buffers::Color | rst::Buffers::Depth);

		r.set_model(get_model_matrix(angle));
		r.set_view(get_view_matrix(eye_pos));
		r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

		r.draw(pos_id, ind_id, rst::Primitive::Triangle);
		cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
		image.convertTo(image, CV_8UC3, 1.0f);

		cv::imwrite(filename, image);

		return 0;
	}

	while (key != 27) {
		r.clear(rst::Buffers::Color | rst::Buffers::Depth);

		//r.set_model(get_rotation(axis, angle));

		r.set_model(get_model_matrix(angle));
		r.set_view(get_view_matrix(eye_pos));
		r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

		r.draw(pos_id, ind_id, rst::Primitive::Triangle);

		cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
		image.convertTo(image, CV_8UC3, 1.0f);
		cv::imshow("image", image);
		key = cv::waitKey(10);

		std::cout << "frame count: " << frame_count++ << '\n';

		if (key == 'a') {
			angle += 10;
		}
		else if (key == 'd') {
			angle -= 10;
		}
	}

	return 0;
}
