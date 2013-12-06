#include "GCA_antiquadvector.hpp"
#include "GCA_scalar.hpp"
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

gca::GCA_antiquadvector& gca::GCA_antiquadvector::operator<<(const double& in){
    this->value = in;
}

gca::GCA_scalar gca::GCA_antiquadvector::operator~() const{
    gca::GCA_scalar result;
    result = this->value;
    return result;
}

namespace gca{

std::ostream& operator<<(std::ostream& os, gca::GCA_antiquadvector& antiquadvector){
  os << antiquadvector.getValue();
  return os;
}

}