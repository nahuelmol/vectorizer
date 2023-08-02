#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

int* example(){

	static int arr[] = {1,2,3};

	return arr;
}

int main(){

	using std::cout;

	int *dir;
	dir = example();

	cout << "\ndireccion: " << dir;
	cout << "\ncontent: " << *dir;
	cout << "\ncontent: " << *dir +1;
	return 0;
}