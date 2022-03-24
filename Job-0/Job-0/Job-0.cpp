// Job-0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
#include<Eigen/Core>
#include<eigen3/Eigen/Dense>
#include <opencv2/opencv.hpp>
#include<iostream>
/*
int main() {

    // Basic Example of cpp
    std::cout << "Example of cpp \n";
    float a = 1.0, b = 2.0;
    std::cout << a << std::endl;
    std::cout << a / b << std::endl;
    std::cout << std::sqrt(b) << std::endl;
    std::cout << std::acos(-1) << std::endl;
    std::cout << std::sin(30.0 / 180.0 * acos(-1)) << std::endl;

    // Example of vector
    std::cout << "Example of vector \n";
    // vector definition
    Eigen::Vector3f v(1.0f, 2.0f, 3.0f);
    Eigen::Vector3f w(1.0f, 0.0f, 0.0f);
    // vector output
    std::cout << "Example of output \n";
    std::cout << v << std::endl;
    // vector add
    std::cout << "Example of add \n";
    std::cout << v + w << std::endl;
    // vector scalar multiply
    std::cout << "Example of scalar multiply \n";
    std::cout << v * 3.0f << std::endl;
    std::cout << 2.0f * v << std::endl;

    // Example of matrix
    std::cout << "Example of matrix \n";
    // matrix definition
    Eigen::Matrix3f i, j;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    // matrix output
    std::cout << "Example of output \n";
    std::cout << i << std::endl;
    // matrix add i + j
    // matrix scalar multiply i * 2.0
    // matrix multiply i * j
    // matrix multiply vector i * v


    
    * PA 0
    
    // TO DO: Define point P
    Eigen::Vector3f P(2.0, 1.0, 1.0);

    // Convert to radians
    double Theta = 45 / 180 * std::acos(-1);
    // Rotation matrix
    Eigen::Matrix3f Rotation;
    Rotation << std::cos(Theta), -std::sin(Theta), 0,
        std::sin(Theta), std::cos(Theta), 0,
        0, 0, 1;

    Eigen::Matrix3f Traslation;
    Traslation << 0, 0, 1,
        0, 0, 2,
        0, 0, 1;

    P = Traslation * Rotation * P;
    std::cout << "Final answer: " << std::endl;
    std::cout << P << std::endl;
    // TO DO: Define rotation matrix M
    // TO DO: M * P
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
*/
