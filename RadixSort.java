import java.util.*;

public class RadixSort {
    public static void radixSort( int[] array)
    {
        int m = array[0];
        int exp = 1;
        int len=array.length;
        int[] b = new int[len];
        
        for (int i = 1; i < len; i++)
            if (array[i] > m)
                m = array[i];
        
        while (m / exp > 0)
        {
            int[] bucket = new int[10];

            for (int i = 0; i < len; i++)
                bucket[(array[i] / exp) % 10]++;
            for (int i = 1; i < 10; i++)
                bucket[i] += bucket[i - 1];
            for (int i = len - 1; i >= 0; i--)
                b[--bucket[(array[i] / exp) % 10]] = array[i];
            for (int i = 0; i < len; i++)
                array[i] = b[i];
            exp *= 10;        
        }
    }
  
    public static void main(String[] args) {
      Scanner sc=new Scanner(System.in);
      
      int sizeOfArray;
      int input[];
      
      sizeOfArray=sc.nextInt();
      input=new int[sizeOfArray];
      
      for(int i=0; i<sizeOfArray; i++){
        input[i]=sc.nextInt();
      }
      
      System.out.print("Array elements before sorting: ");
      for(int x:input)
        System.out.print(x+" ");
      
      radixSort(input);
      
      System.out.print("\nArray elements after sorting: ");
      for(int x:input)
        System.out.print(x+" ");
  }
}