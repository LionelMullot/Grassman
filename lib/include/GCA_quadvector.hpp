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

    double& getValue();

    GCA_quadvector& operator=(const GCA_quadvector& Other);
    GCA_quadvector& operator<<(const double& in);

    GCA_antiscalar operator~();
    double& e1234();


private:
    double value;
};

std::ostream& operator<<(std::ostream& os, GCA_quadvector& quadvector);
}

