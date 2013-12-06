#include "GCA_antibivector.hpp"
#include <iostream>

gca::GCA_antibivector::GCA_antibivector():
    Eigen::VectorXd(Eigen::VectorXd::Zero(6)) {
        setComposantes();
    }

gca::GCA_antibivector::GCA_antibivector(const gca::GCA_antibivector& other):
    Eigen::VectorXd(other), composantes(other.composantes) {}

void gca::GCA_antibivector::setComposantes(){
    for(uint i = 3; i > 0; --i){
        for(uint j = 4; j > i; --j){
            composantes.push_back(i*10 + j);
        }
    }
}

gca::GCA_antibivector& gca::GCA_antibivector::operator=(const gca::GCA_antibivector& Other){
    this->Eigen::VectorXd::operator=(Other);
}

gca::GCA_bivector gca::GCA_antibivector::operator~() const{
    gca::GCA_bivector result;
    result << this[0][5], -this[0][4], this[0][3], this[0][2], -this[0][1], this[0][0];
    return result;
}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_antibivector& in){
        Stream << "[";
            for(uint i = 0; i < in.composantes.size(); ++i)
                Stream << in(i) <<" e" << in.composantes[i] << " ; ";
        Stream << " ]";
        return Stream;
    }

}
