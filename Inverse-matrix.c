#include <stdio.h>

//----------------------------------------------------------
//read matrix : cin>> in c++ , scanf() in c
int Cin(float cinMatrix[100][100]){
	int row, col, sizeMatrix;
	printf("\n Enter Length Of Matrix N*N: ");
	scanf("%d", &sizeMatrix);
	printf("\n -------------------------- \n");
	for(row=0; row < sizeMatrix; row++)
		for(col=0; col < sizeMatrix; col++){
			printf(" Matrix[%d][%d]: ", row+1, col+1);
			scanf("%f", &cinMatrix[row][col]);
		}
	printf(" \n----------------------------------------------------\n ");
	return sizeMatrix;
}

//-----------------------------------------------------
// show matrix : cout<< in c++ , printf() in c
void Cout(float coutMatrix[100][100], int sizeMatrix, int show){
	int row, col;
	if(show == 1) // print matrix
		for(row=0; row < sizeMatrix; row++){
			for(col=0; col < sizeMatrix; col++)
				printf(" %.2f \t ", coutMatrix[row][col]);
			printf(" \n ");
		}
	else if(show == 2){ // print inverse
		printf("\n\n The Inverse Of Matrix Is: \n\n");
		for (row=0; row <sizeMatrix; row++){
			for (col=0; col < sizeMatrix; col++)
				printf(" %.4f \t ", coutMatrix[row][col]);
			printf(" \n ");
		}
	}
	printf("\n\n print not found \n\n");
  return;
}

//---------------------------------------------------
//	calculate minor of matrix OR build new matrix : k-had = minor
void Minor(float minorMatrix[100][100], int colMatrix, int sizeMatrix, float newMinorMatrix[100][100]){
	int col, row, row2 = col2 = 0;
	for(row=1; row < sizeMatrix; row++)
		for( col=0; col < sizeMatrix; col++){
			if(col == colMatrix)
				continue;
			newMinorMatrix[row2][col2] = minorMatrix[row][col];
			col2++;
			if(col2 == (sizeMatrix - 1)){
				row2++;
				col2 = 0;
			}
		}
    return;
}// end function

//---------------------------------------------------
//	calculate determinte of matrix
float Determinte(float minorMatrix[100][100], int sizeMatrix){
	int col;
	float sum=0,
		newMinorMatrix[100][100];
	if (sizeMatrix == 1)
		return minorMatrix[0][0];
	else if(sizeMatrix == 2)
		return (minorMatrix[0][0] * minorMatrix[1][1] - minorMatrix[0][1] * minorMatrix[1][0]);
	else
		for(col=0; col < sizeMatrix; col++){
			Minor(minorMatrix, col, sizeMatrix, newMinorMatrix);	// function
			sum += (float) (minorMatrix[0][col] * pow(-1, col) * Determinte(newMinorMatrix, (sizeMatrix - 1)));	// function
		}
	return sum;
}// end function

//---------------------------------------------------
//	calculate transpose of matrix
void Transpose(float cofactorMatrix[100][100], float sizeMatrix, float determinte, float coutMatrix[100][100]){
	int row, col;
	float transpose[100][100];
	for (row=0; row < sizeMatrix; row++)
		for (col=0; col < sizeMatrix; col++)
			transpose[row][col] = cofactorMatrix[col][row];
	for (row=0; row < sizeMatrix; row++)
		for (col=0; col < sizeMatrix; col++)
			coutMatrix[row][col] = transpose[row][col] / determinte; // adjoint method
    return;
}// end function

//---------------------------------------------------
//	calculate cofactor of matrix
void Cofactor(float cinMatrix[100][100], float sizeMatrix, float determinte, float coutMatrix[100][100]){
	float minorMatrix[100][100],cofactorMatrix[100][100];
	int col3, row3, row2, col2, row, col;
	for (row3=0; row3 < sizeMatrix; row3++)
		for (col3=0; col3 < sizeMatrix; col3++){
			row2 = col2 = 0;
			for (row=0; row < sizeMatrix; row++)
				for (col=0; col < sizeMatrix; col++)
					if (row != row3 && col != col3){
						minorMatrix[row2][col2] = cinMatrix[row][col];
						if (col2 < (sizeMatrix - 2))
							col2++;
						else{
							col2 = 0;
							row2++;
						}
					}
			cofactorMatrix[row3][col3] = pow(-1, (row3 + col3)) * Determinte(minorMatrix, (sizeMatrix - 1));
		}
	Transpose(cofactorMatrix, sizeMatrix, determinte, coutMatrix);	// function
    return;
}// end function

//---------------------------------------------------
//	calculate inverse of matrix
void Inverse(float cinMatrix[100][100], int sizeMatrix, float determinte, float coutMatrix[100][100]){
	if(determinte == 0)
		printf("\n Inverse of Entered Matrix is not possible \n");
	else if(sizeMatrix == 1)
		coutMatrix[0][0] = 1;
	else
		Cofactor(cinMatrix, sizeMatrix, determinte, coutMatrix);	// function
    return;
}// end function

//---------------------------------------------------
//main fuction
int main(void){
	int sizeMatrix,
	 printMatrix = 1,
	 printInverse = 2;
	float determinte,
	cinMatrix[100][100],
	coutMatrix[100][100];
	printf("\n C Program To Find Inverse Of Matrix \n\n");
	sizeMatrix = Cin(cinMatrix);	// function
	Cout(cinMatrix, sizeMatrix, printMatrix);	// function
	determinte = (float) Determinte(cinMatrix, sizeMatrix);	// function
	printf(" ---------------------------------------------------- \n");
	printf("\n\n Determinant of the Matrix : %.4f ", determinte);
	printf("\n\n-----------------------\n");
	Inverse(cinMatrix, sizeMatrix, determinte, coutMatrix);	// function
	Cout(coutMatrix, sizeMatrix, printInverse);	// function
	printf("\n\n ==============================* THE END *============================== \n");
	printf("\n		**** Thanks For Using The Program! **** \n");

	getch();
  return;
}// end main
