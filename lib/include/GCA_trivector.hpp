#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>
#include <vector>

namespace gca{

class GCA_trivector: public Eigen::Vector4d{
public:
	//Constructeur
	GCA_trivector();
    GCA_trivector(double x, double y, double z, double w);
    GCA_trivector(const GCA_trivector& other);

    //Opérateur
    GCA_trivector& operator=(const GCA_trivector& Other);

    //Wedge base
    GCA_trivector operator^(const GCA_scalar value); //N'est pas const car modifie le trivector appelé
    GCA_quadvector operator^(const GCA_vector Other) const;

    //Wedge base duale
    GCA_quadvector operator^(const GCA_antitrivector Other) const;
    GCA_trivector operator^(const GCA_antiquadvector value);

    GCA_antivector operator~() const;

    //Affichage
    friend std::ostream& operator<<(std::ostream& Stream, const GCA_trivector& in);

    const double& e123() const{return this[0][0];} 
    const double& e124() const{return this[0][1];} 
    const double& e134() const{return this[0][2];}
    const double& e234() const{return this[0][3];} 

    //Récupération
    double& e123() {return this[0][0];} 
    double& e124() {return this[0][1];} 
    double& e134() {return this[0][2];}
    double& e234() {return this[0][3];}

private:
    /********* Ordre des composantes ********
    *
    *   e123, e124, e134, e234 
    *
    ***/
    std::vector<unsigned int> composantes;

	void setComposantes();
};

}
