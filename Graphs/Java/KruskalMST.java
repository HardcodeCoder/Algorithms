/**
 * @Author: hardcodecoder
 * @Date:   01:55:01 Wednesday 13 May 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 04:43:41 Wednesday 13 May 2020
 */

import java.io.*;
import java.util.Scanner;

public class KruskalMST {

  private Edge[] edgeList;
  private Subset[] subsetList;

  // Driver method
  public static void main(String args[]) {
    new KruskalMST().initialise();
  }

  // Method to take input and initialise required variables
  private void initialise(){
    int numVertex, numEdges;

    System.out.print("Enter the number of vertices and edges in the graph: ");
    Scanner sc = new Scanner(System.in);
    numVertex = sc.nextInt();
    numEdges = sc.nextInt();

    edgeList = new Edge[numEdges];
    subsetList = new Subset[numVertex];

    System.out.println("Enter the data for each edge:\nSourceVertex\tDestinationVertex\tWeight ");
    for (int i = 0; i < numEdges; i++){
      int src = sc.nextInt();
      int dest = sc.nextInt();
      float weight = sc.nextFloat();
      edgeList[i] = new Edge(src, dest, weight);
    }

    for (int i = 0; i < numVertex; i++){
      Subset subset = new Subset();
      subset.setRootVertex(i);
      subset.setSize(1);
      subsetList[i] = subset;
    }
    findMst(numVertex, numEdges);
  }

  // Helper find MSt using kruskal's algorithm
  private void findMst(int numVertex, int numEdges){
    int i = 0, maxVertexCount = 0;
    Edge[] mstEdgeList = new Edge[numVertex];

    sortEdgeList();

    while (maxVertexCount < numVertex-1 && i < numEdges) {
      Edge edge = edgeList[i++];
      int x = findRootVertex(edge.getSourceVertex());
      int y = findRootVertex(edge.getDestinationVertex());

      if (x != y) {
        mstEdgeList[maxVertexCount++] = edge;
        unionFind(x, y);
      }
    }
    System.out.println("Edges in the Minimum spanning tree:\nSourceVertex\tDestinationVertex\tWeight");
    for (i = 0; i < maxVertexCount; i++){
      Edge edge = mstEdgeList[i];
      System.out.println("" + edge.getSourceVertex() + "\t\t" + edge.getDestinationVertex() + "\t\t" + edge.getWeight());
    }
  }

  // Sorts the edgeList based on weight in ascending order
  private void sortEdgeList() {
    for (int i = 0; i < edgeList.length; i++){
      int min = i;
      for (int j = i+1; j < edgeList.length; j++) {
        if (edgeList[i].getWeight() < edgeList[min].getWeight())
          min = j;
      }
      Edge temp = edgeList[i];
      edgeList[i] = edgeList[min];
      edgeList[min] = temp;
    }
  }

  // Finds the root vertex of a given vertex 'x' (Uses Path-compressesion method)
  private int findRootVertex(int vertex) {
    Subset subset = subsetList[vertex];
    if (subset.getRootVertex() != vertex)
      subset.setRootVertex(findRootVertex(subset.getRootVertex())); //Recursively find and compressess path to the root vertex
    return subset.getRootVertex();
  }

  // Unifies two subsets, smaller subset get's merged into large subset
  private void unionFind(int x, int y) {
    int xRoot = findRootVertex(x);
    int yRoot = findRootVertex(y);

    Subset xSubset = subsetList[xRoot];
    Subset ySubset = subsetList[yRoot];

    if (xSubset.getSize() > ySubset.getSize())
      ySubset.setRootVertex(xRoot);
    else if (xSubset.getSize() < ySubset.getSize())
      xSubset.setRootVertex(yRoot);
    else {
      ySubset.setRootVertex(xRoot);
      xSubset.setSize(xSubset.getSize()+1);
    }
  }

  // Object for each edge
  private static class Edge {

    private int sourceVertex, destinationVertex;
    private float weight;

    Edge(int sourceVertex, int destinationVertex, float weight){
      this.sourceVertex = sourceVertex;
      this.destinationVertex = destinationVertex;
      this.weight = weight;
    }

    int getSourceVertex(){
      return sourceVertex;
    }

    int getDestinationVertex(){
      return destinationVertex;
    }

    float getWeight(){
      return weight;
    }
  }

  // Object to track subset
  private static class Subset {

    private int size, rootVertex;

    void setRootVertex(int vertex) {
      this.rootVertex = vertex;
    }

    int getRootVertex(){
      return rootVertex;
    }

    void setSize(int size){
      this.size = size;
    }

    int getSize(){
      return size;
    }
  }
}
