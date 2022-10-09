import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;



public class Solution {
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        List<String> nm=new ArrayList();
        for(int i=1;i<=n;i++)
        {
            String s=sc.next();
            String f=sc.next();
            if(f.contains("@gmail.com"))
            {
                nm.add(s);
            }
        }
        Collections.sort(nm);
        n=nm.size();
        for(int i=0;i<n;i++)
        {
            System.out.println(nm.get(i));
        }
    }
}
