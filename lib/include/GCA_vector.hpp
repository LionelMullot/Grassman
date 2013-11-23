#pragma once
#include <vector>

namespace gca{

class GCA_antitrivector;

class GCA_vector{
public:
    GCA_vector();
    GCA_vector(const GCA_vector& other);
    GCA_vector(double x, double y);
    GCA_vector(double x, double y, double z);
    GCA_vector(double x, double y, double z, double w);

    GCA_vector& operator=(const GCA_vector& Other);
    GCA_vector& operator^(const GCA_vector& Other);
    GCA_antitrivector& operator~();


private:
    std::vector<double> values;
};

}
