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
        String k=Integer.toBinaryString(n);
        int f=k.length(),c=0,m=0;
        for(int i=0;i<f;i++)
        {
            if(k.charAt(i)=='0')
            {
                c=Math.max(m,c);
                m=0;
            }
            else
            {
                m++;
            }
        }
        c=Math.max(c,m);
        System.out.println(c);
        bufferedReader.close();
    }
}
