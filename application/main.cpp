#include <iostream>
#include <Eigen/Dense>
#include <Eigen/QR>
#include <GCA_scalar.hpp>
#include <GCA_vector.hpp>

int main(){

    Eigen::MatrixXd mat = Eigen::MatrixXd::Zero(4,4);
    std::cout << mat.transpose() << std::endl;

    gca::GCA_scalar a(2.0);
    gca::GCA_scalar b(3.0);

    std::cout << "a=" << a << " b=" << b <<std::endl;
    return 0;
}

// g++ -I ~/eigen main.cpp -o exe
