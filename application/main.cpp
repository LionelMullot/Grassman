#include <iostream>
#include <GCA_scalar.hpp>
#include <GCA_antiscalar.hpp>
#include <GCA_vector.hpp>
#include <GCA_bivector.hpp>
#include <GCA_trivector.hpp>
#include <GCA_quadvector.hpp>
#include <GCA_antiquadvector.hpp>

void plop (){
    gca :: GCA_vector a (1.0 ,2.0 ,3.0 ,1.0);
    gca :: GCA_vector b ;
    b << 3.0 , 2.0 , 1.0 , 1.0;
    gca :: GCA_bivector l = a ^ b ; // l is a Plucker line
    std :: cout << " l : " << l << std :: endl ;
    gca :: GCA_vector x1 (2.0 , -1.0 , -1.0 ,1.0);
    gca :: GCA_vector x2 (1.0 , -1.0 ,1.0 ,1.0);
    gca :: GCA_vector x3 ( -1.0 , -1.0 , -2.0 ,1.0);
   /* gca :: GCA_trivector d = x1 ^ x2 ^ x3 ; // d is a plane
    std :: cout << " intersection : " << ~ d ^~ l << std :: endl ;*/
}


int main(){

    std::cout << std::endl << "--------------Scalaires-------------" << std::endl;

    gca::GCA_scalar a(2.0);
    gca::GCA_scalar b(3.0);
    gca::GCA_vector u(1.0,2.0,4.0,1.0);

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

    //SCALAR : Opérateur wedge avec vector '^'
    gca::GCA_vector v = a^u;
    std::cout << "Operateur wedge avec vector '^' : " << v << std::endl;

    std::cout << std::endl << "--------------Anti Scalaires-------------" << std::endl;
    gca::GCA_antiscalar antiscalar1;
    gca::GCA_quadvector quadvec2;
    quadvec2 = 7.0;
    antiscalar1 = ~quadvec2;
    std::cout << "Antiscalar construit par base duale de quadvector, antiscalar1 = " << antiscalar1 << std::endl;


    std::cout << std::endl << "--------------Vectors-------------" << std::endl;
    gca::GCA_vector vec(1.0,2.0,4.0,1.0);
    std::cout << "Creation du vecteur vec : " << vec << std::endl;

    //VECTOR : opérateur '[]'
    vec[3] = 4.0;
    std::cout << "Operateur '[]' vec[3] = 4.0 : " << vec << std::endl;

    //VECTOR : Opérateur '<<' (std::cout)
    std::cout << "Operateur '<<' (std::cout) vec : " << vec << std::endl;

    //VECTOR : Constructeur par defaut
    gca::GCA_vector vec2;
    std::cout << "Vecteur vec2 : " << vec2 << std::endl;

    std::cout << std::endl << "--------------Bivectors-------------" << std::endl;

    gca::GCA_bivector bivec;
    bivec << 1, 2, 3, 4, 5, 6;

    gca::GCA_bivector bivec3;
    bivec3 << -4, -8, -2, -4, 0, 2;

    std::cout << "Creation du bivecteur bivec : " << bivec << std::endl;

    //BIVECTOR : opérateur '[]'
    bivec[3] = 4.5;
    std::cout << "Operateur '[]' bivec[3] = 4.5 : " << bivec << std::endl;

    //BIVECTOR : Opérateur '<<' (std::cout)
    std::cout << "Operateur '<<' (std::cout) bivec : " << bivec << std::endl;

    //BIVECTOR : Opérateur '~' (std::cout)
    std::cout << "Operateur '~' (std::cout) bivec3 : " << ~bivec3 << std::endl;

    //BIVECTOR : Constructeur par defaut
    gca::GCA_bivector bivec2;
    std::cout << "Vecteur bivec2 : " << bivec2 << std::endl;

    std::cout << std::endl << "--------------Trivectors-------------" << std::endl;
    gca::GCA_vector v1, v2, v3;
    v1 << 1.0, 2.0, 3.0, 1.0;
    v2 << 3.0, 2.0, 1.0, 1.0;
    v3 << 2.0, 1.0, 2.0, 1.0;
    gca::GCA_trivector trivec;
    trivec = v1^v2^v3;
    std::cout << "Trivector construit par wedge de 3 vectors : " << trivec << std::endl;

    std::cout << std::endl << "--------------Quadvectors-------------" << std::endl;
    gca::GCA_quadvector quadv1, quadv2;
    quadv1 << 1.0;
    quadv2 << 3.0;
    std::cout << "Quadvector quadv1 : " << quadv1 << std::endl;
    std::cout << "Composante e1234 : " << quadv1.e1234() << std::endl;

    gca::GCA_antiscalar antiscalar2;
    antiscalar2 = ~quadv2;
    std::cout << "AntiScalaire par base duale de quadv2(egal a 3) antiscalar2= " << antiscalar2 << std::endl;

    std::cout << std::endl << "--------------AntiQuadvectors-------------" << std::endl;
    gca::GCA_antiquadvector antiquadv1;
    gca::GCA_scalar scalar;
    scalar = 7.0;
    antiquadv1 = ~scalar;
    std::cout << "AntiQuadvector antiquadv1 : " << antiquadv1 << std::endl;
    std::cout << "Composante e1234 : " << antiquadv1.e1234() << std::endl;

    antiquadv1 << 9.0;
    scalar = ~antiquadv1;
    std::cout << "Scalaire par base duale d'antiquadv1(egal a 9) scalar= " << scalar << std::endl;



   // plop();

    return 0;
}

// g++ -I ~/eigen main.cpp -o exe
