/**
 * @Author: hardcodecoder
 * @Date:   02:31:00 Sunday 17 May 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 03:07:32 Sunday 17 May 2020
 */

import java.io.*;
import java.util.Scanner;

public class DepthFirstTraversal {

  private int[][] adjacencyMatrix;
  private int numVertex;
  private boolean[] visited;

  // Main method
  public static void main(String args[]) {
    new DepthFirstTraversal().initialize();
  }

  // Helper method to input data and
  // initialize required variables
  private void initialize() {
    System.out.print("Enter the number of vertices: ");
    Scanner sc = new Scanner(System.in);
    numVertex = sc.nextInt();

    adjacencyMatrix = new int[numVertex][numVertex];
    visited = new boolean[numVertex];

    System.out.println("Enter the adjacency matrix: (1 if adjacent else 0)");
    for (int i = 0; i < numVertex; i++) {
      for (int j = 0; j < numVertex; j++) {
        adjacencyMatrix[i][j] = sc.nextInt();
      }
    }

    System.out.print("Enter the source vertex: ");
    int src = sc.nextInt();

    // Mark all vertices as unvisited
    for (int i = 0; i < numVertex; i++)
      visited[i] = false;

    System.out.print("Depth first traversal: ");
    depthFirstTraversal(src);
    System.out.println();
  }

  private void depthFirstTraversal(int vertex) {
    // Print the visited vertex
    System.out.print(vertex + ", ");

    // Mark the visted vertex
    visited[vertex] = true;

    // For all adjacent vertex 'i' of 'vertex'
    // perform depth first traversal recursively
    for (int i = 0; i < numVertex; i++) {
      int adj = adjacencyMatrix[vertex][i];
      if (adj == 1 && !visited[i])
        depthFirstTraversal(i);
    }
  }
}
