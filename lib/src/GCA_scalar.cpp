#include "GCA_scalar.hpp"
#include "GCA_antiquadvector.hpp"
#include "GCA_quadvector.hpp"
#include <iostream>

gca::GCA_scalar::GCA_scalar():
	value(1){}

gca::GCA_scalar::GCA_scalar(const gca::GCA_scalar& other):
	value(other.value){}

gca::GCA_scalar::GCA_scalar(const double value):
	value(value){}

gca::GCA_scalar& gca::GCA_scalar::operator=(const gca::GCA_scalar& Other){
    this->value = Other.value;
}

gca::GCA_scalar& gca::GCA_scalar::operator^(const gca::GCA_scalar& Other){
    this->value *= Other.value;
}

gca::GCA_vector gca::GCA_scalar::operator^(gca::GCA_vector vector){ // Je passe une copie pour ne pas modifier le vecteur d'origine
    for(unsigned int i = 0; i < vector.size(); ++i){
    	vector[i] *= this->value;
    }
    return vector;
}

gca::GCA_bivector gca::GCA_scalar::operator^(gca::GCA_bivector bivector){
    for(unsigned int i = 0; i < bivector.size(); ++i){
        bivector[i] *= this->value;
    }
    return bivector;
}

gca::GCA_trivector gca::GCA_scalar::operator^(gca::GCA_trivector trivector){
    for(unsigned int i = 0; i < trivector.size(); ++i){
        trivector[i] *= this->value;
    }
    return trivector;
}

gca::GCA_quadvector gca::GCA_scalar::operator^(gca::GCA_quadvector quadvector){
    quadvector.getValue() *= this->value;
    return quadvector;
}

gca::GCA_scalar& gca::GCA_scalar::operator<<(const double& in){
    this->value = in;
}

gca::GCA_antiquadvector gca::GCA_scalar::operator~(){
    gca::GCA_antiquadvector result;
    result << this[0].value;
    return result;
}

namespace gca{

std::ostream& operator<<(std::ostream& os, gca::GCA_scalar& scalar){
  os << scalar.getValue();
  return os;
}

}