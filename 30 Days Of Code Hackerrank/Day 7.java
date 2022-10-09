import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc=new Scanner(System.in);
        String s,p="",p1="";
        int i,l,n,j;
        char c;
        n=sc.nextInt();
        for(j=1;j<=n;j++)
        {
            s=sc.next();
            l=s.length();
            char c1[]=new char[l];
            for(i=0;i<l;i++)
            {
                c=s.charAt(i);
                c1[i]=c;
            }
            for(i=0;i<l;i++)
            {
                if(i%2==0)
                {
                    p=p+c1[i];
                }
                else
                {
                    p1=p1+c1[i];
                }
            }
            System.out.println(p+ " " +p1);
            p="";
            p1="";
        }
    }
}