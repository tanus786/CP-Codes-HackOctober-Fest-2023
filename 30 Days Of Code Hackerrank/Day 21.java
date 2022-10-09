import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;



public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        String[] aTemp = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        List<Integer> a = new ArrayList<>();
        int b[]=new int[n];
        for (int i = 0; i < n; i++) {
            int aItem = Integer.parseInt(aTemp[i]);
            a.add(aItem);
            b[i]=aItem;
        }
        int s=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-1-i;j++)
            {
                if(b[j]>b[j+1])
                {
                    s++;
                    int d=b[j];
                    b[j]=b[j+1];
                    b[j+1]=d;
                }
            }
        }
        System.out.println("Array is sorted in "+s+" swaps.");
        System.out.println("First Element: "+b[0]);
        System.out.println("Last Element: "+b[n-1]);
        bufferedReader.close();
    }
}