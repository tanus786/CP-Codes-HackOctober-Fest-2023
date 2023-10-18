

public class Bubble {
    public static void main(String[] args) {
        int []arr = {4,5,1,2,3};
        int n = arr.length;
        for(int i = 0;i<n-1;i++)
        {
            for(int j = 0;j<n-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    arr[j] = arr[j]^arr[j+1];
                    arr[j+1]=arr[j]^arr[j+1];
                    arr[j] = arr[j]^arr[j+1];
                }
            }
        }
        for(int xx:arr)
        {
            System.out.print(xx+" ");
        }
    }
}
