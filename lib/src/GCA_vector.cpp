#include "GCA_vector.hpp"

gca::GCA_vector::GCA_vector(){
    values.push_back(1);
}
gca::GCA_vector::GCA_vector(double x, double y){
    values.push_back(x);
    values.push_back(y);
}
gca::GCA_vector::GCA_vector(double x, double y, double z){
    values.push_back(x);
    values.push_back(y);
    values.push_back(z);
}
gca::GCA_vector::GCA_vector(double x, double y, double z, double w){
    values.push_back(x);
    values.push_back(y);
    values.push_back(z);
    values.push_back(w);
}

gca::GCA_vector::GCA_vector(const gca::GCA_vector& other){}

gca::GCA_vector& gca::GCA_vector::operator=(const gca::GCA_vector& Other){}
gca::GCA_vector& gca::GCA_vector::operator^(const gca::GCA_vector& Other){}
gca::GCA_antitrivector& gca::GCA_vector::operator~(){}
