#include "grassmannCayley.hpp"
#include <iostream>

gca::GCA_antibivector::GCA_antibivector():
    Eigen::VectorXd(Eigen::VectorXd::Zero(6)) {
        setComposantes();
    }

gca::GCA_antibivector::GCA_antibivector(const gca::GCA_antibivector& other):
    Eigen::VectorXd(other), composantes(other.composantes) {}

void gca::GCA_antibivector::setComposantes(){
    for(unsigned int i = 3; i > 0; --i){
        for(unsigned int j = 4; j > i; --j){
            composantes.push_back(i*10 + j);
        }
    }
}

gca::GCA_antibivector& gca::GCA_antibivector::operator=(const gca::GCA_antibivector& Other){
    this->Eigen::VectorXd::operator=(Other);
}

//Wedge
gca::GCA_antibivector gca::GCA_antibivector::operator^(const gca::GCA_scalar& Other) const{
    gca::GCA_antibivector result;
    result = Other^this[0];
    for(unsigned int i = 0; i < result.size(); ++i){
        result[i] = -result[i]; // a^b = -b^a
    }
    return result;
}

gca::GCA_trivector gca::GCA_antibivector::operator^(const gca::GCA_vector& Other) const{
    gca::GCA_trivector result;
    result[0] = this[0][0]*Other[2] - this[0][1]*Other[1] + this[0][3]*Other[0];
    result[1] = this[0][0]*Other[3] - this[0][2]*Other[1] + this[0][4]*Other[0];
    result[2] = this[0][1]*Other[3] - this[0][2]*Other[2] + this[0][5]*Other[0];
    result[3] = this[0][3]*Other[3] - this[0][4]*Other[2] + this[0][5]*Other[1];
    return result;
}

gca::GCA_quadvector gca::GCA_antibivector::operator^(const gca::GCA_bivector& Other) const{
    gca::GCA_quadvector result;
    result = Other^this[0];
    result.getValue() = -result.getValue();
    return result;
}

gca::GCA_bivector gca::GCA_antibivector::operator^(const gca::GCA_antiscalar& Other) const{
  GCA_bivector result;
  for(unsigned int i = 0; i < this[0].size(); ++i){
    result[i] = this[0][i] * Other.getValue();
  }
  return result;
}

gca::GCA_vector gca::GCA_antibivector::operator^(const gca::GCA_antivector& Other) const{
  GCA_vector result;
  result[0] = this[0][0]*Other[2] - this[0][1]*Other[1] + this[0][3]*Other[0];
  result[1] = this[0][0]*Other[3] - this[0][2]*Other[1] + this[0][4]*Other[0];
  result[2] = this[0][1]*Other[3] - this[0][2]*Other[2] + this[0][5]*Other[0];
  result[3] = this[0][3]*Other[3] - this[0][4]*Other[2] + this[0][5]*Other[1];
  return result;
}

gca::GCA_scalar gca::GCA_antibivector::operator^(const gca::GCA_antibivector& Other) const{
  gca::GCA_scalar result;
  unsigned int size = Other.size()-1;

  for(unsigned int i = 0; i <= size; ++i){
      if(i == 1 || i == 4)
          result.getValue() -= (this[0][i]*Other[size - i]);
      else
          result.getValue() += (this[0][i]*Other[size - i]);
  }
  return result;
}

gca::GCA_bivector gca::GCA_antibivector::operator~() const{
    gca::GCA_bivector result;
    result << this[0][5], -this[0][4], this[0][3], this[0][2], -this[0][1], this[0][0];
    return result;
}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_antibivector& in){
        Stream << "[";
            for(unsigned int i = 0; i < in.composantes.size(); ++i)
                Stream << in(i) <<" e" << in.composantes[i] << " ; ";
        Stream << " ]";
        return Stream;
    }

}
