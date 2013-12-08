#include "grassmannCayley.hpp"
#include <iostream>

gca::GCA_bivector::GCA_bivector():
    Eigen::VectorXd(Eigen::VectorXd::Zero(6)) {
        setComposantes();
    }

gca::GCA_bivector::GCA_bivector(const gca::GCA_bivector& other):
    Eigen::VectorXd(other), composantes(other.composantes) {}

void gca::GCA_bivector::setComposantes(){
    for(unsigned int i = 1; i < 4; ++i){
        for(unsigned int j = i+1; j <= 4; ++j){
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
    unsigned int size = Other.size()-1;

    for(unsigned int i = 0; i <= size; ++i){
        if(i == 1 || i == 4)
            result.getValue() -= (this[0][i]*Other[size - i]);
        else
            result.getValue() += (this[0][i]*Other[size - i]);
    }
    return result;
}
gca::GCA_quadvector gca::GCA_bivector::operator^(const gca::GCA_antibivector& Other) const{
    GCA_bivector result = ~Other;
    return this[0]^result;
}

gca::GCA_antibivector gca::GCA_bivector::operator~() const{
    gca::GCA_antibivector result;
    result << this[0][5], -this[0][4], this[0][3], this[0][2], -this[0][1], this[0][0];
    return result;
}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_bivector& in){
        Stream << "[ ";
            for(unsigned int i = 0; i < in.composantes.size(); ++i){
                if(i != in.composantes.size()-1){
                    Stream << in(i) <<" e" << in.composantes[i] << " ; ";
                }else{
                    Stream << in(i) <<" e" << in.composantes[i];
                }
            }
        Stream << " ]";
        return Stream;
    }

}
