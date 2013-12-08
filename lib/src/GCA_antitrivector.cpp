#include "grassmannCayley.hpp"
#include <iostream>

gca::GCA_antitrivector::GCA_antitrivector():
    Eigen::Vector4d(Eigen::Vector4d::Zero()) {
        setComposantes();
    }

gca::GCA_antitrivector::GCA_antitrivector(double x, double y, double z, double w):
    Eigen::Vector4d(x, y, z, w) {
        setComposantes();
    }

gca::GCA_antitrivector::GCA_antitrivector(const gca::GCA_antitrivector& other):
    Eigen::Vector4d(other), composantes(other.composantes) {}

void gca::GCA_antitrivector::setComposantes(){
    for(unsigned int i = 1; i < 3; ++i){
        for(unsigned int j = i+1; j < 4; ++j){
            for(unsigned int k = j+1; k < 5; ++k){
         		composantes.push_back(i*100 + j*10 + k);
            }
        }
    }
}

gca::GCA_antitrivector& gca::GCA_antitrivector::operator=(const gca::GCA_antitrivector& Other){
    this->Eigen::Vector4d::operator=(Other);
}

gca::GCA_vector gca::GCA_antitrivector::operator~() const{
    gca::GCA_vector result;
    result << this[0][3], -this[0][2], this[0][1], -this[0][0];
    return result;
}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_antitrivector& in){
        Stream << "[ ";
            for(unsigned int i = 0; i < in.composantes.size(); ++i)
                Stream << in(i) <<" e" << in.composantes[i] << " ; ";
        Stream << "]";
        return Stream;
    }

}
