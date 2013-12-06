#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>
#include <vector>

namespace gca{

class GCA_vector : public Eigen::Vector4d{
public:
	//Constructeur
    GCA_vector();
    GCA_vector(const GCA_vector& other);
    GCA_vector(double x, double y, double z, double w);

    //Opérateur
    GCA_vector& operator=(const GCA_vector& Other);

    //Wedge
    GCA_vector operator^(const GCA_scalar& value); //N'est pas const car modifie le vector appelé

    //Base
    GCA_bivector operator^(const GCA_vector& Other) const;
    GCA_trivector operator^(const GCA_bivector& Other) const;
    GCA_quadvector operator^(const GCA_trivector& Other) const;

    //Base dual
    GCA_bivector operator^(const GCA_antitrivector& Other) const;
    GCA_trivector operator^(const GCA_antibivector& Other) const;
    GCA_quadvector operator^(const GCA_antivector& Other) const;

    GCA_antitrivector& operator~() const; //A faire

    //Affichage
    friend std::ostream& operator<<(std::ostream& Stream, const GCA_vector& in);

    const double& e1() const{return this[0][0];} 
    const double& e2() const{return this[0][1];} 
    const double& e3() const{return this[0][2];}
    const double& e4() const{return this[0][3];}

    //Récupération valeur
    double& e1() {return this[0][0];} 
    double& e2() {return this[0][1];} 
    double& e3() {return this[0][2];}
    double& e4() {return this[0][3];}

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
