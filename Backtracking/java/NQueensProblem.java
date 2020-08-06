/**
 * @Author: hardcodecoder
 * @Date:   03:44:16 Thursday 06 August 2020
 * @Last modified by:   hardcodecoder
 * @Last modified time: 04:34:53 Thursday 06 August 2020
 */

 import java.io.*;
 import java.util.Scanner;

public class NQueensProblem {

  // Board to place the queen
  private static int[][] mBoard;
  // Arry to mark occpied position in left diagnol
  private static int[] mLeftDiagnol;
  // Array to mark occupied position in right diagnol
  private static int[] mRightDiagnol;
  // Array to mark occupied rows
  private static int[] mRows;
  // Total number of queens to place
  private static int mNumQueens;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter the number of queens to place: ");
    mNumQueens = sc.nextInt();

    // Initialize the arrays
    mBoard = new int[mNumQueens][mNumQueens];
    mLeftDiagnol = new int[2*mNumQueens];
    mRightDiagnol = new int[2*mNumQueens];
    mRows = new int[mNumQueens];

    boolean result = placeQueen(0);
    if (result)
        // Solution is found print the board
        printBoard();
    else
        // Solution is not found
        System.out.println("Solution does not exists");
  }

  private static boolean placeQueen(int col) {
    // Base case
    // All queens has been placed
    if (col >= mNumQueens)
        return true;
    // Check if queen can be placed in any row in column: col
    for (int row = 0; row < mNumQueens; row++) {
      // Check if the queen can be placed in position [row][col]
      if (isSafe(row, col)) {
        // Place queen at [row][col]
        markPositionAsOccupied(row, col, true);

        // Recursively place queens in the next column
        if (placeQueen(col + 1))
            return true;

        // Queen cannot be placed any furthur
        // Backtrack from here
        // Mark this location empty
        markPositionAsOccupied(row, col, false);
      }
    }
    // Cannot place queen in any row for column: col
    return false;
  }

  // Helper method to check if a given position is safe to put queen
  private static boolean isSafe(int row, int col) {
    return mLeftDiagnol[row - col + mNumQueens - 1] != 1 &&
           mRightDiagnol[row + col] != 1 &&
           mRows[row] != 1;
  }

  // Helper method to mark/ unmark a given position
  private static void markPositionAsOccupied(int row, int col, boolean mark) {
    mBoard[row][col] = mLeftDiagnol[row - col + mNumQueens - 1] = mRightDiagnol[row + col] = mRows[row] = mark ? 1:0;
  }

  // Utility method to print the board if solution is found
  private static void printBoard() {
    for (int row = 0; row < mNumQueens; row++) {
      String line = "";
      for (int col = 0; col < mNumQueens; col++) {
        if (mBoard[row][col] == 0)
            line += " _ ";
        else
            line += " Q ";
      }
      System.out.println(line);
    }
  }
}
