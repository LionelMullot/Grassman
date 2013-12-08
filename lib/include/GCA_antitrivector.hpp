#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>
#include <vector>

namespace gca{

class GCA_antitrivector: public Eigen::Vector4d{
public:
	//Constructeur
	GCA_antitrivector();
	GCA_antitrivector(const GCA_antitrivector& other);
    GCA_antitrivector(double x, double y, double z, double w);

    //Opérateur
    GCA_antitrivector& operator=(const GCA_antitrivector& Other);

    GCA_vector operator~() const;

    //Affichage

    friend std::ostream& operator<<(std::ostream& Stream, const GCA_antitrivector& in);

    const double& e123() const{return this[0][0];} 
    const double& e124() const{return this[0][1];} 
    const double& e134() const{return this[0][2];}
    const double& e234() const{return this[0][3];}

private:
	/********* Ordre des composantes ********
	*
	*	e123, e124, e134, e234
	*
	***/
    std::vector<unsigned int> composantes;

	void setComposantes();
};

}
