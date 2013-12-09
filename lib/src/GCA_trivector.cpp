#include "grassmannCayley.hpp"

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
    for(unsigned int i = 1; i < 3; ++i){
        for(unsigned int j = i+1; j < 4; ++j){
            for(unsigned int k = j+1; k < 5; ++k){
            	composantes.push_back(i*100 + j*10 + k);
        	}
        }
    }
}

gca::GCA_trivector& gca::GCA_trivector::operator=(const gca::GCA_trivector& Other){
    this->Eigen::Vector4d::operator=(Other);
}

gca::GCA_trivector gca::GCA_trivector::operator^(const GCA_scalar value){
    return value^this[0];
}

gca::GCA_quadvector gca::GCA_trivector::operator^(const gca::GCA_vector Other) const{
    gca::GCA_quadvector result;
    unsigned int size = Other.size()-1;
    for(unsigned int i = 0; i <= size; ++i){
        if(i%2 == 0){
            result.getValue() += this[0][i] * Other[size-i];
        }
        else{
            result.getValue() -= this[0][i] * Other[size-i];
        }
    }
    return result;
}

gca::GCA_quadvector gca::GCA_trivector::operator^(const gca::GCA_antitrivector Other) const{
    gca::GCA_quadvector result;
    unsigned int size = Other.size()-1;
    for(unsigned int i = 0; i <= size; ++i){
        if(i%2 == 0){
            result.getValue() += this[0][i] * Other[size-i];
        }
        else{
            result.getValue() -= this[0][i] * Other[size-i];
        }
    }
    return result;
}

gca::GCA_antivector gca::GCA_trivector::operator~() const{
    gca::GCA_antivector result;
    result << -this[0][3], this[0][2], -this[0][1], this[0][0];
    return result;
}

gca::GCA_trivector gca::GCA_trivector::operator^(const GCA_antiquadvector value){
    gca::GCA_scalar result = ~value;
    return this[0]^result;
}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_trivector& in){
       Stream << "[";
            for(unsigned int i = 0; i < in.composantes.size(); ++i)
                Stream << " " << in(i) <<" e" << in.composantes[i] << " ;";
        Stream << " ]";
        return Stream;
    }

}
