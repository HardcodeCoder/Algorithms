/**
 * @Author: hardcodecoder
 * @Date:   02:30:40 Sunday 05 April 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 05:01:53 Sunday 05 April 2020
 */


#include<stdio.h>
#include<stdlib.h>

#define INF 9999

int *previousVertex; //array to store preceding vertex
int *distance;       //array to store distance from source vertex(shortest distance) for each vertex

//Helper method to find the minimum weighted
//vertex from the current vertex
int minWeight(bool *visited){
  int min = INF;
  int minIndex = -1;
  for (int v = 0; v < 9; v++){
    if (!visited[v] && distance[v] <= min)
      min = distance[v], minIndex = v;
  }
  return minIndex;
}


//Recursive method to print the shortest path
//between source and destination vertex
int printPath(int src, int dest) {
  if (src == dest) return src;
  printf("%d --> ", printPath(src, previousVertex[dest]));
  return dest;
}


//Helper method to handle print queries
void print(int v, int src, int dest){
  printf("\nMinimum weight between %d -> %d = %d\n", src, dest, distance[dest]);
  printf("\nPath : ");
  printf("%d", printPath(src, dest));

  //Uncomment below code to print all distances from source
  /*printf("\n\nVertex\tDistance from source\n");
  for (int i = 0; i < v; i++){
    printf("%d\t\t%d\n", i, distance[i]);
  }*/
}


//Implementation of dijkstra's shortest path algorithm
void dijkstraShortestPath (int vertexCount, int **graph, int src, int dest) {
  bool *visited; //array to mark visited vertices

  //allocate memory for arrays
  previousVertex = (int*)malloc(sizeof(int)*vertexCount);
  distance = (int*)malloc(sizeof(int)*vertexCount);
  visited = (bool*)malloc(sizeof(bool)*vertexCount);

  for (int i = 0; i < vertexCount; i++){
    distance[i] = INF;
    visited[i] = false;
  }

  //set source vertex distance to zero
  distance[src] = 0;

  for (int i = 0; i < vertexCount-1; i++){

    //returns min weighted vertex from list of
    //non visited vertex adjacent to current vertex
    int min = minWeight(visited);

    //mark choosen vertex as visited
    visited[min] = true;

    for (int v = 0; v < vertexCount; v++){
      //select new distance throught min if vertex is:
      //not visited, is adjacent to current vertex,
      //distance throught min is less than old distance
      if (!visited[v] && graph[min][v] && distance[min] != INF && distance[min] + graph[min][v] < distance[v]){
        distance[v] = distance[min] + graph[min][v];
        previousVertex[v] = min;   //store the preceding vertex for vth vertex
      }
    }
  }
  print(vertexCount, src, dest);
}


//driver method
int main() {
  int **graph;
  int v, src, dest;

  printf("Enter the number of vertex : ");
  scanf("%d", &v);
  printf("\nEnter the adjacency matrix of weights:\n");

  //pointer to pointer for storing 2d array
  graph = (int**)malloc(sizeof(int*)*v);

  for (int i = 0; i < v; i++){
    //allocate memory from each row
    graph[i] = (int*)malloc(sizeof(int)*v);

    //fill each coloum of ith row
    for (int j = 0; j < v; j++)
      scanf("%d", &graph[i][j]);//or use (*(graph+i)+j)
  }

  printf("\nEnter the source and destination vertex : ");
  scanf("%d%d", &src, &dest);

  dijkstraShortestPath(v, graph, src, dest);
  /*Test input
  0 4 0 0 0 0 0 8 0
  4 0 8 0 0 0 0 11 0
  0 8 0 7 0 4 0 0 2
  0 0 7 0 9 14 0 0 0
  0 0 0 9 0 10 0 0 0
  0 0 4 14 10 0 2 0 0
  0 0 0 0 0 2 0 1 6
  8 11 0 0 0 0 1 0 7
  0 0 2 0 0 0 6 7 0
  */
  return 0;
}
