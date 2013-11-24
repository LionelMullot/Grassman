#include "GCA_vector.hpp"

gca::GCA_vector::GCA_vector(){
    values.push_back(1);
    values.push_back(1);
    values.push_back(1);
    values.push_back(1);
}

gca::GCA_vector::GCA_vector(double x, double y, double z, double w){
    values.push_back(x);
    values.push_back(y);
    values.push_back(z);
    values.push_back(w);
}

gca::GCA_vector::GCA_vector(const gca::GCA_vector& other){
    values.push_back(other.values[0]);
    values.push_back(other.values[1]);
    values.push_back(other.values[2]);
    values.push_back(other.values[3]);
}

std::vector<double> gca::GCA_vector::getValues(){
    return values;
}

double& gca::GCA_vector::operator[](const int& i){
    return values[i];
}
gca::GCA_vector& gca::GCA_vector::operator=(const GCA_vector& Other){
    values[0] = Other.values[0];
    values[1] = Other.values[1];
    values[2] = Other.values[2];
    values[3] = Other.values[3];
}

gca::GCA_vector& gca::GCA_vector::operator^(const gca::GCA_vector& Other){}
gca::GCA_antitrivector& gca::GCA_vector::operator~(){}


std::ostream& gca::operator<<(std::ostream& os, GCA_vector& vector){
    os << "[" << vector.getValues()[0] << ", " << vector.getValues()[1] << ", " << vector.getValues()[2] << ", " << vector.getValues()[3] << "]";
    return os;
}
