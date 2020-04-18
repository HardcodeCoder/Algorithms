/**
 * @Author: hardcodecoder
 * @Date:   03:23:41 Saturday 18 April 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 03:35:03 Saturday 18 April 2020
 */


 #include<stdio.h>
 #include<stdlib.h>
 #include<limits.h>


 // Method to find minimum number of scaler multiplications
 // needed to multiply the chain of matrices
 int computeMinimum(int *dimensions, int n){
   int i, j, k, L, q;

   // Matrix to store the cost of multiplying chain of matricies
   // cost[i][j] gives the cost of multiplying martices
   // A[i] * A[i+1] * ... * A[j]
   // 0th row and 0th column is not used for simplicity
   int cost[n][n];

   // Cost is zero for one multiplication
   // single matrix (no multiplication is required)
   for (i = 0; i < n; i++)
     cost[i][i] = 0;

   // Determines chaining length
   // first multiply two matrices together,
   // then three, and so on
   for (L = 2; L < n; L++){

     // Iterates over all possible
     // groups for chaining length L
     for(i = 1; i < n-L+1; i++){
       j = i+L-1;
       cost[i][j] = INT_MAX;

       // Calculates cost for matrix pair
       // in group i
       for(k = i; k < j; k++){
         q = cost[i][k] + cost[k+1][j] + dimensions[i-1] * dimensions[k] * dimensions[j];
         if (q < cost[i][j])
           cost[i][j] = q;
       }
     }
   }

   return cost[1][n-1];
 }


 // Driver method
 int main(){
   int i, n;
   int *dimensions;

   printf("Enter the number of matrices in the chain: ");
   scanf("%d", &n);

   // No of dimensions is 1 gretaer
   // than number of matrices in the chain
   // so increase n by 1
   n++;

   //Allocate memory for dimensions array
   dimensions = (int*) malloc(sizeof(int) * n);

   printf("\nEnter the dimensions of the matrices:\n");

   for (i = 0; i < n; i++)
     scanf("%d", &dimensions[i]);

   printf("\nMinumum number of multiplications required: %d", computeMinimum(dimensions, n));

   /*Test input
    5
    2 3 4 5 6 2
   */
 }
