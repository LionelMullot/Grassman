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

    //Wedge
    GCA_antitrivector operator^(const GCA_scalar& Other) const;
    GCA_bivector operator^(const GCA_vector& Other) const;
    GCA_trivector operator^(const GCA_bivector& Other) const;
    GCA_quadvector operator^(const GCA_trivector& Other) const;

    //Anti Wedge
    GCA_vector operator^(const GCA_antiscalar& Other) const;
    GCA_scalar operator^(const GCA_antivector& Other) const;

    GCA_vector operator~() const;

    //Affichage

    friend std::ostream& operator<<(std::ostream& Stream, const GCA_antitrivector& in);

    const double& e4() const{return this[0][0];} 
    const double& e3() const{return this[0][1];} 
    const double& e2() const{return this[0][2];}
    const double& e1() const{return this[0][3];}

private:
	/********* Ordre des composantes ********
	*
	*	e4, e3, e2, e1
	*
	***/
    std::vector<unsigned int> composantes;

	void setComposantes();
};

}
