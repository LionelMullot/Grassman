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

    //Opérateur
    GCA_antibivector& operator=(const GCA_antibivector& Other);

    //Wedge
    GCA_antibivector operator^(const GCA_scalar& Other) const;
    GCA_trivector operator^(const GCA_vector& Other) const;
    GCA_quadvector operator^(const GCA_bivector& Other) const;
    GCA_bivector operator^(const GCA_antiscalar& Other) const;
    GCA_vector operator^(const GCA_antivector& Other) const;
    GCA_scalar operator^(const GCA_antibivector& Other) const;

    GCA_bivector operator~() const;

    //Affichage
    friend std::ostream& operator<<(std::ostream& Stream, const GCA_antibivector& in);

private:
	/********* Ordre des composantes ********
	*	(en base dual)
	*	e34, e24, e23, e14, e13, e12
	*
	***/

    std::vector<unsigned int> composantes;

	void setComposantes();
};

}
