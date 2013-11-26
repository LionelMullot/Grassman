#pragma once

#include <Eigen/Dense>
#include <Eigen/QR>

namespace gca{

class GCA_bivector;
class GCA_antitrivector;

class GCA_vector : public Eigen::Vector4d{
public:
    GCA_vector();
    GCA_vector(const GCA_vector& other);
    GCA_vector(double x, double y, double z, double w);

    GCA_vector& operator=(const GCA_vector& Other);
    GCA_bivector operator^(const GCA_vector& Other);

    GCA_antitrivector& operator~();

    friend std::ostream& operator<<(std::ostream& Stream, const GCA_vector& in);
};



}
