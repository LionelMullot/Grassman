#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>
#include <vector>

namespace gca{

class GCA_antibivector : public Eigen::VectorXd{
public:
	//Constructeur
    GCA_antibivector();
    GCA_antibivector(const GCA_antibivector& other);
    GCA_antibivector(const double e34, const double e24, const double e23, const double e14, const double e13, const double e12);

    //Opérateur
    GCA_antibivector& operator=(const GCA_antibivector& Other);

    //Wedge
    GCA_antibivector operator^(const GCA_scalar& Other) const;
    GCA_trivector operator^(const GCA_vector& Other) const;
    GCA_quadvector operator^(const GCA_bivector& Other) const;

    //Anti Wedge
    GCA_bivector operator^(const GCA_antiscalar& Other) const;
    GCA_vector operator^(const GCA_antivector& Other) const;
    GCA_scalar operator^(const GCA_antibivector& Other) const;

    GCA_bivector operator~() const;

    //Affichage
    friend std::ostream& operator<<(std::ostream& Stream, const GCA_antibivector& in);

    const double& e12() const{return this[0][5];} 
    const double& e13() const{return this[0][4];} 
    const double& e14() const{return this[0][3];}
    const double& e23() const{return this[0][2];}
    const double& e24() const{return this[0][1];}
    const double& e34() const{return this[0][0];} 

    //Récupération valeur pour modification
    double& e12() {return this[0][5];} 
    double& e13() {return this[0][4];} 
    double& e14() {return this[0][3];}
    double& e23() {return this[0][2];}
    double& e24() {return this[0][1];}
    double& e34() {return this[0][0];} 

private:
	/********* Ordre des composantes ********
	*	En base normal
	*	e34, e24, e23, e14, e13, e12
	*
	***/

    std::vector<unsigned int> composantes;

	void setComposantes();
};

}
