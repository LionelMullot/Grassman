#pragma once 

namespace gca{

class GCA_antiquadvector;

class GCA_scalar{
public:
	GCA_scalar();
	GCA_scalar(const GCA_scalar& other);
	GCA_scalar(const double value);

	GCA_scalar& operator=(const GCA_scalar& Other);
	GCA_scalar& operator^(const GCA_scalar& Other);
	GCA_antiquadvector& operator~();


private:
	double value;
};

}
