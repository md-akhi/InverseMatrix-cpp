#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//----------------------------------------------------------
//read matrix : cin>> in c++ , scanf() in c
int Cin(float cinMatrix[30][30], char **argv, int argc){
	int row, col, sizeMatrix;
	if (argc == 1){
		printf(" Enter the size of matrix N*N: ");
		scanf("%d", &sizeMatrix);
		printf("\n ------------------------------ \n");
		printf(" Enter the elements of matrix: \n");
		for (row = 0; row < sizeMatrix; row++){
			for (col = 0; col < sizeMatrix; col++){
				printf(" M[%d][%d]: ", row+1, col+1);
				scanf("%f", &cinMatrix[row][col]);
			}
			printf(" \n ");
		}
	}
	else {
		FILE *fp = fopen(argv[1], "r");
		fscanf(fp, "%d", &sizeMatrix);
		for (row = 0; row < sizeMatrix; row++){
			for (col = 0; col < sizeMatrix; col++){
				fscanf(fp, "%f", &cinMatrix[row][col]);
			}
		}
		fclose(fp);
	}
	printf("\n ------------------------------ \n");
	return sizeMatrix;
}

//-----------------------------------------------------
// show matrix : cout<< in c++ , printf() in c
void Cout(float coutMatrix[30][30], int sizeMatrix, int show, float determinte, float transposeMatrix[30][30]){
	int row, col;
	if(show == 1){ // print matrix
		for(row=0; row < sizeMatrix; row++){
			for(col=0; col < sizeMatrix; col++){
				printf(" %.1f \t ", coutMatrix[row][col]);
			}
			printf(" \n ");
		}
	}
	else if(show == 2){ // print inverse
		printf("\n The inverse Of matrix is: \n\n");
		for (row=0; row <sizeMatrix; row++){
			for (col=0; col < sizeMatrix; col++){
				printf(" M[%d][%d]: %.1f/%.1f (%.2f) \t ", row+1, col+1,transposeMatrix[row][col], determinte, coutMatrix[row][col]);
			}
			printf(" \n ");
		}
	}
  return;
}

//---------------------------------------------------
//	calculate minor of matrix OR build new matrix : k-had = minor
void Minor(float minorMatrix[30][30], int colMatrix, int sizeMatrix, float newMinorMatrix[30][30]){
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
  return;
}// end function

//---------------------------------------------------
//	calculate determinte of matrix
float Determinte(float minorMatrix[30][30], int sizeMatrix){
	int col;
	float sum = 0,
		newMinorMatrix[30][30];
	if (sizeMatrix == 1){
		return minorMatrix[0][0];
	}
	else if(sizeMatrix == 2){
		return (minorMatrix[0][0] * minorMatrix[1][1] - minorMatrix[0][1] * minorMatrix[1][0]);
	}
	else {
		for(col=0; col < sizeMatrix; col++){
			Minor(minorMatrix, col, sizeMatrix, newMinorMatrix);	// function
			sum += (float) (minorMatrix[0][col] * pow(-1, col) * Determinte(newMinorMatrix, (sizeMatrix - 1)));	// function
		}
	}
	return sum;
}// end function

//---------------------------------------------------
//	calculate transpose of matrix
void Transpose(float cofactorMatrix[30][30], float sizeMatrix, float determinte, float coutMatrix[30][30], float transposeMatrix[30][30]){
	int row, col;
	for (row=0; row < sizeMatrix; row++){
		for (col=0; col < sizeMatrix; col++){
			transposeMatrix[row][col] = cofactorMatrix[col][row];
			coutMatrix[row][col] = cofactorMatrix[col][row] / determinte; // adjoint method
		}
	}
  return;
}// end function

//---------------------------------------------------
//	calculate cofactor of matrix
void Cofactor(float cinMatrix[30][30], float sizeMatrix, float determinte, float coutMatrix[30][30], float transposeMatrix[30][30]){
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
	Transpose(cofactorMatrix, sizeMatrix, determinte, coutMatrix, transposeMatrix);	// function
  return;
}// end function

//---------------------------------------------------
//	calculate inverse of matrix
void Inverse(float cinMatrix[30][30], int sizeMatrix, float determinte, float coutMatrix[30][30], float transposeMatrix[30][30]){
	if(determinte == 0){
		printf("\n Inverse of entered matrix is not possible \n");
	}
	else if(sizeMatrix == 1){
		coutMatrix[0][0] = 1;
	}
	else {
		Cofactor(cinMatrix, sizeMatrix, determinte, coutMatrix, transposeMatrix);	// function
	}
  return;
}// end function

//---------------------------------------------------
//main fuction
int main(int argc, char **argv){
	int sizeMatrix,
		printMatrix = 1,
		printInverse = 2;
	float determinte,
		cinMatrix[30][30],
		coutMatrix[30][30],
		transposeMatrix[30][30];
	printf("\n C Program to find inverse Of matrix \n");
	sizeMatrix = Cin(cinMatrix, argv, argc);	// function
	Cout(cinMatrix, sizeMatrix, printMatrix, 0, transposeMatrix);	// function
	determinte = (float) Determinte(cinMatrix, sizeMatrix);	// function
	printf("\n ------------------------------ \n");
	printf("\n Determinant of the matrix : %.2f ", determinte);
	printf("\n ------------------------------ \n");
	Inverse(cinMatrix, sizeMatrix, determinte, coutMatrix, transposeMatrix);	// function
	Cout(coutMatrix, sizeMatrix, printInverse, determinte, transposeMatrix);	// function
	printf("\n =======* THE END *=======\n");
	printf("\n *** Thanks for using the program! *** \n");
  return 0;
}// end main
