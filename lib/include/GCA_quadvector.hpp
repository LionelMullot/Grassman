#pragma once

#include <iostream>

namespace gca{

class GCA_antiscalar;

class GCA_quadvector{
public:
    //Constructeur
    GCA_quadvector();
    GCA_quadvector(const GCA_quadvector& other);
    GCA_quadvector(const double value);

    GCA_quadvector& operator=(const GCA_quadvector& Other);
    GCA_quadvector& operator<<(const double& in);

    GCA_antiscalar operator~();

    double& getValue(){ return value; }
    const double& e1234() const{ return value; }


private:
    double value;
};

std::ostream& operator<<(std::ostream& os, GCA_quadvector& quadvector);
}

