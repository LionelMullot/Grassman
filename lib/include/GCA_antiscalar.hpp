#pragma once

namespace gca{

class GCA_antiscalar{
public:
    //Constructeur
    GCA_antiscalar();
    GCA_antiscalar(const GCA_antiscalar& other);
    GCA_antiscalar(const double value);

    //Opérateur
    GCA_antiscalar& operator=(const GCA_antiscalar& Other);

    GCA_antiscalar operator^(const GCA_scalar& Other);

    //Anti Wedge
    GCA_scalar operator^(const GCA_antiquadvector& Other);
    GCA_vector operator^(const GCA_antitrivector& Other);
    GCA_bivector operator^(const GCA_antibivector& Other);
    GCA_trivector operator^(const GCA_antivector& Other);

    GCA_antiscalar& operator<<(const double& in);

    GCA_quadvector operator~() const;

    //Affichage
    friend std::ostream& operator<<(std::ostream& os, GCA_antiscalar& scalar);

    double& getValue(){ return value; }
    const double& getValue() const{ return value; }
    const double& e1234() const{ return value; }
    double& e1234() { return value; }

private:
    double value;
};

}

