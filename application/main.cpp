#include <iostream>
#include <Eigen/Dense>
#include <Eigen/QR>

int main(){

	Eigen::MatrixXd a = Eigen::MatrixXd::Zero(4,4);

	std::cout << a.transpose() << std::endl;
	
	return 0;
}

// g++ -I ~/eigen main.cpp -o exe