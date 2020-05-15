/**
 * @Author: hardcodecoder
 * @Date:   02:10:35 Friday 15 May 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 03:01:57 Friday 15 May 2020
 */


import java.io.*;
import java.util.Scanner;

public class BellmanFordShortestPath {

  // Defines  distance for unreachable vertex
  private static final float INF = 99999;

  // Stores the final shortest distances from source to every other vertex
  // Index represent the vertex no. from source and the value gives the distance
  private float[] shortestDistanceFromSource;

  // Stores the ancesstor to the current vertex
  // Index gives the current vertex no. & value gives the ancesstor vertex no.
  private int[] precedingVertex;

  // main method
  public static void main(String args[]) {
    new BellmanFordShortestPath().initialize();
  }

  // Helper method to input data and initialize necessary variables
  private void initialize() {
    int numVertex, numEdges, mSrc, mDest;

    System.out.println("Enter the number of vertices and edges in the graph: ");
    Scanner sc = new Scanner(System.in);
    numVertex = sc.nextInt();
    numEdges = sc.nextInt();

    // Initialize all necessary variables
    Edge[] edgeList = new Edge[numEdges];
    precedingVertex = new int[numVertex];
    shortestDistanceFromSource = new float[numVertex];

    // Input the edges
    System.out.println("Enter the edge list in the format:\nSrc vertex\tDest vertex\tWt");
    for (int i = 0; i < numEdges; i++){
      int src = sc.nextInt();
      int dest = sc.nextInt();
      float wt = sc.nextFloat();
      edgeList[i] = new Edge(src, dest, wt);
    }

    // Input the source and destination vertex no.
    System.out.print("Enter the source and destination vertex: ");
    mSrc = sc.nextInt();
    mDest = sc.nextInt();

    findShortestpath(numVertex, numEdges, edgeList, mSrc, mDest);
  }

  // Implementation of Bellman-Ford algorithm
  private void findShortestpath(int numVertex, int numEdges, Edge[] edgeList, int source, int destination) {
    // Initialise distance of all vertex from source as Infinity
    for (int i = 0; i < numVertex; i++)
      shortestDistanceFromSource[i] = INF;

    // Set distance of source from source to zero
    shortestDistanceFromSource[source] = 0.0f;

    // Relax all edges for |numVertex -1| times
    for (int i = 0; i < numVertex; i++) {
      for (int j = 0; j < numEdges; j++) {
        // Get data of current edge
        int src = edgeList[j].getSourceVertex();
        int dest = edgeList[j].getDestinationVertex();
        float wt = edgeList[j].getWeight();

        if (shortestDistanceFromSource[src] != INF && shortestDistanceFromSource[src] + wt < shortestDistanceFromSource[dest]) {
          // Distance to 'dest' vertex via 'src' sourtex is better
          shortestDistanceFromSource[dest] = shortestDistanceFromSource[src] + wt;
          precedingVertex[dest] = src;
        }
      }
    }

    // Relax all the edges for one more time
    // to detect presence of negative cycle
    for (int i = 0; i < numEdges; i++) {
      int src = edgeList[i].getSourceVertex();
      int dest = edgeList[i].getDestinationVertex();
      float wt = edgeList[i].getWeight();

      if (shortestDistanceFromSource[src] != INF && shortestDistanceFromSource[src] + wt < shortestDistanceFromSource[dest]) {
        // Negative cycle detected exit
        // without printing shortest path
        System.out.println("Negative cycle detected. Exiting...");
        return;
      }
    }

    print(numVertex, source, destination);
  }

  // Helper method to print the output
  private void print(int numVertex, int src, int dest){
    // Uncomment to print distances of all vertex from source
    /*System.out.println("Shortest distances:\nVertex\tDistance from source\n");
    for (int i = 0; i < numVertex; i++) {
      float d = shortestDistanceFromSource[i];
      if (d < 0)
        System.out.println(String.format("%d\t\t%.1f", i, d));
      else
        System.out.println(String.format("%d\t\t+%.1f", i, d));
    }*/

    // prints the shortest distance
    System.out.print(String.format("Shortest distance from %d to %d: %.2f\nPath: ", src, dest, shortestDistanceFromSource[dest]));
    System.out.println(printPath(src, dest));
  }

  // Method to print the path from source to the destination vertex recursively
  private int printPath(int src, int dest) {
    if (src == dest) return src;
    System.out.print(String.format("%d -- > ", printPath(src, precedingVertex[dest])));
    return dest;
  }

  // Edge object class
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
}
