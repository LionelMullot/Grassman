#include "grassmannCayley.hpp"
#include <iostream>

gca::GCA_antitrivector::GCA_antitrivector():
    Eigen::Vector4d(Eigen::Vector4d::Zero()) {
        setComposantes();
    }

gca::GCA_antitrivector::GCA_antitrivector(double x, double y, double z, double w):
    Eigen::Vector4d(x, y, z, w) {
        setComposantes();
    }

gca::GCA_antitrivector::GCA_antitrivector(const gca::GCA_antitrivector& other):
    Eigen::Vector4d(other), composantes(other.composantes) {}

void gca::GCA_antitrivector::setComposantes(){
    for(unsigned int i = 4; i > 0; --i){
        composantes.push_back(i);
    }
}

gca::GCA_antitrivector& gca::GCA_antitrivector::operator=(const gca::GCA_antitrivector& Other){
    this->Eigen::Vector4d::operator=(Other);
}

gca::GCA_antitrivector gca::GCA_antitrivector::operator^(const gca::GCA_scalar& Other) const{
    gca::GCA_antitrivector result;
    result = Other^this[0];
    for(unsigned int i = 0; i < result.size(); ++i){
        result[i] = -result[i]; // a^b = -b^a
    }
    return result;
}

gca::GCA_bivector gca::GCA_antitrivector::operator^(const gca::GCA_vector& Other) const{
    gca::GCA_bivector result;
    result = Other^this[0];
    for(unsigned int i = 0; i < result.size(); ++i){
        result[i] = -result[i]; // a^b = -b^a
    }
    return result;
}

gca::GCA_trivector gca::GCA_antitrivector::operator^(const gca::GCA_bivector& Other) const{
    gca::GCA_trivector result;
    result = Other^this[0];
    for(unsigned int i = 0; i < result.size(); ++i){
        result[i] = -result[i]; // a^b = -b^a
    }
    return result;
}

gca::GCA_quadvector gca::GCA_antitrivector::operator^(const gca::GCA_trivector& Other) const{
    gca::GCA_quadvector result;
    result = Other^this[0];
    result.getValue() = -result.getValue();
    return result;
}

gca::GCA_vector gca::GCA_antitrivector::operator^(const gca::GCA_antiscalar& Other) const{
  GCA_vector result;
  for(unsigned int i = 0; i < this[0].size(); ++i){
    result[i] = this[0][i] * Other.getValue();
  }
  return result;
}

gca::GCA_scalar gca::GCA_antitrivector::operator^(const gca::GCA_antivector& Other) const{
  GCA_scalar result;
  result = Other^this[0];
  result.getValue() = -result.getValue();
  return result;
}

gca::GCA_vector gca::GCA_antitrivector::operator~() const{
    gca::GCA_vector result;
    result << this[0][3], -this[0][2], this[0][1], -this[0][0];
    return result;
}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_antitrivector& in){
        Stream << "[ ";
            for(unsigned int i = 0; i < in.composantes.size(); ++i)
                Stream << in(i) <<" e" << in.composantes[i] << " ; ";
        Stream << "]";
        return Stream;
    }

}
