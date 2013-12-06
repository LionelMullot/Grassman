#include "GCA_antiscalar.hpp"
#include "GCA_quadvector.hpp"
#include <iostream>

gca::GCA_antiscalar::GCA_antiscalar():
    value(1){}

gca::GCA_antiscalar::GCA_antiscalar(const gca::GCA_antiscalar& other):
    value(other.value){}

gca::GCA_antiscalar::GCA_antiscalar(const double value):
    value(value){}

gca::GCA_antiscalar& gca::GCA_antiscalar::operator=(const gca::GCA_antiscalar& Other){
    this->value = Other.value;
}

gca::GCA_antiscalar& gca::GCA_antiscalar::operator^(const gca::GCA_antiscalar& Other){
    this->value *= Other.value;
}

gca::GCA_vector gca::GCA_antiscalar::operator^(gca::GCA_vector vector){
    for(unsigned int i = 0; i < vector.size(); ++i){
        vector[i] *= this->value;
    }
    return vector;
}

gca::GCA_antiscalar& gca::GCA_antiscalar::operator<<(const double& in){
    this->value = in;
}

gca::GCA_quadvector gca::GCA_antiscalar::operator~() const{
    gca::GCA_quadvector result = this->value;
    return result;
}

namespace gca{
  
std::ostream& operator<<(std::ostream& os, gca::GCA_antiscalar& antiscalar){
  os << antiscalar.getValue();
  return os;
}

}