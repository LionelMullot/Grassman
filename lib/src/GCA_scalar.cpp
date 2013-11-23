#include "GCA_scalar.hpp"

gca::GCA_scalar::GCA_scalar():
	value(1){}

gca::GCA_scalar::GCA_scalar(const gca::GCA_scalar& other):
	value(other.value){}

gca::GCA_scalar::GCA_scalar(const double value):
	value(value){}

double gca::GCA_scalar::getValue(){
    return value;
}

gca::GCA_scalar& gca::GCA_scalar::operator=(const gca::GCA_scalar& Other){
    this->value = Other.value;
}
gca::GCA_scalar& gca::GCA_scalar::operator^(const gca::GCA_scalar& Other){}
gca::GCA_antiquadvector& gca::GCA_scalar::operator~(){}

std::ostream& gca::operator<<(std::ostream& os, gca::GCA_scalar& scalar){
  os << scalar.getValue();
  return os;
}
