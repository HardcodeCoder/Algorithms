/**
 * @Author: hardcodecoder
 * @Date:   03:10:39  Tuesday 24 March 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 03:19:27  Tuesday 24 March 2020
 */


 #include<stdio.h>
 #include<stdlib.h>

//performs selection sort on the array
void selectionSort(int *a, int n) {
  int i, j, min;
  for (i = 0; i < n; i++){
    min = i;                       //Consider a[i] as the smallest value
    for (j = i; j < n; j++){       //Iterate over the array from i+1 to n
      if (a[min] > a[j])           //Check for smaller value than a[i]
      min = j;                   //Assign smaller value index to min
    }

    //If min index is not same as i
    //swap the value a[i] and a[min]
    if (min != i){
      int t = a[i];
      a[i] = a[min];
      a[min] = t;
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

  selectionSort(a, n);

  printf("\nSorted data: ");
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);

  return 0;
}
