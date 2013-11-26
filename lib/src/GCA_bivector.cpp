#include "GCA_bivector.hpp"
#include <iostream>

gca::GCA_bivector::GCA_bivector():
    Eigen::VectorXd(Eigen::VectorXd::Zero(6)) {}

gca::GCA_bivector::GCA_bivector(const gca::GCA_bivector& other):
    Eigen::VectorXd(other) {}

gca::GCA_bivector& gca::GCA_bivector::operator=(const gca::GCA_bivector& Other){
    this->Eigen::VectorXd::operator=(Other);
}


gca::GCA_quadvector& gca::GCA_bivector::operator^(const gca::GCA_bivector& Other){}

gca::GCA_antibivector& gca::GCA_bivector::operator~() {}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_bivector& in){
        Stream << "[";
            Stream << in.transpose();
        Stream << " ]";
        return Stream;
    }

}
