#include <iostream>
#include <Eigen/Dense>
#include <Eigen/QR>
#include <GCA_scalar.hpp>
#include <GCA_vector.hpp>

int main(){

    gca::GCA_scalar a(2.0);
    gca::GCA_scalar b(3.0);
    gca::GCA_vector u(1.0,2.0,4.0,1.0);

    //VECTOR : Opérateur '<<' (std::cout)
    std::cout << "Operateur '<<' (std::cout) : u=" << u << std::endl;

    //SCALAR : Opérateur wedge avec vector '^'
    gca::GCA_vector v = a^u;
    std::cout << "Operateur wedge avec vector '^' : " << v << std::endl;

    //SCALAR : Opérateur '='
    a=b;
    std::cout << "Operateur '=' : a=b=" << a << std::endl;

    //SCALAR : Opérateur << (initialisation)
    gca::GCA_scalar c;
    c << 4.0;
    std::cout << "Operateur '<<' (initialisation) : c<<4.0 donne c=" << c << std::endl;

    //SCALAR : Opérateur '<<' (std::cout)
    std::cout << "Operateur '<<' (std::cout) : a=" << a << std::endl;

    //SCALAR : Opérateur wedge '^'
    gca::GCA_scalar d = a^b;
    std::cout << "Operateur wedge '^' : d=a^b=" << d <<std::endl;

    return 0;
}

// g++ -I ~/eigen main.cpp -o exe
