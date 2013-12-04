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

    {//RAII
        std::cout << std::endl << "--------------Scalaires-------------" << std::endl;

        gca::GCA_scalar a(2.0);
        gca::GCA_scalar b(3.0);

        //SCALAR : Affiche des scalar
        std::cout << "Affichage a : " << a << std::endl << "Affichage b : " << b << std::endl;
       
        //SCALAR : Opérateur '='
        a=b;
        std::cout << "Operateur '=' : a=b=" << a << std::endl;

        //SCALAR : Opérateur << (initialisation)
        gca::GCA_scalar c;
        c << 4.0;
        std::cout << "Operateur '<<' (initialisation) : c<<4.0 donne c=" << c << std::endl;

        //SCALAR : Opérateur wedge '^'
        gca::GCA_scalar d = a^b;
        std::cout << "Operateur wedge '^' : d=a^b=" << d <<std::endl;

        //SCALAR : Opérateur wedge avec vector '^'
        gca::GCA_vector u(2,1,3,4);
        std::cout << "Vector u : " << u << std::endl;
        gca::GCA_vector v = a^u;
        std::cout << "Operateur wedge avec vector 'a^u' : " << v << std::endl;

        //SCALAR : Opérateur wedge avec bivector '^'
        gca::GCA_bivector biu;
        biu << 2, 1, -5, 2, -2, -4;
        std::cout << "Bivector biu : " << biu << std::endl;
        gca::GCA_bivector biv = a^biu;
        std::cout << "Operateur wedge avec bivector 'a^biu' : " << biv << std::endl;

        //SCALAR : Opérateur wedge avec trivector '^'
        gca::GCA_trivector triu;
        triu << 3, 2, -2, 1;
        std::cout << "Trivector triu : " << triu << std::endl;
        gca::GCA_trivector triv = a^triu;
        std::cout << "Operateur wedge avec trivector 'a^triu' : " << triv << std::endl;

        //SCALAR : Opérateur wedge avec quadvector '^'
        gca::GCA_quadvector qu(-2);
        std::cout << "Quadvector qu : " << qu << std::endl;
        gca::GCA_quadvector qv = a^qu;
        std::cout << "Operateur wedge avec Quadvector 'a^qu' : " << qv << std::endl;
    }

    {
        std::cout << std::endl << "--------------Vectors-------------" << std::endl;
        gca::GCA_vector u (1.0 ,2.0 ,3.0 ,1.0);
        gca::GCA_vector v;
        v << 3.0 , 2.0 , 1.0 , 1.0;
        gca::GCA_vector w;
        gca::GCA_vector s (2.0, -2.0, 1.0, 1.0);

        //VECTOR : Affiche des vectors
        std::cout << "Creation et affichage des vectors : \n u = " << u << "\n v = " << v << "\n w = " << w << "\n s = " << s << std::endl;

        //VECTOR : Opérateur '='
        w = v;
        std::cout << "Opérateur '=' : w=v=" << w << std::endl;

        //VECTOR : opérateur '[]'
        w[0] = 4.0;
        std::cout << "Operateur '[]' w[0] = 4.0 : " << w << std::endl;

        //VECTOR : modification par composante
        w.e1() = -2;
        std::cout << "Modification par composante w.e1() = -2 : " << w << std::endl;

        //VECTOR : opérateur wedge avec scalar '^'
        std::cout << "Operateur wedge avec scalar 'w^2' : " << (w^2) << std::endl;

        //VECTOR : opérateur wedge avec vector '^'
        std::cout << "Operateur wedge avec vector : \n u^v = " << (u^v) << "\n v^u = " << (v^u) << std::endl;

        //VECTOR : opérateur wedge avec bivector '^'
        std::cout << "Operateur wedge avec bivector : \n w^(u^v) = " << (w^(u^v)) << "\n (u^v)^w " << ((u^v)^w) << std::endl;

        //VECTOR : opérateur wedge avec trivector '^'
        std::cout << "Operateur wedge avec trivector : \n s^(w^(u^v))" << (s^(w^(u^v))) << "\n (w^(u^v))^s " << ((w^(u^v))^s) <<  std::endl;
    }

    {
        std::cout << std::endl << "--------------Bivectors-------------" << std::endl;

        gca::GCA_bivector bivec;
        bivec << 1, 2, 3, 4, 5, 6;

        gca::GCA_bivector bivec2(bivec);

        gca::GCA_bivector bivec3 = bivec2;

        //BIVECTOR : Affiche des bivectors
        std::cout << "Creation et affichage des bivecteurs : \n bivec = " << bivec << "\n bivec2 = " << bivec2 << "\n bivec3 = " << bivec3 << std::endl;

        //BIVECTOR : affichage composante
        std::cout << "Affichage composante : \n e13 : " << bivec.e13() << "\n e23 : " << bivec.e23() << std::endl;

        //BIVECTOR : opérateur '[]'
        bivec[3] = 4.5;
        std::cout << "Operateur '[]' bivec[3] = 4.5 : " << bivec << std::endl;

        //BIVECTOR : modification par composante
        bivec.e13() = -2;
        std::cout << "Modification par composante bivec.e13() = -2 : " << bivec << std::endl;

        //BIVECTOR : Operateur wedge avec scalar '^'
        std::cout << "Operateur wedge avec scalar : \n bivec^2 = " << (bivec^2) << std::endl;

        //BIVECTOR : Operateur wedge avec vector '^'
        gca::GCA_vector u(1.0,2.0,3.0,1.0);
        std::cout << "Vector u : " << u << std::endl;
        std::cout << "Operateur wedge avec vector : \n bivec^u = " << (bivec^u) << "\n u^bivec = " << (u^bivec) << std::endl;

        //BIVECTOR : Operateur wedge avec bivector '^'
        std::cout << "Operateur wedge avec bivector : \n bivec^bivec2 = " << (bivec^bivec2) << "\n bivec2^bivec = " << (bivec2^bivec) << std::endl;

        //BIVECTOR : Opérateur '~' (std::cout)
        std::cout << "Operateur '~' (std::cout) bivec3 : " << ~bivec3 << std::endl;
    }

    {
        std::cout << std::endl << "--------------Trivectors-------------" << std::endl;

        gca::GCA_trivector tv1;
        tv1 << 1, 2, 3, 4;

        gca::GCA_trivector tv2(tv1);

        gca::GCA_trivector tv3 = tv2;

        //TRIVECTOR : Affiche des bivectors
        std::cout << "Creation et affichage des trivecteurs : \n tv1 = " << tv1 << "\n tv2 = " << tv2 << "\n tv3 = " << tv3 << std::endl;

        //TRIVECTOR : affichage composante
        std::cout << "Affichage composante : \n e123 : " << tv1.e123() << "\n e124 : " << tv1.e124() << std::endl;

        //TRIVECTOR : opérateur '[]'
        tv1[3] = 4.5;
        std::cout << "Operateur '[]' tv1[3] = 4.5 : " << tv1 << std::endl;

        //TRIVECTOR : modification par composante
        tv1.e123() = -2;
        std::cout << "Modification par composante tv1.e123() = -2 : " << tv1 << std::endl;

        //TRIVECTOR : Operateur wedge avec scalar '^'
        std::cout << "Operateur wedge avec scalar : \n tv1^2 = " << (tv1^2) << std::endl;

        //TRIVECTOR : Operateur wedge avec vector '^'
        gca::GCA_vector u(1.0,2.0,3.0,1.0);
        std::cout << "Vector u : " << u << std::endl;
        std::cout << "Operateur wedge avec vector : \n tv1^u = " << (tv1^u) << "\n u^tv1 = " << (u^tv1) << std::endl;

        //TRIVECTOR : Opérateur '~' (std::cout)
        //std::cout << "Operateur '~' (std::cout) tv1 : " << ~tv1 << std::endl;
    }
/*
    std::cout << std::endl << "--------------Anti Scalaires-------------" << std::endl;
    gca::GCA_antiscalar antiscalar1;
    gca::GCA_quadvector quadvec2;
    quadvec2 = 7.0;
    antiscalar1 = ~quadvec2;
    std::cout << "Antiscalar construit par base duale de quadvector, antiscalar1 = " << antiscalar1 << std::endl;

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
*/
    return 0;
}

// g++ -I ~/eigen main.cpp -o exe
