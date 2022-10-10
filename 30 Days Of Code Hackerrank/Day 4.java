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
        String k=n%2==1||(n%2==0&&n>=6&&n<=20) ? "Weird" : "Not Weird";
        System.out.println(k);
        bufferedReader.close();
    }
}