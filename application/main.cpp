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

    //SCALAR : Opérateur '='
    a=b;
    std::cout << "Operateur '=' : a=b=" << a << std::endl;

    //SCALAR : Opérateur << (initialisation)
    gca::GCA_scalar c;
    c << 4.0;
    std::cout << "Operateur '<<' (initialisation) : c<<4.0 donne c=" << c << std::endl;

    //SCALAR : Opérateur '<<' (std::cout)
    std::cout << "Operateur '<<' (sd::cout) : a=" << a << std::endl;

    //SCALAR : Opérateur wedge '^'
    gca::GCA_scalar d = a^b;
    std::cout << "Operateur wedge '^' : d=a^b=" << d <<std::endl;
    return 0;
}

// g++ -I ~/eigen main.cpp -o exe
