#pragma once

#include <iostream>
#include "GCA_vector.hpp"

namespace gca{

class GCA_antiquadvector;

class GCA_antiscalar{
public:
    //Constructeur
    GCA_antiscalar();
    GCA_antiscalar(const GCA_antiscalar& other);
    GCA_antiscalar(const double value);

    //Opérateur
    GCA_antiscalar& operator=(const GCA_antiscalar& Other);

    GCA_antiscalar& operator^(const GCA_antiscalar& Other);

    GCA_vector operator^(GCA_vector vector);

    GCA_antiscalar& operator<<(const double& in);

    GCA_quadvector operator~() const;

    //Affichage
    friend std::ostream& operator<<(std::ostream& os, GCA_antiscalar& scalar);

    double& getValue(){ return value; }
    const double& getValue() const{ return value; }

private:
    double value;
};

}

