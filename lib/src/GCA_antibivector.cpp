#include "GCA_antibivector.hpp"
#include <iostream>

gca::GCA_antibivector::GCA_antibivector():
    Eigen::VectorXd(Eigen::VectorXd::Zero(6)) {}

gca::GCA_antibivector::GCA_antibivector(const gca::GCA_antibivector& other):
    Eigen::VectorXd(other) {}

gca::GCA_antibivector& gca::GCA_antibivector::operator=(const gca::GCA_antibivector& Other){
    this->Eigen::VectorXd::operator=(Other);
}

gca::GCA_bivector gca::GCA_antibivector::operator~() {
    gca::GCA_bivector result;
    result << this[0][5], -this[0][4], this[0][3], this[0][2], -this[0][1], this[0][0];
    return result;
}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_antibivector& in){
        Stream << "[";
            Stream << in.transpose();
        Stream << " ]";
        return Stream;
    }

}
