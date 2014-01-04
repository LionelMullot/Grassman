#include "grassmannCayley.hpp"

gca::GCA_antiscalar::GCA_antiscalar():
    value(1){}

gca::GCA_antiscalar::GCA_antiscalar(const gca::GCA_antiscalar& other):
    value(other.value){}

gca::GCA_antiscalar::GCA_antiscalar(const double value):
    value(value){}

gca::GCA_antiscalar& gca::GCA_antiscalar::operator=(const gca::GCA_antiscalar& Other){
    this->value = Other.getValue();
}

gca::GCA_scalar gca::GCA_antiscalar::operator^(const gca::GCA_antiquadvector& Other){
    GCA_scalar result;
    result.getValue() = this[0].getValue() * Other.getValue();
    return result;
}

gca::GCA_vector gca::GCA_antiscalar::operator^(const gca::GCA_antitrivector& Other){
    gca::GCA_vector result =  Other^this[0];
    for(unsigned int i = 0; i < result.size(); ++i){
        result[i] = -result[i];
    }
    return result;
}

gca::GCA_bivector gca::GCA_antiscalar::operator^(const gca::GCA_antibivector& Other){
    gca::GCA_bivector result = Other^this[0];
    for(unsigned int i = 0; i < result.size(); ++i){
        result[i] = -result[i];
    }
    return result;
}

gca::GCA_trivector gca::GCA_antiscalar::operator^(const gca::GCA_antivector& Other){
    gca::GCA_trivector result = Other^this[0];
    for(unsigned int i = 0; i < result.size(); ++i){
        result[i] = -result[i];
    }
    return result;
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
