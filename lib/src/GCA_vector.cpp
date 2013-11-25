#include "GCA_vector.hpp"
#include <iostream>

gca::GCA_vector::GCA_vector():
    Eigen::Vector4d(Eigen::Vector4d::Zero()) {}

gca::GCA_vector::GCA_vector(double x, double y, double z, double w):
    Eigen::Vector4d(x, y, z, w) {}

gca::GCA_vector::GCA_vector(const gca::GCA_vector& other):
    Eigen::Vector4d(other) {}

gca::GCA_vector& gca::GCA_vector::operator=(const gca::GCA_vector& Other){
    this->Eigen::Vector4d::operator=(Other);
}

gca::GCA_bivector& gca::GCA_vector::operator^(const gca::GCA_vector& Other){}

gca::GCA_antitrivector& gca::GCA_vector::operator~() {}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_vector& in){
        Stream << "[";
            Stream << " " << in.transpose();
        Stream << " ]";
        return Stream;
    }

}