import java.util.*;
public class DistinctNumber
{
  public static void main(String[]args)
  {
       Scanner sc= new Scanner(System.in);
        int n= sc.nextInt();
        int []a= new int[n];
       for(int i=0;i<n;i++)
         {
           a[i]=sc.nextInt();
         }
       HashSet<Integer> h= new HashSet<Integer>();
        for(int j=0;j<n;j++)
          {
             h.add(a[j];
           }
          System.out.println(h.size());
               
               
               
    }
  }
