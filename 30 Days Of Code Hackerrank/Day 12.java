import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the hourglassSum function below.
    static int hourglassSum(int[][] arr) {
        int a[]=new int[16];
        int i,j,k,k1,m=0,s;
        for(i=0;i<6-2;i++)
        {
            for(j=0;j<6-2;j++)
            {
                s=0;
                if(i==j)
                {
                   for(k=i;k<(i+3);k++)
                   {
                       s=s+arr[k][k];
                   }
                   for(k=i,k1=j+2;k<(i+3);k++,k1--)
                   {
                       s=s+arr[k][k1];
                   }
                   s=s-arr[i+1][i+1]; 
                   s=s+arr[i][i+1];
                   s=s+arr[i+2][i+1];
                }
                else if(i<j)
                {
                   for(k=i,k1=j;k<(i+3);k++,k1++)
                   {
                       s=s+arr[k][k1];
                   }
                   for(k=i,k1=j+2;k<(i+3);k++,k1--)
                   {
                       s=s+arr[k][k1];
                   }
                   s=s-arr[i+1][j+1]; 
                   s=s+arr[i][j+1];
                   s=s+arr[i+2][j+1];
                }
                else if(i>j)
                {
                    for(k=i,k1=j;k<(i+3);k++,k1++)
                   {
                       s=s+arr[k][k1];
                   }
                   for(k=i,k1=j+2;k<(i+3);k++,k1--)
                   {
                       s=s+arr[k][k1];
                   }
                   s=s-arr[i+1][j+1]; 
                   s=s+arr[i][j+1];
                   s=s+arr[i+2][j+1];
                }
                a[m++]=s;
            }
        }
            Arrays.sort(a);
            return a[a.length-1];
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }

        int result = hourglassSum(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
