/**
 * @Author: hardcodecoder
 * @Date:   02:14:46 Thursday 16 April 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 06:13:10 Thursday 16 April 2020
 */


#include<stdio.h>
#include<stdlib.h>

//Since infinity is not logically possible in C
//Define infinity to a large value
#define INF 9999

//Struct to represent an edge
struct Edge {
  int src, dest, wt;
};


//Stores the preceding vertex
//from the current vertexx
int *precedingVertexInShortestPath;

//Stores the distance of all
//vertices from source vertex
int *distanceFromSource;


//Method to recursively print
//the path from src --> dest
int printShortestPath(int src, int dest){
  if (src == dest)
    return src;
  printf("%d --> ", printShortestPath(src, precedingVertexInShortestPath[dest]));
  return dest;
}


//Helper method to handle print queries
void print(int v, int src, int dest){
  printf("\nMinimum distance between %d -> %d = %d\n", src, dest, distanceFromSource[dest]);
  printf("\nPath : ");
  printf("%d", printShortestPath(src, dest));

  //Uncomment below code to print all distances from source
  /*printf("\n\nVertex\tDistance from source\n");
  for (int i = 0; i < v; i++){
    int distance = distanceFromSource[i];
    if (distance < 0)
      printf("%d\t\t%d\n", i, distance);
    else
      printf("%d\t\t+%d\n", i, distance);
  }*/
}


//Implementation of Bellman-Ford shortest path algorithm
void bellmanFordShortestPath(int numVertices, int numEdges, struct Edge *edgeList, int src, int dest){
  int i,j;

  distanceFromSource = (int*) malloc(sizeof(int) * numVertices);
  precedingVertexInShortestPath = (int*) malloc(sizeof(int) * numVertices);

  //Initialize all distance from source to infinity
  for (i = 0; i < numVertices; i++)
    distanceFromSource[i] = INF;

  //Initialize distance of source to 0
  distanceFromSource[src] = 0;

  //Relax all the adges for |V| -1 times
  for (i = 0; i < numVertices; i++){
    //Interate over all edges
    for (j = 0; j < numEdges; j++){
      int u = edgeList[j].src;
      int v = edgeList[j].dest;
      int w = edgeList[j].wt;

      //Check new distance from source is
      //lower than previous stored distance
      if (distanceFromSource[u] != INF && distanceFromSource[u] + w < distanceFromSource[v]){
        //Update distance
        distanceFromSource[v] = distanceFromSource[u] + w;
        //Store the preceding vertex
        precedingVertexInShortestPath[v] = u;
      }
    }
  }

  //Relax the edges one more time
  //if the distance(s) changes we have a negative cycle
  //Terminate the program
  for (i = 0; i < numEdges; i++){
    int u = edgeList[i].src;
    int v = edgeList[i].dest;
    int w = edgeList[i].wt;
    if (distanceFromSource[u] != INF && distanceFromSource[u] + w < distanceFromSource[v]){
      //Change in distance, which means a negative cycle
      //Terminate the program
      printf("Negative cycle detected, terminating...");
      return;
    }
  }

  print(numVertices, src, dest);
}


//Driver method
int main(){
  int v, e, src, dest;
  printf("Enter the number of vertices and edges : ");
  scanf("%d %d", &v, &e);

  struct Edge *edgeList = (struct Edge*)malloc(sizeof(struct Edge)*e);
  printf("\nEnter the edge list in the format:\nSrc vertex\tDest vertex\tWt\n");

  for (int i = 0; i < e; i++){
    scanf("%d%d%d", &edgeList[i].src, &edgeList[i].dest, &edgeList[i].wt);
  }

  printf("\nEnter the source and destination vertex : ");
  scanf("%d%d", &src, &dest);

  bellmanFordShortestPath(v, e, edgeList, src, dest);

  /* Test input
  5 8
  0 1 -1
  0 2 4
  1 2 3
  1 3 2
  1 4 2
  3 2 5
  3 1 1
  4 3 -3
  */
  return 0;
}
