

public class InsertionSort {
    public static void main(String[] args) {
        int []arr = {4,5,1,2,3};
        int n = arr.length;
        for(int i = 1;i<n;i++)
        {
           int temp = arr[i];
           int j = i-1;
           for(;j>=0;j--)
           {
            if(arr[j]>temp)
            {
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
           }
           arr[j+1] = temp;
        }
        for(int xx:arr)
        {
            System.out.print(xx+" ");
        }
    }
}
