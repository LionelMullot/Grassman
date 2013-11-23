#pragma once

namespace gca{

class GCA_antitrivector;

class GCA_vector{
public:
    GCA_vector();
    GCA_vector(const GCA_vector& other);
    GCA_vector(const double value);

    GCA_vector& operator=(const GCA_vector& Other);
    GCA_vector& operator^(const GCA_vector& Other);
    GCA_antitrivector& operator~();


private:
    double value;
};

}
