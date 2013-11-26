#include "GCA_trivector.hpp"

gca::GCA_trivector::GCA_trivector():
    Eigen::VectorXd(Eigen::VectorXd::Zero(4)) {}

gca::GCA_trivector::GCA_trivector(const gca::GCA_trivector& other):
    Eigen::VectorXd(other) {}

gca::GCA_trivector& gca::GCA_trivector::operator=(const gca::GCA_trivector& Other){
    this->Eigen::VectorXd::operator=(Other);
}

gca::GCA_antitrivector& gca::GCA_trivector::operator~() {}

namespace gca{

    std::ostream& operator<<(std::ostream& Stream, const gca::GCA_trivector& in){
        Stream << "[";
            Stream << in.transpose();
        Stream << " ]";
        return Stream;
    }

}
