import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        while(n-- > 0)
        {
            int a=sc.nextInt();
            if(a==1)
            {
                System.out.println("Not prime");
            }
            else if(a==2)
            {
                System.out.println("Prime");
            }
            else
            {
                int c=0;
                for(int i=2;i<=(int)Math.sqrt(a);i++)
                {
                    if(a%i==0)
                    {
                        c++;
                        break;
                    }
                }
                if(c==0)
                {
                    System.out.println("Prime");
                }
                else
                {
                    System.out.println("Not prime");
                }
            }
        }
    }
}
