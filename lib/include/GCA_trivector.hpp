#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>
#include <vector>

#include "GCA_antitrivector.hpp"

namespace gca{

class GCA_antivector;

class GCA_trivector: public Eigen::Vector4d{
public:
	//Constructeur
	GCA_trivector();
    GCA_trivector(double x, double y, double z, double w);
    GCA_trivector(const GCA_trivector& other);

    //Opérateur
    GCA_trivector& operator=(const GCA_trivector& Other);
    GCA_antivector& operator~(); //Changer le type de retour

    //Affichage
    friend std::ostream& operator<<(std::ostream& Stream, const GCA_trivector& in);

    const double& e123() const{return this[0][0];} 
    const double& e124() const{return this[0][1];} 
    const double& e134() const{return this[0][2];}
    const double& e234() const{return this[0][3];}

private:
    /********* Ordre des composantes ********
    *
    *   e123, e124, e134, e234 
    *
    ***/
	std::vector<uint> composantes;

	void setComposantes();
};

}
