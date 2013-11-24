#include "GCA_vector.hpp"
#include <iostream>

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

gca::GCA_vector::GCA_vector(const gca::GCA_vector& other){
    for(unsigned int i = 0; i < other.values.size(); ++i){
        values.push_back(other.values[i]);
    }
}

std::vector<double>& gca::GCA_vector::getValues(){
    return values;
}

gca::GCA_vector& gca::GCA_vector::operator=(const gca::GCA_vector& Other){
    for(unsigned int i = 0; i < Other.values.size(); ++i){
        values.push_back(Other.values[i]);
    }
}

gca::GCA_vector& gca::GCA_vector::operator^(const gca::GCA_vector& Other){}

gca::GCA_antitrivector& gca::GCA_vector::operator~(){}

std::ostream& gca::operator<<(std::ostream& Stream, gca::GCA_vector& in){ 
    for(unsigned int i = 0; i < in.getValues().size(); ++i)
        Stream << " " << (in.getValues())[i];
    return Stream;
} 
