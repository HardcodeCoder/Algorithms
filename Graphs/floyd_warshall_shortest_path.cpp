/**
 * @Author: hardcodecoder
 * @Date:   04:24:42 Thursday 16 April 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 06:12:12 Thursday 16 April 2020
 */


#include<stdio.h>
#include<stdlib.h>

#define INF 9999


// Stores the number of vertices in the graph
int numVertices;

// Adjacency matrix to store the
// shortest distances from each vertex
int **shortestDistanceMatrix;


// Method to print matrix
void printMatrix() {
  int i,j;
  printf ("\nThe following matrix shows the shortest distances between every pair of vertices \n");
  for (i = 0; i < numVertices; i++) {
    for (j = 0; j < numVertices; j++) {
      if (shortestDistanceMatrix[i][j] == INF)
        printf("%5s", "INF");
      else
        printf("%5d", shortestDistanceMatrix[i][j]);
    }
    printf("\n");
  }
}


// Implementation of Floyd-Marshall shortest path algorithm
void floydWarshallShortestPath(int **matrix) {
  int i, j, k;

  // Allocalte memory for pointer to pointer for 2D array
  shortestDistanceMatrix = (int**) malloc(sizeof(int*) * numVertices);

  // Initialize the output matrix same as the source matrix
  for (i = 0; i < numVertices; i++){
    // Allocate memory for each row
    shortestDistanceMatrix[i] = (int*) malloc(sizeof(int) * numVertices);
    for (j = 0; j < numVertices; j++)
        shortestDistanceMatrix[i][j] = matrix[i][j];
  }

  // Iterate with kth vertex as the intermediate vertex
  for (k = 0; k < numVertices; k++){

    // Select all vertices as source for each kth intermediate vertex
    for (i = 0; i < numVertices; i++){

      // Select each vertex as destination for each ith vertex
      for (j = 0; j < numVertices; j++){
        if (shortestDistanceMatrix[i][k] != INF && shortestDistanceMatrix[k][j] != INF &&
           shortestDistanceMatrix[i][j] > shortestDistanceMatrix[i][k] + shortestDistanceMatrix[k][j])
          shortestDistanceMatrix[i][j] = shortestDistanceMatrix[i][k] + shortestDistanceMatrix[k][j];
      }
    }
  }

  // If distance of any verex from itself becomes
  // negative, then there is a negative weight cycle.
  for (i = 0; i < numVertices; i++){
    if (shortestDistanceMatrix[i][i] < 0){
      printf("Negative edge detected, terminating...");
      return;
    }
  }
  // Print the final output
  printMatrix();
}



int main(){
  int **graph;

  printf("Enter the number of vertex : ");
  scanf("%d", &numVertices);
  printf("\nEnter the adjacency matrix (9999 for infinity):\n");

  // pointer to pointer for storing 2d array
  graph = (int**)malloc(sizeof(int*)*numVertices);

  for (int i = 0; i < numVertices; i++){
    // allocate memory from each row
    graph[i] = (int*)malloc(sizeof(int)*numVertices);

    // fill each coloum of ith row
    for (int j = 0; j < numVertices; j++)
      scanf("%d", &graph[i][j]);//or use (*(graph+i)+j)
  }

  floydWarshallShortestPath(graph);
  /* Test input
  0 5 9999 10
  9999 0 3 9999
  9999 9999 0 1
  9999 9999 9999 0
  */
  return 0;
}
