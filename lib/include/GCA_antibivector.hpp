#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>
#include <vector>

#include "GCA_bivector.hpp"

namespace gca{

class GCA_bivector;

class GCA_antibivector : public Eigen::VectorXd{
public:
	//Constructeur
    GCA_antibivector();
    GCA_antibivector(const GCA_antibivector& other);

    //Opérateur
    GCA_antibivector& operator=(const GCA_antibivector& Other);

    GCA_bivector operator~();

    //Affichage
    friend std::ostream& operator<<(std::ostream& Stream, const GCA_antibivector& in);

private:
	/********* Ordre des composantes ********
	*
	*	
	*
	***/

	std::vector<uint> composantes;

	void setComposantes();
};

}
