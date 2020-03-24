/**
 * @Author: hardcodecoder
 * @Date:   02:48:32  Tuesday 24 March 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 03:19:13  Tuesday 24 March 2020
 */


#include<stdio.h>
#include<stdlib.h>


//Performs bubble sort on the array
void bubbleSort(int *a, int n) {
  int i, j;
  for (i = 0; i < n-1; i++){
    //Iterate only upto n-i-1 time
    //since the largest value get's pushed tothe last index
    //at every pass and needs no more comparision
    for (j = 0; j < n-i-1; j++){
      //Swaps two consecutive array values
      //If next index has a smaller value than current index
      if (a[j] > a[j+1]) {
        int t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
    }
  }
}


//Driver method
int main() {
  int *a;
  int i, n;

  printf("Enter the size of the array : ");
  scanf("%d", &n);

  a=(int*)malloc(sizeof(int)*n);

  printf("\nEnter the data: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("\nUnsorted data: ");
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);

  bubbleSort(a, n);

  printf("\nSorted data: ");
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);

  return 0;
}
