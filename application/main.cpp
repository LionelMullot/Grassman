#include "grassmannCayley.hpp"
#include <iostream>


void codeTest (){
  std :: cout << "" << std :: endl ;
    gca :: GCA_vector a (1.0 ,2.0 ,3.0 ,1.0);
    gca :: GCA_vector b ;
    b << 3.0 , 2.0 , 1.0 , 1.0;
    gca :: GCA_bivector l = a ^ b ; // l is a Plucker line
    std :: cout << " l : " << l << std :: endl ;
    gca :: GCA_vector x1 (2.0 , -1.0 , -1.0 ,1.0);
    gca :: GCA_vector x2 (1.0 , -1.0 ,1.0 ,1.0);
    gca :: GCA_vector x3 ( -1.0 , -1.0 , -2.0 ,1.0);
    gca :: GCA_trivector d = x1 ^ x2 ^ x3 ; // d is a plane
    std :: cout << " intersection : " << (~ d^~ l) << std :: endl ;
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

        //SCALAR : Opérateur wedge avec antiquadvector '^'
        gca::GCA_antiquadvector aqu(2);
        std::cout << "Antiquadvector aqu : " << aqu << std::endl;
        gca::GCA_antiquadvector aqv = a^aqu;
        std::cout << "Operateur wedge avec Antiquadvector 'a^aqu' : " << aqv << std::endl;

        //SCALAR : Opérateur wedge avec antitrivector '^'
        gca::GCA_antitrivector atriu;
        atriu << 2, 3, -1, 1;
        std::cout << "Antitrivector qu : " << atriu << std::endl;
        gca::GCA_antitrivector atriv = a^atriu;
        std::cout << "Operateur wedge avec Antitrivector 'a^atriv' : " << atriv << std::endl;

        //SCALAR : Opérateur wedge avec antibivector '^'
        gca::GCA_antibivector abiu;
        abiu << 4, 2, 7, -2, 1, 3;
        std::cout << "Antibivector abiu : " << abiu << std::endl;
        gca::GCA_antibivector abiv = a^abiu;
        std::cout << "Operateur wedge avec Antibivector 'a^abiu' : " << abiv << std::endl;

        //SCALAR : Opérateur wedge avec antivector '^'
        gca::GCA_antivector au(-2,2,8,1);
        std::cout << "Antivector qu : " << au << std::endl;
        gca::GCA_antivector av = a^au;
        std::cout << "Operateur wedge avec Antivector 'a^au' : " << av << std::endl;

        //SCALAR : Opérateur wedge avec antiscalar '^'
        gca::GCA_antiscalar aa(-2);
        std::cout << "Antiscalar aa : " << aa << std::endl;
        b = a^aa;
        std::cout << "Operateur wedge avec antiscalar 'a^aa' : " << b << std::endl;

        //SCALAR : Opérateur ~
        std::cout << "Base dual de a : " << ~a << std::endl;
    }

    {
        std::cout << std::endl << "--------------Vectors-------------" << std::endl;
        gca::GCA_vector u (1.0 ,2.0 ,3.5 ,1.0);
        gca::GCA_vector v;
        v << 3.0 , 2.0 , 1.0 , 1.0;
        gca::GCA_vector w;
        gca::GCA_vector s (2.0, -2.0, 1.0, 1.0);

        //VECTOR : Affiche des vectors
        std::cout << "Creation et affichage des vectors : \n u = " << u << "\n v = " << v << "\n w = " << w << "\n s = " << s << std::endl;

        //VECTOR : Opérateur '='
        w = v;
        std::cout << "Operateur '=' : w=v=" << w << std::endl;

        //VECTOR : opérateur '[]'
        w[0] = 4.0;
        std::cout << "Operateur '[]' w[0] = 4.0 : " << w << std::endl;

        //VECTOR : modification par composante
        w.e1() = -2;
        std::cout << "Modification par composante w.e1() = -2 : " << w << std::endl;

        //VECTOR : opérateur wedge avec scalar '^'
        //Interdit à mon avis, déclarer un scalar avant.
        gca::GCA_scalar a = 2.0;
        std::cout << "Operateur wedge avec scalar 'w^2' : " << (w^a) << std::endl;

        //VECTOR : opérateur wedge avec vector '^'
        std::cout << "Operateur wedge avec vector : \n u^v = " << (u^v) << "\n v^u = " << (v^u) << std::endl;

        //VECTOR : opérateur wedge avec bivector '^'
        std::cout << "Operateur wedge avec bivector : \n w^(u^v) = " << (w^(u^v)) << "\n (u^v)^w = " << ((u^v)^w) << std::endl;

        //VECTOR : opérateur wedge avec trivector '^'
        std::cout << "Operateur wedge avec trivector : \n s^(w^(u^v)) = " << (s^(w^(u^v))) << "\n (w^(u^v))^s = " << ((w^(u^v))^s) <<  std::endl;

        //VECTOR : opérateur wedge avec antivector '^'
        std::cout << "Operateur wedge avec antivector : \n s^(~(w^(u^v))) = " << (s^(~(w^(u^v)))) << "\n (~(w^(u^v)))^s = " << /*((~(w^(u^v)))^s) << */std::endl;

        //VECTOR : opérateur wedge avec antibivector '^'
        std::cout << "Operateur wedge avec antibivector : \n s^(~(u^v)) = " << (s^(~(u^v))) << "\n (~(u^v))^s = " << /*((~(u^v))^s) <<  */ std::endl;

        //VECTOR : opérateur wedge avec antitrivector '^'
        std::cout << "Operateur wedge avec antitrivector : \n s^~v = " << (s^~v) << "\n ~v^s " << /*~v^s << */  std::endl;

        //VECTOR : opérateur wedge avec antiquadvector '^'
        std::cout << "Operateur wedge avec antiquadvector : \n s^~2.0 = " << (s^~a) << std::endl;

        //VECTOR : opérateur ~
        std::cout << "Base dual de v : " << ~v << std::endl;
    }

    {
        std::cout << std::endl << "--------------Bivectors-------------" << std::endl;
        gca::GCA_bivector bivec;
        bivec << 1, 2, 3, 4, 5, 6;
        gca::GCA_bivector bivec2(bivec);
        gca::GCA_bivector bivec3(bivec);


        //BIVECTOR : Affiche des bivectors
        std::cout << "Creation et affichage des bivecteurs : \n bivec = " << bivec << "\n bivec2 = " << bivec2 << "\n bivec3 = " << bivec3 << std::endl;

        //BIVECTOR : opérateur '='
        bivec2 = bivec;
        std::cout << "Operateur '=' : bivec2=bivec=" << bivec2 << std::endl;

        //BIVECTOR : opérateur '[]'
        bivec2[0] = 4.0;
        std::cout << "Operateur '[]' bivec2[0] = 4.0 : " << bivec2 << std::endl;

        //BIVECTOR : modification par composante
        bivec.e13() = -2;
        std::cout << "Modification par composante bivec.e13() = -2 : " << bivec << std::endl;

        //BIVECTOR : Operateur wedge avec scalar '^'
        gca::GCA_scalar a = 2.0;
        std::cout << "Operateur wedge avec scalar : \n bivec^2 = " << (bivec^a) << std::endl;

        //BIVECTOR : Operateur wedge avec vector '^'
        gca::GCA_vector u(1.0,2.0,3.0,1.0);
        std::cout << "Vector u : " << u << std::endl;
        std::cout << "Operateur wedge avec vector : \n bivec^u = " << (bivec^u) << "\n u^bivec = " << (u^bivec) << std::endl;

        //BIVECTOR : Operateur wedge avec bivector '^'
        bivec << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0;
        bivec2 << 2.0, 3.0, 4.0, 6.0, 5.0, 4.0;
        std::cout << "Operateur wedge avec bivector : \n bivec^bivec2 = " << (bivec^bivec2) << "\n bivec2^bivec = " << (bivec2^bivec) << std::endl;

        //BIVECTOR : opérateur wedge avec antibivector '^'
        bivec << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0;
        bivec2 << 2.0, 3.0, 4.0, 6.0, 5.0, 4.0;
        std::cout << "Operateur wedge avec antibivector : \n bivec^(~bivec2) = " << (bivec^(~bivec2)) << "\n (~bivec2)^ bivec = " << std::endl;

        //BIVECTOR : opérateur wedge avec antitrivector '^'
        bivec << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0;
        gca::GCA_vector vec;
        vec << 2.0, 3.0, 4.0, 5.0;
        std::cout << "Operateur wedge avec antitrivector : \n bivec^(~vec) = " << (bivec^(~vec)) << "\n (~vec)^ bivec = " << std::endl;

        //BIVECTOR : opérateur wedge avec antiquadvector '^'
        std::cout << "Operateur wedge avec antiquadvector : \n bivec^~2.0 = " << (bivec^~a) << std::endl;

        //BIVECTOR : opérateur ~
        std::cout << "Base duale de bivec : " << ~bivec << std::endl;
    }

    {
        std::cout << std::endl << "--------------Trivectors-------------" << std::endl;
        gca::GCA_trivector tv1;
        tv1 << 1, 2, 3, 4;
        gca::GCA_trivector tv2;

        gca::GCA_trivector tv3 = tv2;

        //TRIVECTOR : Affiche des trivectors
        std::cout << "Creation et affichage des trivecteurs : \n tv1 = " << tv1 << "\n tv2 = " << tv2 << "\n tv3 = " << tv3 << std::endl;

        //TRIVECTOR : opérateur '='
        tv2 = tv1;
        std::cout << "Operateur '=' : tv2=tv1=" << tv2 << std::endl;

        //TRIVECTOR : opérateur '[]'
        tv1[3] = 4.5;
        std::cout << "Operateur '[]' tv1[3] = 4.5 : " << tv1 << std::endl;

        //TRIVECTOR : modification par composante
        tv1.e123() = -2;
        std::cout << "Modification par composante tv1.e123() = -2 : " << tv1 << std::endl;

        //TRIVECTOR : Operateur wedge avec scalar '^'
        gca::GCA_scalar a = 2.0;
        std::cout << "Operateur wedge avec scalar : \n tv1^2 = " << (tv1^a) << std::endl;

        //TRIVECTOR : Operateur wedge avec vector '^'
        gca::GCA_vector u(1.0,2.0,3.0,1.0);
        std::cout << "Vector u : " << u << std::endl;
        std::cout << "Operateur wedge avec vector : \n tv1^u = " << (tv1^u) << "\n u^tv1 = " << (u^tv1) << std::endl;

        //TRIVECTOR : Operateur wedge avec antitrivector '^'
        std::cout << "Operateur wedge avec antitrivector : \n tv1^~u = " << (tv1^~u) << std::endl;

        //TRIVECTOR : Operateur wedge avec antiquadvector '^'
        std::cout << "Operateur wedge avec scalar : \n tv1^~2 = " << (tv1^~a) << std::endl;

        //TRIVECTOR : Opérateur ~
        std::cout << "Base duale de tv1 : " << ~tv1 << std::endl;
    }

    {
        std::cout << std::endl << "--------------Quadvectors-------------" << std::endl;
        gca::GCA_quadvector qv1;
        qv1 << 1.0;
        gca::GCA_quadvector qv2;
        gca::GCA_quadvector qv3 = qv1;

        //QUADVECTOR : Affiche des quadvectors
        std::cout << "Creation et affichage des quadvectors : \n qv1 = " << qv1 << "\n qv2 = " << qv2 << "\n qv3 = " << qv3 << std::endl;

        //QUADVECTOR : opérateur '='
        qv3 = qv1;
        std::cout << "Operateur '=' : qv3=qv1=" << qv3 << std::endl;

        //QUADVECTOR : opérateur initialisation '<<'
        qv2 << 4.5;
        std::cout << "Operateur '<<' qv2 << 4.5 : " << qv2 << std::endl;

        //QUADVECTOR : Operateur wedge avec scalar '^'
        gca::GCA_scalar a = 2.0;
        std::cout << "Operateur wedge avec scalar : \n qv1^2 = " << (qv1^a) << std::endl;

        //QUADVECTOR : Operateur wedge avec antiquadvector '^'
        std::cout << "Operateur wedge avec antiquadvector : \n qv1^~2 = " << (qv1^~a) << std::endl;

        //QUADVECTOR : Opérateur ~
        gca::GCA_antiscalar ant;
        ant = ~qv1;
        std::cout << "Base duale de qv1 : " << ant << std::endl;
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
*/

    codeTest();

    return 0;
}

// g++ -I ~/eigen main.cpp -o exe
