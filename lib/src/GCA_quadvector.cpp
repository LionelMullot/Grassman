#include "GCA_quadvector.hpp"
#include "GCA_antiscalar.hpp"
#include <iostream>

gca::GCA_quadvector::GCA_quadvector():
    value(1){}

gca::GCA_quadvector::GCA_quadvector(const gca::GCA_quadvector& other):
    value(other.value){}

gca::GCA_quadvector::GCA_quadvector(const double value):
    value(value){}

gca::GCA_quadvector& gca::GCA_quadvector::operator=(const gca::GCA_quadvector& Other){
    this->value = Other.value;
}

gca::GCA_quadvector& gca::GCA_quadvector::operator<<(const double& in){
    this->value = in;
}

gca::GCA_antiscalar gca::GCA_quadvector::operator~(){
    gca::GCA_antiscalar result;
    result = this->value;
    return result;
}

std::ostream& gca::operator<<(std::ostream& os, gca::GCA_quadvector& quadvector){
  os << "[ " << quadvector.getValue() << " e1234 ]";
  return os;
}
