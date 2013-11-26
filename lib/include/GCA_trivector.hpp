#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>

#include "GCA_antitrivector.hpp"

namespace gca{

class GCA_antitrivector;

class GCA_trivector: public Eigen::VectorXd{
public:
	GCA_trivector();
    GCA_trivector(const GCA_trivector& other);

    GCA_trivector& operator=(const GCA_trivector& Other);

    GCA_antitrivector& operator~(); //Changer le type de retour

    friend std::ostream& operator<<(std::ostream& Stream, const GCA_trivector& in);
};

}
