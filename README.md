# SudokuSolv
A simple sudoku solving program. Written in C++ and utilizes structs and recursive backtracking. Uses bruteforce method to find solution.

# Tutorial
Use makefile to build. Accepts input after running executable on the command line. 
Accepts input in the form of:

>0 0 5 | 2 3 0 | 8 0 0 
>0 0 0 | 0 0 0 | 2 7 0 
>0 1 0 | 4 0 0 | 0 5 9 
>----------------------
>0 0 0 | 7 0 0 | 0 0 0 
>0 4 9 | 3 6 0 | 7 0 5 
>2 7 0 | 5 0 4 | 0 9 6 
>----------------------
>9 0 6 | 0 0 0 | 0 0 0 
>5 0 0 | 6 0 1 | 0 3 0 
>0 2 7 | 9 0 0 | 0 0 8 

# Example

Input:
0 0 5 | 2 3 0 | 8 0 0 
0 0 0 | 0 0 0 | 2 7 0 
0 1 0 | 4 0 0 | 0 5 9 
----------------------
0 0 0 | 7 0 0 | 0 0 0 
0 4 9 | 3 6 0 | 7 0 5 
2 7 0 | 5 0 4 | 0 9 6 
----------------------
9 0 6 | 0 0 0 | 0 0 0 
5 0 0 | 6 0 1 | 0 3 0 
0 2 7 | 9 0 0 | 0 0 8 

Result:
7 9 5 | 2 3 6 | 8 4 1 
4 6 8 | 1 9 5 | 2 7 3 
3 1 2 | 4 7 8 | 6 5 9 
----------------------
6 5 3 | 7 1 9 | 4 8 2 
8 4 9 | 3 6 2 | 7 1 5 
2 7 1 | 5 8 4 | 3 9 6 
----------------------
9 3 6 | 8 5 7 | 1 2 4 
5 8 4 | 6 2 1 | 9 3 7 
1 2 7 | 9 4 3 | 5 6 8
