#include "grassmannCayley.hpp"
#include <iostream>

gca::GCA_bivector::GCA_bivector():
    Eigen::VectorXd(Eigen::VectorXd::Zero(6)) {
        setComposantes();
    }

gca::GCA_bivector::GCA_bivector(const gca::GCA_bivector& other):
    Eigen::VectorXd(other), composantes(other.composantes) {}

void gca::GCA_bivector::setComposantes(){
    for(uint i = 1; i < 4; ++i){
        for(uint j = i+1; j <= 4; ++j){
            composantes.push_back(i*10 + j);
        }
    }
}

gca::GCA_bivector& gca::GCA_bivector::operator=(const gca::GCA_bivector& Other){
    this->Eigen::VectorXd::operator=(Other);
}

gca::GCA_bivector gca::GCA_bivector::operator^(const gca::GCA_scalar& value){
    return value^this[0];
}

gca::GCA_trivector gca::GCA_bivector::operator^(const gca::GCA_vector& Other) const{
    gca::GCA_trivector result;
    result[0] = this[0][0]*Other[2] - this[0][1]*Other[1] + this[0][3]*Other[0];
    result[1] = this[0][0]*Other[3] - this[0][2]*Other[1] + this[0][4]*Other[0];
    result[2] = this[0][1]*Other[3] - this[0][2]*Other[2] + this[0][5]*Other[0];
    result[3] = this[0][3]*Other[3] - this[0][4]*Other[2] + this[0][5]*Other[1];
    return result;
}

gca::GCA_quadvector gca::GCA_bivector::operator^(const gca::GCA_bivector& Other) const{
    gca::GCA_quadvector result;
    uint size = Other.size()-1;
    for(uint i = 0; i <= size; ++i){
        if(i == 1 || i == 4)
            result.getValue() -= (this[0][i]*this[0][size - i]);
        else
            result.getValue() += (this[0][i]*this[0][size - i]);
    }
    return result;
}

gca::GCA_antibivector gca::GCA_bivector::operator~() const{
    gca::GCA_antibivector result;
    result << this[0][5], -this[0][4], this[0][3], this[0][2], -this[0][1], this[0][0];
    return result;
}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_bivector& in){
        Stream << "[";
            for(uint i = 0; i < in.composantes.size(); ++i)
                Stream << in(i) <<" e" << in.composantes[i] << " ; ";
        Stream << " ]";
        return Stream;
    }

}
