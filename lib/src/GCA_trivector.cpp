#include "GCA_trivector.hpp"

gca::GCA_trivector::GCA_trivector():
    Eigen::Vector4d(Eigen::Vector4d::Zero()) {
    	setComposantes();
    }

gca::GCA_trivector::GCA_trivector(double x, double y, double z, double w):
    Eigen::Vector4d(x, y, z, w) {
        setComposantes();
    }

gca::GCA_trivector::GCA_trivector(const gca::GCA_trivector& other):
    Eigen::Vector4d(other), composantes(other.composantes) {}

void gca::GCA_trivector::setComposantes(){
    for(uint i = 1; i < 3; ++i){
        for(uint j = i+1; j < 4; ++j){
        	for(uint k = j+1; k < 5; ++k){
            	composantes.push_back(i*100 + j*10 + k);
        	}
        }
    }
}

gca::GCA_trivector& gca::GCA_trivector::operator=(const gca::GCA_trivector& Other){
    this->Eigen::Vector4d::operator=(Other);
}

gca::GCA_antivector& gca::GCA_trivector::operator~() {}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_trivector& in){
       Stream << "[";
            for(uint i = 0; i < in.composantes.size(); ++i)
                Stream << " " << in(i) <<" e" << in.composantes[i] << " ;";
        Stream << " ]";
        return Stream;
    }

}
