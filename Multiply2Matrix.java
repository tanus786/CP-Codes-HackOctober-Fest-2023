package testcode;

import java.util.Scanner;

public class Multiply2Matrix {
	public static void main(String[] args)
	   {
	      int i, j, k, sum=0;
	      int[][] firstMatrix = new int[3][3];
	      int[][] secondMatrix = new int[3][3];
	      int[][] resultMatrix = new int[3][3];
	      Scanner scan = new Scanner(System.in);
	      
	      System.out.print("Enter elements of First Matrix: ");
	      for(i=0; i<3; i++)
	      {
	         for(j=0; j<3; j++)
	         {
	            firstMatrix[i][j] = scan.nextInt();
	         }
	      }
	      System.out.print("Enter elements of Second Matrix: ");
	      for(i=0; i<3; i++)
	      {
	         for(j=0; j<3; j++)
	         {
	            secondMatrix[i][j] = scan.nextInt();
	         }
	      }
	      
	      // multiplying the two matrices
	      for(i=0; i<3; i++)
	      {
	         for(j=0; j<3; j++)
	         {
	            sum = 0;
	            for(k=0; k<3; k++)
	            {
	               sum = sum + (firstMatrix[i][k] * secondMatrix[k][j]);
	            }
	            resultMatrix[i][j] = sum;
	         }
	      }
	      
	      System.out.println("Result is:");
	      for(i=0; i<3; i++)
	      {
	         for(j=0; j<3; j++)
	         {
	            System.out.print(resultMatrix[i][j]+ "  ");
	         }
	         System.out.print("\n");
	      }
	   }
}
