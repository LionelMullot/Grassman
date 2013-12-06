#include "GCA_antivector.hpp"
#include "GCA_trivector.hpp"

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
    for(uint i = 1; i < 5; ++i){
         composantes.push_back(i);
    }
}

gca::GCA_antivector& gca::GCA_antivector::operator=(const gca::GCA_antivector& Other){
    this->Eigen::Vector4d::operator=(Other);
}

gca::GCA_trivector& gca::GCA_antivector::operator~() const{}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_antivector& in){
        Stream << "[";
            for(uint i = 0; i < in.composantes.size(); ++i)
                Stream << in(i) <<" e" << in.composantes[i] << " ; ";
        Stream << " ]";
        return Stream;
    }

}
