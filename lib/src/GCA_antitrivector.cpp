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
    for(uint i = 1; i < 3; ++i){
    	for(uint j = i+1; j < 4; ++j)
    		for(uint k = j+1; k < 4; ++k)
         		composantes.push_back(i*100 + j*10 + k);
    }
}

gca::GCA_antitrivector& gca::GCA_antitrivector::operator=(const gca::GCA_antitrivector& Other){
    this->Eigen::Vector4d::operator=(Other);
}

gca::GCA_vector& gca::GCA_antitrivector::operator~() const{}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_antitrivector& in){
        Stream << "[";
            for(uint i = 0; i < in.composantes.size(); ++i)
                Stream << in(i) <<" e" << in.composantes[i] << " ; ";
        Stream << " ]";
        return Stream;
    }

}
