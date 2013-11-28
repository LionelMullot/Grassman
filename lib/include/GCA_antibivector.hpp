#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>
#include "GCA_bivector.hpp"

namespace gca{

class GCA_bivector;

class GCA_antibivector : public Eigen::VectorXd{
public:
    GCA_antibivector();
    GCA_antibivector(const GCA_antibivector& other);

    GCA_antibivector& operator=(const GCA_antibivector& Other);

    GCA_bivector operator~(); //Changer le type de retour

    friend std::ostream& operator<<(std::ostream& Stream, const GCA_antibivector& in);

};

}
