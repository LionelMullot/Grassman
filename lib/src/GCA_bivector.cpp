#include "GCA_bivector.hpp"
#include <iostream>

#include "GCA_vector.hpp"

gca::GCA_bivector::GCA_bivector():
    Eigen::VectorXd(Eigen::VectorXd::Zero(6)) {}

gca::GCA_bivector::GCA_bivector(const gca::GCA_bivector& other):
    Eigen::VectorXd(other) {}

gca::GCA_bivector& gca::GCA_bivector::operator=(const gca::GCA_bivector& Other){
    this->Eigen::VectorXd::operator=(Other);
}

gca::GCA_trivector gca::GCA_bivector::operator^(const gca::GCA_vector& Other){
    gca::GCA_trivector result;
    std::cout << "Other vaut : " << Other << std::endl;
    result[0] = this[0][0]*Other[2] - this[0][1]*Other[1] + this[0][3]*Other[0];
    result[1] = this[0][0]*Other[3] - this[0][2]*Other[1] + this[0][4]*Other[0];
    result[2] = this[0][1]*Other[3] - this[0][2]*Other[2] + this[0][5]*Other[0];
    result[3] = this[0][3]*Other[3] - this[0][4]*Other[2] + this[0][5]*Other[1];
    return result;
}

gca::GCA_quadvector& gca::GCA_bivector::operator^(const gca::GCA_bivector& Other){
}

gca::GCA_antibivector gca::GCA_bivector::operator~() {
    gca::GCA_antibivector result;
    result << this[0][5], -this[0][4], this[0][3], this[0][2], -this[0][1], this[0][0];
    return result;
}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_bivector& in){
        Stream << "[";
            Stream << in.transpose();
        Stream << " ]";
        return Stream;
    }

}
