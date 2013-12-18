#include "grassmannCayley.hpp"
#include <iostream>

gca::GCA_antiquadvector::GCA_antiquadvector():
    value(1){}

gca::GCA_antiquadvector::GCA_antiquadvector(const gca::GCA_antiquadvector& other):
    value(other.value){}

gca::GCA_antiquadvector::GCA_antiquadvector(const double value):
    value(value){}

gca::GCA_antiquadvector& gca::GCA_antiquadvector::operator=(const gca::GCA_antiquadvector& Other){
    this->value = Other.value;
}

gca::GCA_antiquadvector gca::GCA_antiquadvector::operator^(const gca::GCA_scalar& Other) const{
    gca::GCA_antiquadvector result;
    result = Other^this[0];
    return result;
}

gca::GCA_vector gca::GCA_antiquadvector::operator^(gca::GCA_vector& Other) const{
    gca::GCA_vector result;
    result = Other^this[0];
    return result;
}

gca::GCA_bivector gca::GCA_antiquadvector::operator^(gca::GCA_bivector& Other) const{
    gca::GCA_bivector result;
    result = Other^this[0];
    return result;
}

gca::GCA_trivector gca::GCA_antiquadvector::operator^(gca::GCA_trivector& Other) const{
    gca::GCA_trivector result;
    result = Other^this[0];
    return result;
}

gca::GCA_quadvector gca::GCA_antiquadvector::operator^(gca::GCA_quadvector& Other) const{
    gca::GCA_quadvector result;
    result = Other^this[0];
    return result;
}

gca::GCA_scalar gca::GCA_antiquadvector::operator^(const gca::GCA_antiscalar& Other) const{
  GCA_scalar result;
  result.getValue() = this[0].getValue() * Other.getValue();
  return result;
}

gca::GCA_antiquadvector& gca::GCA_antiquadvector::operator<<(const double& in){
    this->value = in;
}

gca::GCA_scalar gca::GCA_antiquadvector::operator~() const{
    gca::GCA_scalar result;
    result = this->value;
    return result;
}

namespace gca{

std::ostream& operator<<(std::ostream& os, const gca::GCA_antiquadvector& antiquadvector){
    os << "[ " << antiquadvector.getValue() << " e1234 ]";
    return os;
}

}
