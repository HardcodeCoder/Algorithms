/**
 * @Author: hardcodecoder
 * @Date:   03:43:46 Friday 15 May 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 03:59:38 Friday 15 May 2020
 */


import java.io.*;
import java.util.Scanner;

public class BubbleSort {

  public static void main(String args[]) {
    int n;
    System.out.println("Enter the number of elements: ");
    Scanner sc = new Scanner(System.in);
    n = sc.nextInt();

    float[] list = new float[n];

    System.out.println("Enter the numbers in the arrray:");
    for (int i = 0; i < n; i++)
      list[i] = sc.nextFloat();

    bubbleSort(list);

    System.out.print("Sorted array: ");
    for (int i = 0; i < n; i++)
      System.out.print(String.format("%.2f, ", list[i]));
    System.out.println();
  }

  private static void bubbleSort(float[] list) {
    int n = list.length;
    for (int i = 0; i < n-1; i++) {
      for (int j = 0; j < n-1-i; j++) {
        if (list[j] > list[j+1]) {
          // Value at jth index is smaller than (j+1)th index
          // swap them to maintain ascending order
          float s = list[j];
          list[j] = list[j+1];
          list[j+1] = s;
        }
      }
    }
  }
}
