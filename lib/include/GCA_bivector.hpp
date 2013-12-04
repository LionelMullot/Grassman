#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>
#include <vector>

#include "GCA_trivector.hpp"
#include "GCA_antibivector.hpp"

namespace gca{

class GCA_vector;
class GCA_antibivector;
class GCA_quadvector;

class GCA_bivector : public Eigen::VectorXd{
public:
	//Constructeur
	GCA_bivector();
	GCA_bivector(const GCA_bivector& other);

	//Operateur
    GCA_bivector& operator=(const GCA_bivector& Other);

    GCA_trivector operator^(const GCA_vector& Other);

    GCA_quadvector& operator^(const GCA_bivector& Other); 

    GCA_antibivector operator~(); //Changer le type de retour

    //Affichage
    friend std::ostream& operator<<(std::ostream& Stream, const GCA_bivector& in);
    
    const double& e12() const{return this[0][0];} 
    const double& e13() const{return this[0][1];} 
    const double& e14() const{return this[0][2];}
    const double& e23() const{return this[0][3];}
    const double& e24() const{return this[0][4];}
    const double& e34() const{return this[0][5];} 

private:
    /********* Ordre des composantes ********
    *
    *   e12, e13, e14, e23, e24, e34
    *
    ***/
    
	std::vector<uint> composantes;

	void setComposantes();
};

}
