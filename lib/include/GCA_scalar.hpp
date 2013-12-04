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

    //Operateur
	GCA_scalar& operator=(const GCA_scalar& Other);

	GCA_scalar& operator^(const GCA_scalar& Other); //N'est pas const car modifie le scalar appelé

	GCA_vector operator^(GCA_vector vector) const;
	GCA_bivector operator^(GCA_bivector bivector) const;
	GCA_trivector operator^(GCA_trivector trivector) const;
	GCA_quadvector operator^(GCA_quadvector quadvector) const;

    GCA_scalar& operator<<(const double& in);

    GCA_antiquadvector operator~();

    //Affichage 
    friend std::ostream& operator<<(std::ostream& os, const GCA_scalar& scalar);

    const double& getValue() const{ return value; }


private:
    double value;
};

}

