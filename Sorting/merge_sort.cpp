/**
* @Author: hardcodecoder
* @Date:   02:36:42  Tuesday 24 March 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 02:48:13  Tuesday 24 March 2020
*/


#include <stdio.h>
#include <stdlib.h>


//Merges two sub arrays into original array
void mergeSubArray(int *L, int *a, int*R, int l){
  int mL = l/2;
  int mR = l-mL;
  int i = 0, j = 0, k=0;

  //Copy data from L and R into original array
  while(i < mL && j < mR){
    if(L[i] < R[j]){             //Ascending order; smaller elemnt first
      a[k] = L[i];
      i++;
    }
    else{
      a[k] = R[j];
      j++;
    }
    k++;
  }

  //Copy remaining elemnt from L sub array
  while(i<mL){
    a[k] = L[i];
    i++;
    k++;
  }

  //Copy remaining elements from R sub array
  while(j<mR){
    a[k] = R[j];
    j++;
    k++;
  }
}


//Divides the array into two new sub array L and R
//and copies the data from original array to L & R
//recursively call sort in su array L and R
void sort(int *a, int l){
  if(l>1){
    int *L, *R, mid, i;
    mid = l/2;

    L = (int*)malloc(sizeof(int)*mid);      //Allocates memory for Left sub array
    R = (int*)malloc(sizeof(int)*(l-mid));  //Allocates memory for Right sub array

    for(i=0;i<mid;i++)                      //Copies data into Left sub array
      L[i] = a[i];

    for(i=mid;i<l;i++)                      //Copies data into Right sub array
      R[i-mid] = a[i];

    //Recursively call sort into Left and Right sub array
    sort(L, mid);
    sort(R, l-mid);

    //Merge sorted Left and Right sub array
    mergeSubArray(L,a,R,l);
  }
}


int main(){
  int *a,n,i;

  printf("Enter the size of the array : ");
  scanf("%d", &n);

  a = (int*)malloc(n * sizeof(int));

  printf("Enter the data : \n");
  for(i=0;i<n;i++)
    scanf("%d", &a[i]);

  printf("\nUnsorted array : ");
  for(i=0;i<n;i++)
    printf("%d ", a[i]);

  sort(a,n);

  printf("\nSorted array : ");
  for(i=0;i<n;i++)
    printf("%d ", a[i]);
}
