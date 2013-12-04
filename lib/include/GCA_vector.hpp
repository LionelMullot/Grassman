#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>
#include <vector>

#include "GCA_bivector.hpp"

namespace gca{

class GCA_bivector;
class GCA_antitrivector;

class GCA_vector : public Eigen::Vector4d{
public:
	//Constructeur
    GCA_vector();
    GCA_vector(const GCA_vector& other);
    GCA_vector(double x, double y, double z, double w);

    //Opérateur
    GCA_vector& operator=(const GCA_vector& Other);

    GCA_bivector operator^(const GCA_vector& Other);

    GCA_antitrivector& operator~();

    //Affichage

    friend std::ostream& operator<<(std::ostream& Stream, const GCA_vector& in);

    const double& e1() const{return this[0][0];} 
    const double& e2() const{return this[0][1];} 
    const double& e3() const{return this[0][2];}
    const double& e4() const{return this[0][3];}

private:
    /********* Ordre des composantes ********
    *
    *   e1, e2, e3, e4
    *
    ***/
	std::vector<uint> composantes;

	void setComposantes();
};



}
