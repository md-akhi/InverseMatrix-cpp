Inverse-matrix
==============

The inverse matrix C/C++

## Install C/C++
```sh
# OS Ubuntu
# Update apt repository
$ sudo apt update
# Install build-essential
$ sudo apt install build-essential

# Check GCC version
$ gcc --version
# Check G++ version
$ g++ --version
# Output
gcc/g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
Copyright (C) 2019 Free Software Foundation, Inc.
```

## Compile & Run
> c
```sh
# gcc == cc
# Compiling the C program
$ cc Inverse-matrix.c -o c.out
# if error dl
$ cc Inverse-matrix.c -o c.out -lm
```
```bash
# Run C program
$ ./c.out

# run with input / output file
$ ./c.out < ex.in > ex.out
```

> cpp/c++
```sh
# Compiling the C++ program
$ g++ Inverse-matrix.cpp -o cpp.out
```
```bash
# Run C++ program
$ ./cpp.out

# run with input / output file
$ ./cpp.out < ex.in > ex.out
```
## Input / Output File
> example input file
```markdown
# ex.in
2 // N
1 // Matrix[1][1]
9 // Matrix[1][2]
3 // Matrix[2][1]
7 // Matrix[2][2]

# or
4	// N
1	9	0	5	// Matrix[1][1]	Matrix[1][2]	Matrix[1][3]	Matrix[1][4]	
3	7	0	6	// Matrix[2][1]	Matrix[2][2]	Matrix[2][3]	Matrix[2][4]
3	7	0	5	// Matrix[3][1]	Matrix[3][2]	Matrix[3][3]	Matrix[3][4]
1	2	8	1	// Matrix[4][1]	Matrix[4][2]	Matrix[4][3]	Matrix[4][4]
```

> example output file
```markdown
# ex.out
 C Program to find inverse Of matrix 
 Enter the size of matrix N*N: 
 ------------------------------ 
 Enter the elements of matrix: 
  M[1][1]:  M[1][2]:  M[1][3]:  M[1][4]:  
  M[2][1]:  M[2][2]:  M[2][3]:  M[2][4]:  
  M[3][1]:  M[3][2]:  M[3][3]:  M[3][4]:  
  M[4][1]:  M[4][2]:  M[4][3]:  M[4][4]:  
 
 ------------------------------ 
  1.0 	  9.0 	  0.0 	  5.0 	  
  3.0 	  7.0 	  0.0 	  6.0 	  
  3.0 	  7.0 	  0.0 	  5.0 	  
  1.0 	  2.0 	  8.0 	  1.0 	  
 
 ------------------------------ 

 Determinant of the matrix : -160.00 

 ------------------------------ 

 The inverse Of matrix is: 

  M[1][1]: 56.0/-160.0 (-0.35) 	  M[1][2]: 80.0/-160.0 (-0.50) 	  M[1][3]: -152.0/-160.0 (0.95) 	  M[1][4]: -0.0/-160.0 (0.00) 	  
  M[2][1]: -24.0/-160.0 (0.15) 	  M[2][2]: 80.0/-160.0 (-0.50) 	  M[2][3]: -72.0/-160.0 (0.45) 	  M[2][4]: 0.0/-160.0 (-0.00) 	  
  M[3][1]: -1.0/-160.0 (0.01) 	  M[3][2]: -10.0/-160.0 (0.06) 	  M[3][3]: 17.0/-160.0 (-0.11) 	  M[3][4]: -20.0/-160.0 (0.12) 	  
  M[4][1]: -0.0/-160.0 (0.00) 	  M[4][2]: -160.0/-160.0 (1.00) 	  M[4][3]: 160.0/-160.0 (-1.00) 	  M[4][4]: 0.0/-160.0 (-0.00) 	  
 
 =======* THE END *=======

 *** Thanks for using the program! *** 
```
