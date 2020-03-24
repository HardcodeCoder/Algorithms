/**
 * @Author: hardcodecoder
 * @Date:   02:31:26  Tuesday 24 March 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 02:35:45  Tuesday 24 March 2020
 */

 #include <stdio.h>
 #include <stdlib.h>

//Helper method to swap two array elements
 void swap(int* x, int* y) {
   int t = *x;
   *x = *y;
   *y = t;
 }


//Partitions the array intwo two sub arrays and returns the partition index
 int partition(int* a, int l, int h) {
   int piv = a[h];
   int i = l;
   for(int j = i; j<=h-1;j++){
     if(a[j] < piv){
       swap(&a[i], &a[j]);
       i++;
     }
   }
   swap(&a[i], &a[h]);
   return i;
 }


//Sort the array by recursively calling sort with updated partition index
 void sort(int* a, int l, int h) {
   if(l<h){
     int p = partition(a,l,h);
     sort(a,0,p-1);
     sort(a,p+1,h);
   }
 }


//Driver method
 int main() {
   int n, *a, i;
   printf("Enter the size of the array : ");
   scanf("%d", &n);

   a = (int*)malloc(sizeof(int) * n);

   printf("Enter the data : \n");
   for(i = 0;i<n;i++)
     scanf("%d", &a[i]);

   printf("\nUnsorted array : ");
   for(i = 0;i<n;i++)
     printf("%d ", a[i]);

   sort(a, 0, n-1);
   
   printf("\nSorted array : ");
   for(i = 0;i<n;i++)
     printf("%d ", a[i]);

   return 0;
 }
