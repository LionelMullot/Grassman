#pragma once
#include <vector>
#include <ostream>


namespace gca{

class GCA_antitrivector;
class GCA_bivector;

class GCA_vector{
public:
    GCA_vector();
    GCA_vector(const GCA_vector& other);
    GCA_vector(double x, double y, double z, double w);

    double& operator[](const int& i);
    GCA_vector& operator=(const GCA_vector& Other);
    GCA_vector& operator^(const GCA_vector& Other);

    std::vector<double>& getValues();
    GCA_antitrivector& operator~();


private:
    std::vector<double> values;
};

std::ostream& operator<<(std::ostream& Stream, gca::GCA_vector& in);

}
