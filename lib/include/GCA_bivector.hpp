#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>
#include <vector>

namespace gca{

class GCA_bivector : public Eigen::VectorXd{
public:
	//Constructeur
	GCA_bivector();
	GCA_bivector(const GCA_bivector& other);
    GCA_bivector(const double e12, const double e13, const double e14, const double e23, const double e24, const double e34);


	//Operateur
    GCA_bivector& operator=(const GCA_bivector& Other);

    //Wedges Base
    GCA_bivector operator^(const GCA_scalar& value); //N'est pas const car modifie le bivector appelé
    GCA_trivector operator^(const GCA_vector& Other) const;
    GCA_quadvector operator^(const GCA_bivector& Other) const;

    //Wedges Base duale
    GCA_quadvector operator^(const GCA_antibivector& Other) const;
    GCA_trivector operator^(const GCA_antitrivector& Other) const;
    GCA_bivector operator^(const GCA_antiquadvector& Other);

    GCA_antibivector operator~() const;

    //Affichage
    friend std::ostream& operator<<(std::ostream& Stream, const GCA_bivector& in);
    
    const double& e12() const{return this[0][0];} 
    const double& e13() const{return this[0][1];} 
    const double& e14() const{return this[0][2];}
    const double& e23() const{return this[0][3];}
    const double& e24() const{return this[0][4];}
    const double& e34() const{return this[0][5];} 

    //Récupération valeur pour modification
    double& e12() {return this[0][0];} 
    double& e13() {return this[0][1];} 
    double& e14() {return this[0][2];}
    double& e23() {return this[0][3];}
    double& e24() {return this[0][4];}
    double& e34() {return this[0][5];} 

private:
    /********* Ordre des composantes ********
    *
    *   e12, e13, e14, e23, e24, e34
    *
    ***/
    
    std::vector<unsigned int> composantes;

	void setComposantes();
};

}
