import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a,b,c,d,e,f;
        a=sc.nextInt();
        b=sc.nextInt();
        c=sc.nextInt();
        d=sc.nextInt();
        e=sc.nextInt();
        f=sc.nextInt();
        if(c>f)
        {
            System.out.println(10000);
        }
        else if((b>e) && (c==f))
        {
            System.out.println((b-e)*500);
        }
        else if((a>d) && (b==e) && (c==f))
        {
            System.out.println((a-d)*15);
        }
        else
        {
            System.out.println(0);
        }
    }
}