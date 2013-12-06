#include "grassmannCayley.hpp"
#include <iostream>

gca::GCA_scalar::GCA_scalar():
	value(0){}

gca::GCA_scalar::GCA_scalar(const gca::GCA_scalar& other):
	value(other.value){}

gca::GCA_scalar::GCA_scalar(const double value):
	value(value){}

gca::GCA_scalar& gca::GCA_scalar::operator=(const gca::GCA_scalar& Other){
    this->value = Other.value;
}

gca::GCA_scalar gca::GCA_scalar::operator^(const gca::GCA_scalar& Other){
    return this->value * Other.value;
}

gca::GCA_scalar gca::GCA_scalar::operator^(const gca::GCA_antiscalar& Other){
    return this->value * Other.getValue();
}

gca::GCA_vector gca::GCA_scalar::operator^(gca::GCA_vector vector) const{ 
    for(unsigned int i = 0; i < vector.size(); ++i){
    	vector[i] *= this->value;
    }
    return vector;
}

gca::GCA_bivector gca::GCA_scalar::operator^(gca::GCA_bivector bivector) const{
    for(unsigned int i = 0; i < bivector.size(); ++i){
        bivector[i] *= this->value;
    }
    return bivector;
}

gca::GCA_trivector gca::GCA_scalar::operator^(gca::GCA_trivector trivector) const{
    for(unsigned int i = 0; i < trivector.size(); ++i){
        trivector[i] *= this->value;
    }
    return trivector;
}

gca::GCA_quadvector gca::GCA_scalar::operator^(gca::GCA_quadvector quadvector) const{
    quadvector.getValue() *= this->value;
    return quadvector;
}

gca::GCA_antiquadvector gca::GCA_scalar::operator^(gca::GCA_antiquadvector antiquadvector) const{
    antiquadvector.getValue() *= this->value;
    return antiquadvector;
}

gca::GCA_antitrivector gca::GCA_scalar::operator^(gca::GCA_antitrivector antitrivector) const{
    for(unsigned int i = 0; i < antitrivector.size(); ++i){
        antitrivector[i] *= this->value;
    }
    return antitrivector;
}

gca::GCA_antibivector gca::GCA_scalar::operator^(gca::GCA_antibivector antibivector) const{
    for(unsigned int i = 0; i < antibivector.size(); ++i){
        antibivector[i] *= this->value;
    }
    return antibivector;
}

gca::GCA_antivector gca::GCA_scalar::operator^(gca::GCA_antivector antivector) const{
    for(unsigned int i = 0; i < antivector.size(); ++i){
        antivector[i] *= this->value;
    }
    return antivector;
}

gca::GCA_scalar& gca::GCA_scalar::operator<<(const double& in){
    this->value = in;
}

gca::GCA_antiquadvector gca::GCA_scalar::operator~() const{
    gca::GCA_antiquadvector result;
    result << this[0].value;
    return result;
}

namespace gca{

std::ostream& operator<<(std::ostream& os, const gca::GCA_scalar& scalar){
  os << scalar.getValue();
  return os;
}

}