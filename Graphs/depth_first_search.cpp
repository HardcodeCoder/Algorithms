/**
 * @Author: hardcodecoder
 * @Date:   05:14:22 Friday 17 April 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 05:47:43 Friday 17 April 2020
 */


#include<stdio.h>
#include<stdlib.h>


// Pointer to 2D array to
// stores the adjacency data
int **adjacencyMatrix;

// Stores the number of vertices in the tree
int numVertices;

// Pointer to boolean array to mark visited vertices
bool *visited;


// Helper method to recursively perform DFS
void dfsUtil(int v){
  // Mark the current vertex v as visited
  visited[v] = true;

  // Print the visited vertex
  printf("%d, ", v);

  // Iterate over adjacent vertices and recursively
  // call dfsUtil on the adjacent unvisited vertex
  for (int i = 0; i < numVertices; i++){
    int adj = adjacencyMatrix[v][i];
    if (adj == 1 && !visited[i])
      dfsUtil(i);
  }
}


// implementation of Depth First Search algorithm
void depthFirstSearch(int src){
  visited = (bool*) malloc(sizeof(bool) * numVertices);

  // Initialize all vertices as unvisited
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  // Call the dfs Util method to
  // print the traversal
  printf("\nDepth first traversal:\n");
  dfsUtil(src);
}


// Driver method
int main(){
  int src;

  printf("Enter the number of vertex : ");
  scanf("%d", &numVertices);
  printf("\nEnter the adjacency matrix of (1 if adjacent else 0):\n");

  // pointer to pointer for storing 2d array
  adjacencyMatrix = (int**)malloc(sizeof(int*) * numVertices);

  for (int i = 0; i < numVertices; i++){
    // allocate memory from each row
    adjacencyMatrix[i] = (int*)malloc(sizeof(int) * numVertices);

    // fill each coloum of ith row
    for (int j = 0; j < numVertices; j++)
      scanf("%d", &adjacencyMatrix[i][j]); // or use (*(graph+i)+j)
  }

  printf("\nEnter the source vertex : ");
  scanf("%d", &src);

  depthFirstSearch(src);
  /* Test input
  10
  0 1 0 1 0 0 0 0 0 0
  0 0 1 0 1 0 1 1 0 0
  0 1 0 1 0 0 0 0 1 1
  1 0 1 0 0 0 0 0 0 0
  0 1 0 0 0 1 1 1 0 0
  0 0 0 0 1 0 0 0 0 0
  0 1 0 0 1 0 0 1 0 0
  0 1 0 0 1 0 1 0 0 0
  0 0 1 0 0 0 0 0 0 0
  0 0 1 0 0 0 0 0 0 0
  */
  return 0;
}
