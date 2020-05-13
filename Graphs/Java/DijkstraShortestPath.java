/**
* @Author: hardcodecoder
* @Date:   04:45:44 Wednesday 13 May 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 07:11:42 Wednesday 13 May 2020
*/


import java.io.*;
import java.util.Scanner;

public class DijkstraShortestPath {
  

  // Defines infinity for vertices which is not adjacent
  private static final int INF = 9999;

  // Stores the initial distances for each pair of vertices
  private int[][] distanceMatrix;

  // Helper arrray whose index is the vertex number
  // and value gives the ancesstor vertex in MST
  private int[] previousVertex;

  // Index is the vertex no. and value is the shortest distance from source
  private int[] shortestDistance;

  // Marks visited vertices
  private boolean[] visited;

  public static void main(String args[]) {
    new DijkstraShortestPath().initialise();
  }

  // Helper method to input data and initialise variables
  private void initialise() {
    int numVertex, src, dest;

    System.out.print("Enter the number of vertices: ");
    Scanner sc = new Scanner(System.in);
    numVertex = sc.nextInt();

    distanceMatrix = new int[numVertex][numVertex];
    previousVertex = new int[numVertex];
    shortestDistance = new int[numVertex];
    visited = new boolean[numVertex];

    System.out.println("Enter the distances for each vertex (Enter 0 for unreachable vertex and same vertex)");
    for (int i = 0; i < numVertex; i++){
      for (int j = 0; j < numVertex; j++)
        distanceMatrix[i][j] = sc.nextInt();

    }

    System.out.print("\nEnter the source and destination vertex: ");
    src = sc.nextInt();
    dest = sc.nextInt();

    findShortestPath(numVertex, src, dest);
  }

  // Dijkstra's algorithm implementation to find MST from source to all vertex
  private void findShortestPath(int numVertex, int src, int dest) {
    for (int i = 0; i < numVertex; i++) {
      shortestDistance[i] = INF;
      visited[i] = false;
    }

    shortestDistance[src] = 0;

    for (int i = 0; i < numVertex-1; i++){
      int min = getNearestVertex(numVertex);
      visited[min] = true;

      for (int v = 0; v < numVertex; v++) {
        if (!visited[v]
          && distanceMatrix[min][v] != 0
          && shortestDistance[min] != INF
          && shortestDistance[min] + distanceMatrix[min][v] < shortestDistance[v]) {

          shortestDistance[v] = shortestDistance[min] + distanceMatrix[min][v];
          previousVertex[v] = min;
        }
      }
    }
    print(numVertex, src, dest);
  }

  // returns the nearest unvisited vertex
  private int getNearestVertex(int numVertex) {
    int min = INF;
    int minIndex = -1;
    for (int v = 0; v < numVertex; v++){
      if (!visited[v] && shortestDistance[v] <= min){
        min = shortestDistance[v];
        minIndex = v;
      }
    }
    return minIndex;
  }

  // Print helper method
  private void print(int numVertex, int src, int dest) {
    // Uncomment to print distances of all vertex from source
    /*System.out.println("Vertex\tDistance from source");
    for (int i = 0; i < numVertex; i++)
      System.out.println("" + i + "\t\t" + shortestDistance[i]);*/

    System.out.println(String.format("Shortest distance between %d -> %d = %d", src, dest, shortestDistance[dest]));
    System.out.print("Path: ");
    System.out.println(printPath(src, dest));
  }

  // Recursively backtracks and prints path from src to dest
  private int printPath(int src, int dest) {
    if (src == dest) return src;
    System.out.print(String.format("%d --> ", printPath(src, previousVertex[dest])));
    return dest;
  }
}
