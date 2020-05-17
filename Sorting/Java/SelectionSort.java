/**
 * @Author: hardcodecoder
 * @Date:   03:08:17 Sunday 17 May 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 03:28:36 Sunday 17 May 2020
 */


 import java.io.*;
 import java.util.Scanner;

 public class SelectionSort {

   // Main method
   public static void main(String args[]) {
     new SelectionSort().initialize();
   }

   // Helper method to input data
   private void initialize() {
     System.out.println("Enter the number of elements: ");
     Scanner sc = new Scanner(System.in);
     int n = sc.nextInt();

     float[] list = new float[n];

     System.out.println("Enter the numbers in the arrray:");
     for (int i = 0; i < n; i++)
       list[i] = sc.nextFloat();

     selectionSort(list);
   }


   // Implementation of selection sort algorithm
   private void selectionSort(float[] list) {
     for (int i = 0; i < list.length; i++) {
       int min = i;                                 // Consider list[i] as the smallest value
       for (int j = i; j < list.length; j++) {      // Iterate over the list once for each i
         if (list[j] < list[min])                   // Find if there's a smaller value than list[min]
          min = j;
       }

       // If list[i] is not the smallest value
       // swap list[i] and list[min]
       if (min != i) {
         float f = list[i];
         list[i] = list[min];
         list[min] = f;
       }
     }
     print(list);
   }

   // Helper method to print array
   private void print(float[] list) {
     System.out.print("Sorted array: ");
     for (int i = 0; i < list.length; i++)
       System.out.print(String.format("%.2f, ", list[i]));
     System.out.println();
   }
 }
