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
    for(unsigned int i = 2; i > 0; --i){
        for(unsigned int j = 3; j > i; --j){
            for(unsigned int k = 4; k > j; --k){
              composantes.push_back(i*100 + j*10 + k);
          }
        }
    }
}

gca::GCA_antivector& gca::GCA_antivector::operator=(const gca::GCA_antivector& Other){
    this->Eigen::Vector4d::operator=(Other);
}

gca::GCA_antivector gca::GCA_antivector::operator^(const gca::GCA_scalar& Other) const{
    gca::GCA_antivector result;
    result = Other^this[0];
    for(unsigned int i = 0; i < result.size(); ++i){
        result[i] = -result[i]; // a^b = -b^a
    }
    return result;
}

gca::GCA_quadvector gca::GCA_antivector::operator^(const gca::GCA_vector& Other) const{
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

gca::GCA_trivector gca::GCA_antivector::operator^(const gca::GCA_antiscalar& Other) const{
  GCA_trivector result;
  for(unsigned int i = 0; i < this[0].size(); ++i){
    result[i] = this[0][i] * Other.getValue();
  }
  return result;
}

gca::GCA_bivector gca::GCA_antivector::operator^(const gca::GCA_antivector& Other) const{
  gca::GCA_bivector result;
  unsigned int cpt = 0;
  for(unsigned int i = 0; i < Other.size() - 1; ++i){
      for(unsigned int j = i + 1; j < Other.size(); ++j){
          result[cpt++] = (this[0][i]*Other[j] - this[0][j]*Other[i]);
      }
  }
  return result;
}

gca::GCA_vector gca::GCA_antivector::operator^(const gca::GCA_antibivector& Other) const{
    gca::GCA_vector result;
    result[0] = Other[0]*this[0][2] - Other[1]*this[0][1] + Other[3]*this[0][0];
    result[1] = Other[0]*this[0][3] - Other[2]*this[0][1] + Other[4]*this[0][0];
    result[2] = Other[1]*this[0][3] - Other[2]*this[0][2] + Other[5]*this[0][0];
    result[3] = Other[3]*this[0][3] - Other[4]*this[0][2] + Other[5]*this[0][1];

    return result;
}

gca::GCA_scalar gca::GCA_antivector::operator^(const gca::GCA_antitrivector& Other) const{
    gca::GCA_scalar result;
    unsigned int size = Other.size()-1;
    for(unsigned int i = 0; i <= size; ++i){
        if(i%2 == 0){
          result.getValue() += Other[i] * this[0][size-i];
        }
        else{
            result.getValue() -= Other[i] * this[0][size-i];
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
