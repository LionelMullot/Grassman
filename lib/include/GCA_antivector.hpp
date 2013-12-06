#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>
#include <vector>

namespace gca{

class GCA_antivector: public Eigen::Vector4d{
public:
	//Constructeur
	GCA_antivector();
	GCA_antivector(const GCA_antivector& other);
    GCA_antivector(double x, double y, double z, double w);

    //Opérateur
    GCA_antivector& operator=(const GCA_antivector& Other);

    GCA_trivector& operator~() const;

    //Affichage

    friend std::ostream& operator<<(std::ostream& Stream, const GCA_antivector& in);

    const double& e1() const{return this[0][0];} 
    const double& e2() const{return this[0][1];} 
    const double& e3() const{return this[0][2];}
    const double& e4() const{return this[0][3];}

private:
	/********* Ordre des composantes ********
	*
	*	e1, e2, e3, e4
	*
	***/
	std::vector<uint> composantes;

	void setComposantes();
};

}