/**
 * @Author: hardcodecoder
 * @Date:   03:10:18 Friday 15 May 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 03:42:45 Friday 15 May 2020
 */


 import java.io.*;
 import java.util.Scanner;

 public class FloydWarshallShortestPath {

   // Defines  distance for unreachable vertex
   private static final float INF = 9999;

   // Stores the final shortest distances from source to every other vertex
   // Index represent the vertex no. from source and the value gives the distance
   private float[][] shortestDistance;

   // Main method
   public static void main(String args[]) {
     new FloydWarshallShortestPath().initialize();
   }

   // Helper method to input data and initialize necessary variables
   private void initialize() {
     int numVertex;

     System.out.println("Enter the number of vertices: ");
     Scanner sc = new Scanner(System.in);
     numVertex = sc.nextInt();

     // Initialize all necessary variables
     float[][] adjacencyMatrix = new float[numVertex][numVertex];
     shortestDistance = new float[numVertex][numVertex];

     // Input the adjacency matrix also,
     // Initialize the output matrix as input matrix
     System.out.println("Enter the adjacency matrix: ");
     for (int i = 0; i < numVertex; i++) {
       for (int j = 0; j < numVertex; j++) {
         float f = sc.nextFloat();
         adjacencyMatrix[i][j] = f;
         shortestDistance[i][j] = f;
       }
     }

     findShortestpath(numVertex);
   }

   // Implementation of floyd-warshall algorithm
   private void findShortestpath(int numVertex) {
     // Iterate with kth vertex as intermediate vertex
     for (int k = 0; k < numVertex; k++) {
       // Iterate with ith vertex as source for kth intermediate vertex
       for (int i = 0; i < numVertex; i++) {
         // Iterate with jth vertex as destination vertex for
         // ith source vertex and kth intermediate vertex
         for (int j = 0; j < numVertex; j++) {
           // Find shortest path from i-->j with k as intermediate vertex
           if (shortestDistance[i][k] != INF && shortestDistance[k][j] != INF
            &&shortestDistance[i][j] > shortestDistance[i][k] + shortestDistance[k][j])
                  shortestDistance[i][j] = shortestDistance[i][k] + shortestDistance[k][j];
         }
       }
     }

     // If distance of any verex from itself becomes
     // negative, then there is a negative weight cycle.
     for (int i = 0; i < numVertex; i++){
       if (shortestDistance[i][i] < 0){
         System.out.println("Negative edge detected, terminating...");
         return;
       }
     }

     print(numVertex);
   }

   // Helper method to print the output matrix
   private void print(int numVertex) {
     System.out.println("The following matrix shows the shortest distances between every pair of vertices:");
     for (int i = 0; i < numVertex; i++) {
       for (int j = 0; j < numVertex; j++) {
         if (shortestDistance[i][j] == INF)
           System.out.print(String.format("%5s", "INF"));
         else
           System.out.print(String.format("%5.1f", shortestDistance[i][j]));
       }
       System.out.println();
     }
   }
 }
