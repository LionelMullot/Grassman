#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>

#include "GCA_trivector.hpp"

namespace gca{

class GCA_vector;
class GCA_antibivector;
class GCA_quadvector;

class GCA_bivector : public Eigen::VectorXd{
public:
	GCA_bivector();
	GCA_bivector(const GCA_bivector& other);

    GCA_bivector& operator=(const GCA_bivector& Other);

    GCA_trivector operator^(const GCA_vector& Other);

    GCA_quadvector& operator^(const GCA_bivector& Other); 

    GCA_antibivector& operator~(); //Changer le type de retour

    friend std::ostream& operator<<(std::ostream& Stream, const GCA_bivector& in);

};

}
