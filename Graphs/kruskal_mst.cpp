/**
 * @Author: hardcodecoder
 * @Date:   02:42:59  Sunday 22 March 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 03:28:19 Tuesday 21 April 2020
 */


#include<stdio.h>
#include<stdlib.h>

//Structure to hold single edge
struct Edge{
  int src, dest, wt;
};


//Structure to represent subset in Union-find
struct Subset{
  int size, rootId;
};


//Subset array for Union-find
struct Subset *subsets;


//Finds the root vertex of a given vertex 'x' (Uses Path-compressesion method)
int find(int x){
  if (subsets[x].rootId != x)
    subsets[x].rootId = find(subsets[x].rootId); //Recursively find and compressess path to the root vertex
  return subsets[x].rootId;
}


//Unifies two subsets, smaller subset get's merged into large subset
void unifi(int x, int y){
  int xroot = find(x);
  int yroot = find(y);

  if (subsets[xroot].size > subsets[yroot].size)
    subsets[yroot].rootId = xroot;
  else if (subsets[xroot].size < subsets[yroot].size)
    subsets[xroot].rootId = yroot;
  else{
    subsets[yroot].rootId = xroot;
    subsets[xroot].size++;
  }
}


void sortEdgeList(struct Edge* edgeList, int n){
  for (int i = 0; i < n; i++){
    int min = i;
    for (int j = i+1; j < n; j++){
      if (edgeList[j].wt < edgeList[min].wt)
        min = j;
    }
    //Swap edgeList[min] and edgeList[i]
    struct Edge temp = edgeList[i];
    edgeList[i] = edgeList[min];
    edgeList[min] = temp;
  }

  /*printf("\nSorted edges:\nSrc\tDest\tWeight\n");
  for (int i=0;i<n;i++)
    printf("%d\t%d\t%d\n", edgeList[i].src, edgeList[i].dest, edgeList[i].wt);*/
}


void kruskal(struct Edge *edgeList, int v, int e){
  struct Edge *mst;
  int mstIndex = 0, i = 0;
  //Sort the edgeList
  sortEdgeList(edgeList, e);

  subsets = (struct Subset*)malloc(sizeof(struct Subset)*v);
  mst = (struct Edge*)malloc(sizeof(struct Edge)*v);

  for(int i = 0; i < v; i++){
    subsets[i].rootId = i;
    subsets[i].size = 1;
  }
  i=0;

  while (mstIndex < v-1 && i < e){
    struct Edge nextEdge = edgeList[i++];

    int x = find(nextEdge.src);
    int y = find(nextEdge.dest);

    if (x != y){
      mst[mstIndex++] = nextEdge;
      unifi(x, y);
    }
  }
  //Print mst
  printf("\nPrinting MST:\nSrc\tDest\tWeight\n");
  for (i = 0; i < mstIndex; i++)
    printf(" %d  ---> %d   :    %d\n", mst[i].src, mst[i].dest, mst[i].wt);
}


//Driver method
int main(){
  int v,e;
  printf("Enter the number of vertices and edges : ");
  scanf("%d %d", &v, &e);

  struct Edge *edgeList = (struct Edge*)malloc(sizeof(struct Edge)*e);
  printf("\nEnter the edge list in the format:\nSrc\tDest\tWeight\n");

  for (int i = 0; i < e; i++){
    scanf("%d%d%d", &edgeList[i].src, &edgeList[i].dest, &edgeList[i].wt);
  }

  kruskal(edgeList, v, e);
  return 0;
}
