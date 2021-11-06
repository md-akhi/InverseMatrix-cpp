#include <stdio.h>

//----------------------------------------------------------
//read matrix : cin>> in c++ , scanf() in c
int cin(float readMatrix[100][100]){
	int horizontal,vertical,n;
	printf("\n Enter Length Of Matrix N*N : ");
	scanf("%d",&n);
	printf("\n--------------------------\n");
	for(horizontal=0;horizontal<n;horizontal++)
		for(vertical=0;vertical<n;vertical++){
			printf(" Matrix[%d][%d] : ",horizontal+1,vertical+1);
			scanf("%f",&readMatrix[horizontal][vertical]);
		}
	printf("\n----------------------------------------------------\n");
return n;
}

//-----------------------------------------------------
// show matrix : cout<< in c++ , printf() in c
void cout(float writeMatrix[100][100],int n,int show){
	int horizontal,vertical;
	if(show == 1)
		for(horizontal=0;horizontal < n;horizontal++){
			for(vertical=0;vertical < n;vertical++)
				printf(" %.2f \t",writeMatrix[horizontal][vertical]);
			printf("\n");
		}
	else if(show == 2){
		printf("\n\n The Inverse Of Matrix Is : \n\n");
		for (horizontal=0;horizontal<n;horizontal++){
			for (vertical=0;vertical<n;vertical++)
				printf(" %.4f \t",writeMatrix[horizontal][vertical]);
			printf("\n");
		}
	}
}

//---------------------------------------------------
//	calculate minor of matrix OR build new matrix : k-had = minor
void minor(float b[100][100],float a[100][100],int horizontal,int sizeMatrix){
	int j,l,h=0,k=0;
	for(l=1;l<sizeMatrix;l++)
		for( j=0;j<sizeMatrix;j++){
			if(j == horizontal)
				continue;
			b[h][k] = a[l][j];
			k++;
			if(k == (sizeMatrix-1)){
				h++;
				k=0;
			}
		}
}// end function

//---------------------------------------------------
//	calculate determinte of matrix
float determinte(float matrix[100][100],int sizeMatrix){
	int horizontal;
	float b[100][100],sum=0;
	if (sizeMatrix == 1)
return matrix[0][0];
	else if(sizeMatrix == 2)
return (matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0]);
	else
		for(horizontal=0;horizontal<sizeMatrix;horizontal++){
			minor(b,matrix,horizontal,sizeMatrix);	// read function
			sum = (float) (sum+matrix[0][horizontal]*pow(-1,horizontal)*determinte(b,(sizeMatrix-1)));	// read function	// sum = determinte matrix
		}
return sum;
}// end function

//---------------------------------------------------
//	calculate transpose of matrix
void transpose(float cofactorMatrix[100][100],float writeMatrix[100][100],float sizeMatrix,float determinte){
	int horizontal,vertical;
	float b[100][100];
	for (horizontal=0;horizontal<sizeMatrix;horizontal++)
		for (vertical=0;vertical<sizeMatrix;vertical++)
			b[horizontal][vertical] = cofactorMatrix[vertical][horizontal];
	for (horizontal=0;horizontal<sizeMatrix;horizontal++)
		for (vertical=0;vertical<sizeMatrix;vertical++)
			writeMatrix[horizontal][vertical] = b[horizontal][vertical]/determinte;	// array d[][] = inverse matrix
}// end function

//---------------------------------------------------
//	calculate cofactor of matrix
void cofactor(float readMatrix[100][100],float writeMatrix[100][100],float sizeMatrix,float determinte){
	float b[100][100],cofactorMatrix[100][100];
	int l,h,m,k,horizontal,vertical;
	for (h=0;h<sizeMatrix;h++)
		for (l=0;l<sizeMatrix;l++){
			m=0;
			k=0;
			for (horizontal=0;horizontal<sizeMatrix;horizontal++)
				for (vertical=0;vertical<sizeMatrix;vertical++)
					if (horizontal != h && vertical != l){
						b[m][k]=readMatrix[horizontal][vertical];
						if (k<(sizeMatrix-2))
							k++;
						else{
							k=0;
							m++;
						}
					}
			cofactorMatrix[h][l] = pow(-1,(h+l))*determinte(b,(sizeMatrix-1));	// c = cofactor Matrix
		}
	transpose(cofactorMatrix,writeMatrix,sizeMatrix,determinte);	// read function
}// end function

//---------------------------------------------------
//	calculate inverse of matrix
void inverse(float readMatrix[100][100],float writeMatrix[100][100],int sizeMatrix,float determinte){
	if(determinte == 0)
		printf("\nInverse of Entered Matrix is not possible\n");
	else if(sizeMatrix == 1)
		writeMatrix[0][0] = 1;
	else
		cofactor(readMatrix,writeMatrix,sizeMatrix,determinte);	// read function
}// end function

//---------------------------------------------------
//main fuction exe
int main(void){
	int sizeMatrix,
	 matrixPrint = 1,
	 inversePrint = 2;
	float readMatrix[100][100],writeMatrix[100][100],deter;
	printf("\n C Program To Find Inverse Of Matrix\n\n");
	sizeMatrix = cin(readMatrix);	// read function
	cout(readMatrix,sizeMatrix,matrixPrint);	// read function
	deter = (float) determinte(readMatrix,sizeMatrix);	// read function
		printf("----------------------------------------------------\n");
		printf("\n\n Determinant of the Matrix : %.4f ",deter);
		printf("\n\n-----------------------\n");
	inverse(readMatrix,writeMatrix,sizeMatrix,deter);	// read function
	cout(writeMatrix,sizeMatrix,inversePrint);	// read function
		printf("\n\n==============================* THE END *==============================\n");
		printf("\n		**** Thanks For Using The Program!!! ****\n");
	getch();
    return 0;
}// end main
