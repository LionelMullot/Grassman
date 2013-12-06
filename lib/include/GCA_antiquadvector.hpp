#pragma once

#include <iostream>

namespace gca{

class GCA_antiquadvector{
public:
    //Constructeur
    GCA_antiquadvector();
    GCA_antiquadvector(const GCA_antiquadvector& other);
    GCA_antiquadvector(const double value);

    //Opérateur
    GCA_antiquadvector& operator=(const GCA_antiquadvector& Other);
    GCA_antiquadvector& operator<<(const double& in);

    GCA_scalar operator~() const;

    //Affichage

    friend std::ostream& operator<<(std::ostream& os, GCA_antiquadvector& antiquadvector);

    double& getValue(){ return value; }
    const double& e1234() const{ return value; }

private:
    double value;
};

}

