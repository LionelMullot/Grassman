#include "grassmannCayley.hpp"
#include <iostream>

gca::GCA_antibivector::GCA_antibivector():
    Eigen::VectorXd(Eigen::VectorXd::Zero(6)) {
        setComposantes();
    }

gca::GCA_antibivector::GCA_antibivector(const gca::GCA_antibivector& other):
    Eigen::VectorXd(other), composantes(other.composantes) {}

void gca::GCA_antibivector::setComposantes(){
    for(unsigned int i = 3; i > 0; --i){
        for(unsigned int j = 4; j > i; --j){
            composantes.push_back(i*10 + j);
        }
    }
}

gca::GCA_antibivector& gca::GCA_antibivector::operator=(const gca::GCA_antibivector& Other){
    this->Eigen::VectorXd::operator=(Other);
}

//Wedge
gca::GCA_trivector gca::GCA_antibivector::operator^(const gca::GCA_vector& Other) const{
    gca::GCA_trivector result;
    result[0] = this[0][0]*Other[2] - this[0][1]*Other[1] + this[0][3]*Other[0];
    result[1] = this[0][0]*Other[3] - this[0][2]*Other[1] + this[0][4]*Other[0];
    result[2] = this[0][1]*Other[3] - this[0][2]*Other[2] + this[0][5]*Other[0];
    result[3] = this[0][3]*Other[3] - this[0][4]*Other[2] + this[0][5]*Other[1];
    return result;
}

gca::GCA_bivector gca::GCA_antibivector::operator~() const{
    gca::GCA_bivector result;
    result << this[0][5], -this[0][4], this[0][3], this[0][2], -this[0][1], this[0][0];
    return result;
}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_antibivector& in){
        Stream << "[";
            for(unsigned int i = 0; i < in.composantes.size(); ++i)
                Stream << in(i) <<" e" << in.composantes[i] << " ; ";
        Stream << " ]";
        return Stream;
    }

}
