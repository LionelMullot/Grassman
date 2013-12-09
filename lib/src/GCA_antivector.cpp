#include "grassmannCayley.hpp"

gca::GCA_antivector::GCA_antivector():
    Eigen::Vector4d(Eigen::Vector4d::Zero()) {
        setComposantes();
    }

gca::GCA_antivector::GCA_antivector(double x, double y, double z, double w):
    Eigen::Vector4d(x, y, z, w) {
        setComposantes();
    }

gca::GCA_antivector::GCA_antivector(const gca::GCA_antivector& other):
    Eigen::Vector4d(other), composantes(other.composantes) {}

void gca::GCA_antivector::setComposantes(){
    for(unsigned int i = 1; i < 5; ++i){
         composantes.push_back(i);
    }
}

gca::GCA_antivector& gca::GCA_antivector::operator=(const gca::GCA_antivector& Other){
    this->Eigen::Vector4d::operator=(Other);
}

gca::GCA_quadvector gca::GCA_antivector::operator^(const gca::GCA_vector Other) const{
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

gca::GCA_trivector& gca::GCA_antivector::operator~() const{}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_antivector& in){
        Stream << "[";
            for(unsigned int i = 0; i < in.composantes.size(); ++i)
                Stream << in(i) <<" e" << in.composantes[i] << " ; ";
        Stream << " ]";
        return Stream;
    }

}
