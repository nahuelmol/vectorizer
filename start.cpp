#include <iostream>
#include <tchar.h>

#include <iterator>
#include <algorithm>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

#include "cimg/CImg.h"
using namespace cimg_library;

using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::EigenSolver;

MatrixXd *MatrixInput(){
	int I, J;
	int i = 0, j = 0;

	float value;
	
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "\nTell me the size";
	cout << "\nThe rows: ";
	cin >> I;

	cout << "\nNow, the columns: ";
	cin >> J;

	static MatrixXd b(I,J);
	MatrixXd *pointer = &b;

	while(i<I){

		while(j<J){
			cout << "\nEnters the value in the place: (" << i << ", " << j << ")";
			cin >> value;
			b(i,j) = value;

			j++;
		}

		i++;
		j = 0;

	}

	cout << "b =" << endl << *pointer << endl;	

	cout << "&b: " << pointer;
	
	return pointer;
}

void diagonal_matrix_calculator(){

	using std::cout;
	using std::endl;

	int i = 0;
	int N = 0;

	EigenSolver<MatrixXd> es;

	MatrixXd *dir = MatrixInput();
	MatrixXd m = *dir;

	N = m.cols();

	cout << "\ndireccion: "<< dir;
	cout << "\ncontent: "<< *dir;

	es.compute(*dir,/* computeEigenvectors = */ false);
	cout << "The eigenvalues of A are: " << es.eigenvalues().transpose() << endl;
	cout << "The eigenvectors of A are: " << es.eigenvectors() << endl;
	//while(i<N){
	//	cout << "The eigenvector " << i << " is: " << endl << es.eigenvectors().col(i) << endl;
	//	i++;
	//}

}

void inverse_matrix_calculator(){

	using std::cout;

	MatrixXd *dir = MatrixInput();

	cout << "\ndireccion: "<< dir;
	cout << "\ncontent: "<< *dir;

}

void transpuesta_matrix_calculator(){

	using std::cout;

	MatrixXd *dir = MatrixInput();

	cout << "\ndireccion: "<< dir;
	cout << "\ncontent: "<< *dir;

}

void myinterface(){

	using std::find;
	using std::cout;
	using std::cin;

	int options[] = {1,2,3};
	bool exists;

	do{
		int opc;
		cout << "\nPlease choose an option\n";
		cout <<	"1.Encontrar matriz diagonal\n";
		cout << "2.Encontrar inversa\n";
		cout << "3.Encontrar transpuesta\n";

		cin >> opc;

		switch(opc){
			case 1:
				cout << "trying to find a diagonal matrix";
				diagonal_matrix_calculator();
			break;
			case 2:
				cout << "trying to find the reverse matrix";
			break;
			case 3:
				cout << "trying to find the transpose matrix";
			break;

			default:
				cout << "There's not an option choosed";
		}

		exists = find(std::begin(options), std::end(options), opc);

	}while(exists);
	


}

int main(){

	MatrixXd M = MatrixXd::Random(3,3);
	VectorXd v(3);
  	v << 1, 0, 0;

  	std::cout << "M =" << std::endl << M << std::endl;
  	std::cout << "v =" << std::endl << v << std::endl;
  	std::cout << "M * v =" << std::endl << M * v << std::endl;

  	MatrixXd m(2,2);
  	m(0,0) = 3;
  	m(1,0) = 2.5;
  	m(0,1) = -1;
  	m(1,1) = m(1,0) + m(0,1);
  	//std::cout << m << std::endl;

  	myinterface();

  	return 0;
}