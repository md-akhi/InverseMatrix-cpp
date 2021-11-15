#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class InverseMatrix {
	float
		transposeMatrix[30][30];
 public:
	float determinte,
		cinMatrix[30][30],
		coutMatrix[30][30];
	int sizeMatrix;

	//---------------------------------------------------
	//	calculate inverse of matrix
	void Inverse(){
		if(determinte == 0){
			cout<<"\n Inverse of entered matrix is not possible \n";
		}
		else if(sizeMatrix == 1){
			coutMatrix[0][0] = 1;
		}
		else {
			Cofactor();	// function
		}
		//return;
	}// end function

	//---------------------------------------------------
	//	calculate cofactor of matrix
	void Cofactor(){
		float minorMatrix[30][30],
			cofactorMatrix[30][30];
		int col3, row3, row2, col2, row, col;
		for (row3=0; row3 < sizeMatrix; row3++){
			for (col3=0; col3 < sizeMatrix; col3++){
				row2 =0;
				col2 = 0;
				for (row=0; row < sizeMatrix; row++){
					for (col=0; col < sizeMatrix; col++){
						if (row != row3 && col != col3){
							minorMatrix[row2][col2] = cinMatrix[row][col];
							if (col2 < (sizeMatrix - 2)){
								col2++;
							}
							else {
								col2 = 0;
								row2++;
							}
						}
					}
				}
				cofactorMatrix[row3][col3] = pow(-1, (row3 + col3)) * Determinte(minorMatrix, (sizeMatrix - 1));
			}
		}
		Transpose(cofactorMatrix);	// function
		//return;
	}// end function

	//---------------------------------------------------
	//	calculate transpose of matrix
	void Transpose(float cofactorMatrix[30][30]){
		int row, col;
		for (row=0; row < sizeMatrix; row++){
			for (col=0; col < sizeMatrix; col++){
				transposeMatrix[row][col] = cofactorMatrix[col][row];
				coutMatrix[row][col] = cofactorMatrix[col][row] / determinte; // adjoint method
			}
		}
		//return;
	}// end function

	//---------------------------------------------------
	//	calculate determinte of matrix
	float Determinte(float minorMatrix[30][30], int size){
		int col;
		float sum = 0,
			newMinorMatrix[30][30];
		if (size == 1){
			return minorMatrix[0][0];
		}
		else if(size == 2){
			return (minorMatrix[0][0] * minorMatrix[1][1] - minorMatrix[0][1] * minorMatrix[1][0]);
		}
		else {
			for(col=0; col < size; col++){
				Minor(minorMatrix, col, newMinorMatrix);	// function
				sum += (float) (minorMatrix[0][col] * pow(-1, col) * Determinte(newMinorMatrix, (size - 1)));	// function
			}
		}
		return (float) sum;
	}// end function

	//---------------------------------------------------
	//	calculate minor of matrix OR build new matrix : k-had = minor
	void Minor(float minorMatrix[30][30], int colMatrix,  float newMinorMatrix[30][30]){
		int col, row,
			row2 = 0,
			col2 = 0;
		for(row=1; row < sizeMatrix; row++){
			for( col=0; col < sizeMatrix; col++){
				if(col == colMatrix){
					continue;
				}
				newMinorMatrix[row2][col2] = minorMatrix[row][col];
				col2++;
				if(col2 == (sizeMatrix - 1)){
					row2++;
					col2 = 0;
				}
			}
		}
		//return;
	}// end function

	//----------------------------------------------------------
	//read matrix : cin>> in c++ , scanf() in c
	void Scanf(char **argv, int argc){
		int row, col;
		if (argc == 1){
			cout<<" Enter the size of matrix N*N: ";
			cin>>sizeMatrix;
			cout<<"\n ------------------------------ \n";
			cout<<" Enter the elements of matrix: \n";
			for (row = 0; row < sizeMatrix; row++){
				for (col = 0; col < sizeMatrix; col++){
					cout<<" M["<<(row+1)<<"]["<<(col+1)<<"]: ";
					cin>>cinMatrix[row][col];
				}
				cout<<" \n ";
			}
		} else {
			ifstream inputFile;
			inputFile.open(argv[1]);
			if (inputFile.is_open()){
				inputFile>>sizeMatrix;
				for (row = 0; row < sizeMatrix; row++){
					for (col = 0; col < sizeMatrix; col++){
						inputFile>>cinMatrix[row][col];
					}
				}
				inputFile.close();
			}
		}
		cout<<("\n ------------------------------ \n");
		//return;
	}

	//-----------------------------------------------------
	// show matrix : cout<< in c++ , printf() in c
	void Printf(int show){
		int row, col;
		if(show == 1){ // print matrix
			for(row=0; row < sizeMatrix; row++){
				for(col=0; col < sizeMatrix; col++){
					cout<<" "<<cinMatrix[row][col]<<" \t";
				}
				cout<<" \n ";
			}
		}
		else if(show == 2){ // print inverse
			cout<<"\n The inverse Of matrix is: \n";
			for (row=0; row <sizeMatrix; row++){
				for (col=0; col < sizeMatrix; col++){
					cout<<" M["<<(row+1)<<"]["<<(col+1)<<"]: "<<transposeMatrix[row][col]<<"/"<<determinte<<" ("<<coutMatrix[row][col]<<") \t ";
				}
				cout<<" \n ";
			}
		}
		//return;
	}

}app;

//---------------------------------------------------
//main fuction
int main(int argc, char **argv){
	int printMatrix = 1,
		printInverse = 2;
	cout<<"\n C Program to find inverse Of matrix \n";
	app.Scanf(argv, argc);	// function
	app.Printf(printMatrix);	// function
	app.determinte = app.Determinte(app.cinMatrix, app.sizeMatrix);	// function
	cout<<"\n ------------------------------ \n";
	cout<<"\n Determinant of the matrix : "<<app.determinte;
	cout<<"\n ------------------------------ \n";
	app.Inverse();	// function
	app.Printf(printInverse);	// function
	cout<<"\n =======* THE END *=======\n";
	cout<<"\n *** Thanks for using the program! *** \n";
  return 0;
}// end main
