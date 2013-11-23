#include "GCA_vector.hpp"

gca::GCA_vector::GCA_vector():
    value(1){}

gca::GCA_vector::GCA_vector(const gca::GCA_vector& other):
    value(other.value){}

gca::GCA_vector::GCA_vector(const double value):
    value(value){}

gca::GCA_vector& gca::GCA_vector::operator=(const gca::GCA_vector& Other){}
gca::GCA_vector& gca::GCA_vector::operator^(const gca::GCA_vector& Other){}
gca::GCA_antitrivector& gca::GCA_vector::operator~(){}

