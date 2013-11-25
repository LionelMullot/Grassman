#pragma once

#include <iostream>
#include "GCA_vector.hpp"

namespace gca{

class GCA_antiquadvector;

class GCA_scalar{
public:
	//Constructeur
	GCA_scalar();
	GCA_scalar(const GCA_scalar& other);
	GCA_scalar(const double value);

    double& getValue();

	GCA_scalar& operator=(const GCA_scalar& Other);

	GCA_scalar& operator^(const GCA_scalar& Other);

	GCA_vector operator^(GCA_vector vector);

    GCA_scalar& operator<<(const double& in);

	GCA_antiquadvector& operator~();


private:
    double value;
};
// A mettre en dehors de la classe. A voir comment ça se comportera pour les autres classes.
std::ostream& operator<<(std::ostream& os, GCA_scalar& scalar);
}

