#pragma once
#include <iostream>

namespace gca{

class GCA_antiquadvector;

class GCA_scalar{
public:
	GCA_scalar();
	GCA_scalar(const GCA_scalar& other);
	GCA_scalar(const double value);

    double getValue();

	GCA_scalar& operator=(const GCA_scalar& Other);
	GCA_scalar& operator^(const GCA_scalar& Other);
	GCA_antiquadvector& operator~();


private:
    double value;
};

std::ostream& operator<<(std::ostream& os, GCA_scalar& scalar);
}

