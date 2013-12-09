#pragma once

#include <iostream>

namespace gca{

class GCA_quadvector{
public:
    //Constructeur
    GCA_quadvector();
    GCA_quadvector(const GCA_quadvector& other);
    GCA_quadvector(const double value);

    //Opérateur
    GCA_quadvector& operator=(const GCA_quadvector& Other);
    GCA_quadvector& operator<<(const double& in);

    GCA_quadvector operator^(const GCA_scalar value);
    GCA_quadvector operator^(const GCA_antiquadvector value);

    GCA_antiscalar operator~() const;

    //Affichage
    friend std::ostream& operator<<(std::ostream& os, const GCA_quadvector& quadvector);
    double& getValue(){ return value; }
    const double& getValue() const{ return value; } //Utiliser pour l'affichage d'un quadvector qui serait const
    const double& e1234() const{ return value; }


private:
    double value;
};

}
