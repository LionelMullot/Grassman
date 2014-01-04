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

    //Wedge
    GCA_antivector operator^(const gca::GCA_scalar& Other) const;
    GCA_quadvector operator^(const gca::GCA_vector& Other) const;

    //Anti Wedge
    GCA_trivector operator^(const gca::GCA_antiscalar& Other) const;
    GCA_bivector operator^(const gca::GCA_antivector& Other) const;
    GCA_vector operator^(const gca::GCA_antibivector& Other) const;
    GCA_scalar operator^(const gca::GCA_antitrivector& Other) const;

    GCA_trivector& operator~() const;

    //Affichage

    friend std::ostream& operator<<(std::ostream& Stream, const GCA_antivector& in);

    const double& e234() const{return this[0][0];} 
    const double& e134() const{return this[0][1];} 
    const double& e124() const{return this[0][2];}
    const double& e123() const{return this[0][3];}

private:
	/********* Ordre des composantes ********
	*   En base normal
	*	e234, e134, e124, e123
	*
	***/
    std::vector<unsigned int> composantes;

	void setComposantes();
};

}
