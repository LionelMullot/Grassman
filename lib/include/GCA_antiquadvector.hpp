#pragma once

#include <iostream>

namespace gca{

class GCA_scalar;

class GCA_antiquadvector{
public:
    //Constructeur
    GCA_antiquadvector();
    GCA_antiquadvector(const GCA_antiquadvector& other);
    GCA_antiquadvector(const double value);

    double& getValue();

    GCA_antiquadvector& operator=(const GCA_antiquadvector& Other);
    GCA_antiquadvector& operator<<(const double& in);

    GCA_scalar& operator~();


private:
    double value;
};

std::ostream& operator<<(std::ostream& os, GCA_antiquadvector& antiquadvector);
}

