/**
 * @Author: hardcodecoder
 * @Date:   03:18:50 Monday 04 May 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 03:33:40 Monday 04 May 2020
 */


 #include<stdio.h>
 #include<stdlib.h>


 // Optimization criteria
 //1. The sum of i and j is constant and unique for each right diagonal
 //   where i is the row of element and j is the column of element.

 //2. The difference of i and j is constant and unique for each left
 //   diagonal where i and j are row and column of element respectively.


 // 2D Array to store Queens position
 int **chessBoard;
 // Array to store whether queen occupies
 // any position in right diagnol
 int *rightDiagnol;
 // Array to store whether queen occupies
 // any position in left diagnol
 int *leftDiagnol;
 // Array where indices represent column number
 // and states whether queen can be placed in the row
 int *column;


 // Recursive helper method that actually places
 // queens in non-attacking position
 bool resolveQueens(int col, int n){
   if (col >= n) // All queens are placed
     return true;
   for (int i = 0; i < n; i++){
     if (leftDiagnol[i-col+n-1] != 1 // no queen is present in left diagnol
       && rightDiagnol[i+col] != 1   // no queen is present in right diagnol
       && column[i] != 1){           // no queen is present in the ith row

         // Safe to place queen in row:i and column: col
         chessBoard[i][col] = 1;
         // mark this place as occcupied
         leftDiagnol[i-col+n-1] = rightDiagnol[i+col] = column[i] = 1;

         // Continue solving for (col+1)th column
         if(resolveQueens(col+1, n))
           return true;

         // Backtrack if queens cannot be placed
         // Remove queen from this location
         chessBoard[i][col] = 0;
         // mark this place as empty
         leftDiagnol[i-col+n-1] = rightDiagnol[i+col] = column[i] = 0;
     }
   }
   return false;
 }


 // Initializer method for Queens problem
 void placeQueens(int n){
   // Allocate memory for n x n chess board
   chessBoard = (int**) malloc(sizeof(int*) * n);
   // Allocate memory for right diagnol
   rightDiagnol = (int*) malloc(sizeof(int) * 2*n);
   // Allocate memory for left diagnol
   leftDiagnol = (int*) malloc(sizeof(int) * 2 * n);
   // Allocate memory for ther column array
   column = (int*) malloc(sizeof(int) * n);

   // Initialize the chessBoard with zeros
   for (int i = 0; i < n; i++){
     chessBoard[i] = (int*) malloc(sizeof(int) * n);
     for (int j = 0; j < n; j++)
       chessBoard[i][j] = 0;
   }

   // start placing queens starting from top left position (0th row, 0th column)
   bool flag = resolveQueens(0, n);
   if (flag){
     // Got a solution, print chess board
     for (int i = 0; i < n; i++){
       for (int j = 0; j < n; j++){
         if(chessBoard[i][j] == 1) //Queen is placed
           printf("Q  ");
         else
           printf("_  ");
       }
       printf("\n");
     }
   }
   else // No solution found
     printf("\nNo solution possible");
 }


 // Driver method
 int main(){
   int n;
   printf("Enter the number of queens you want to place: ");
   scanf("%d", &n);

   placeQueens(n);
   return 0;
 }
