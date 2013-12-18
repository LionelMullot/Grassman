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

    GCA_antiquadvector operator^(const GCA_scalar& Other) const;
    GCA_vector operator^(GCA_vector& Other) const;
    GCA_bivector operator^(GCA_bivector& Other) const;
    GCA_trivector operator^(GCA_trivector& Other) const;
    GCA_quadvector operator^(GCA_quadvector& Other) const;
    GCA_scalar operator^(const GCA_antiscalar& Other) const;

    GCA_scalar operator~() const;

    //Affichage

    friend std::ostream& operator<<(std::ostream& os, const GCA_antiquadvector& antiquadvector);

    double& getValue(){ return value; }
    const double& getValue() const{ return value; }
    double& e1234() { return value; }
    const double& e1234() const{ return value; }

private:
    double value;
};

}

