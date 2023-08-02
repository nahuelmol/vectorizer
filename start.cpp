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
	//cout << "The eigenvectors of A are: " << es.eigenvectors() << endl;
	//while(i<N){
	//	cout << "The eigenvector " << i << " is: " << endl << es.eigenvectors().col(i) << endl;
	//	i++;
	//}

}

void inverse_matrix_calculator(){

	using std::cout;
	using std::endl;
	
	MatrixXd *dir = MatrixInput();
	MatrixXd original = *dir;
	MatrixXd matriz_inversa = original.inverse();

	cout << "\nOriginal: "<< endl << *dir << endl;
	cout << "\nTranspuesta: " << endl << matriz_inversa << endl;
}

void transpuesta_matrix_calculator(){

	using std::cout;
	using std::endl;

	MatrixXd *dir = MatrixInput();
	MatrixXd original = *dir;
	MatrixXd matriz_transpuesta = original.transpose();

	cout << "\nOriginal: "<< endl << *dir << endl;
	cout << "\nTranspuesta: " << endl << matriz_transpuesta << endl;

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
		cout << "4.Stop it!\n";

		cin >> opc;

		switch(opc){
			case 1:
				cout << "trying to find a diagonal matrix";
				diagonal_matrix_calculator();
			break;
			case 2:
				cout << "trying to find the reverse matrix";
				inverse_matrix_calculator();
			break;
			case 3:
				cout << "trying to find the transpose matrix";
				transpuesta_matrix_calculator();
			break;

			default:
				cout << "There's not an option choosed";
		}

		exists = find(std::begin(options), std::end(options), opc);

	}while(exists);
	


}

int main(){

  	myinterface();

  	return 0;
}