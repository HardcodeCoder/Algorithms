/**
 * @Author: hardcodecoder
 * @Date:   02:22:23 Friday 17 April 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 05:48:04 Friday 17 April 2020
 */


#include<stdio.h>
#include<stdlib.h>

// variables for queue implementation
int *queue, front = -1, rear = -1, size;


// Methood to insert item in the queue
void insertIntoQueue(int a){
  if (rear == size-1){
    printf("\nQueue is full aborting...");
    return;
  }
  if (rear == -1 && front == -1)
    front = rear = 0;
  else
    rear++;
  queue[rear] = a;
}


// Method to delete an item in the queue
int removeFromQueue() {
  if (front == -1 || front > rear){
    printf("\nQueue is empty, aborting....");
    return -1;
  }
  int a = queue[front++];
  if (front > rear)
    front = rear = -1;
  return a;
}


// Helper method to check if queue is empty
bool queueIsEmpty(){
  if (front == -1 && rear == -1)
    return true;
  return false;
}


// Implementation of Breadth First Search algorithm
void breadthFirstSearch(int **adjacencyMatrix, int numVertices, int src){
  int i,j;
  bool *visited = (bool*) malloc(sizeof(bool) * numVertices);
  queue = (int*) malloc(sizeof(int) * numVertices);
  size = numVertices;

  // mark all vertices as unvisited
  for (i = 0; i < numVertices; i++)
    visited[i] = false;

  // mark the source vertex as visited
  visited[src] = true;

  // insert into queue
  insertIntoQueue(src);

  printf("\nBreadth first traversal:\n");
  while(!queueIsEmpty()){
    int v = removeFromQueue();
    if (v == -1){
      printf("\nCalled remove on an empty queue, aborting....");
      return;
    }
    printf("%d, ", v);

    // Explore all adjacent vertex from vertex v
    for (i = 0; i < numVertices; i++){
      int adj = adjacencyMatrix[v][i];

      if (adj == 1 && !visited[i]){
        // vertex 'i' is adjacent to vertex 'v'
        // and is unvisited
        insertIntoQueue(i);
        visited[i] = true;
      }
    }
  }
}


// Driver method
int main(){
  int **adjacencyMatrix;
  int v, src;

  printf("Enter the number of vertex : ");
  scanf("%d", &v);
  printf("\nEnter the adjacency matrix of (1 if adjacent else 0):\n");

  // pointer to pointer for storing 2d array
  adjacencyMatrix = (int**)malloc(sizeof(int*)*v);

  for (int i = 0; i < v; i++){
    // allocate memory from each row
    adjacencyMatrix[i] = (int*)malloc(sizeof(int)*v);

    // fill each coloum of ith row
    for (int j = 0; j < v; j++)
      scanf("%d", &adjacencyMatrix[i][j]); // or use (*(graph+i)+j)
  }

  printf("\nEnter the source vertex : ");
  scanf("%d", &src);

  breadthFirstSearch(adjacencyMatrix, v, src);
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
