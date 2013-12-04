#include "GCA_vector.hpp"
#include "GCA_scalar.hpp"
#include <iostream>

gca::GCA_vector::GCA_vector():
    Eigen::Vector4d(Eigen::Vector4d::Zero()) {
        setComposantes();
    }

gca::GCA_vector::GCA_vector(double x, double y, double z, double w):
    Eigen::Vector4d(x, y, z, w) {
        setComposantes();
    }

gca::GCA_vector::GCA_vector(const gca::GCA_vector& other):
    Eigen::Vector4d(other), composantes(other.composantes) {}

void gca::GCA_vector::setComposantes(){
    for(uint i = 1; i <= 4; ++i){
         composantes.push_back(i);
    }
}

gca::GCA_vector& gca::GCA_vector::operator=(const gca::GCA_vector& Other){
    this->Eigen::Vector4d::operator=(Other);
}

gca::GCA_vector gca::GCA_vector::operator^(const gca::GCA_scalar& value){
    return value^this[0];
}

gca::GCA_bivector gca::GCA_vector::operator^(const gca::GCA_vector& Other) const{
    gca::GCA_bivector result;
    unsigned int cpt = 0;
    for(unsigned int i = 0; i < Other.size() - 1; ++i){
        for(unsigned int j = i + 1; j < Other.size(); ++j){
            result[cpt++] = (this[0][i]*Other[j] - this[0][j]*Other[i]);
        }
    }
    return result;
}

gca::GCA_trivector gca::GCA_vector::operator^(const gca::GCA_bivector& Other) const{
    gca::GCA_trivector result = Other^this[0];
    for(uint i = 0; i < result.size(); ++i){
        result[i] = -result[i];// a^b = -b^a
    }
    return result;
}

gca::GCA_quadvector gca::GCA_vector::operator^(const gca::GCA_trivector& Other) const{
    gca::GCA_quadvector result = Other^this[0];
    result.getValue() = -result.getValue(); // a^b = -b^a
    return result;
}

gca::GCA_antitrivector& gca::GCA_vector::operator~() {}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_vector& in){
        Stream << "[";
            for(uint i = 0; i < in.composantes.size(); ++i)
                Stream << " " << in(i) <<" e" << in.composantes[i] << " ;";
        Stream << " ]";
        return Stream;
    }

}
