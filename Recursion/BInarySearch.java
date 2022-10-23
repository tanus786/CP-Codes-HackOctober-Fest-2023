public class BInarySearch {

    public static void main(String[] args) {
        int[]arr={1,2,3,4,5,6,7,8,9};
        System.out.println(BS(arr,9,0,arr.length-1));
    }

    static int BS(int[]arr, int t, int s, int e)
    {
        if (s>e) return -1;
        int m=s+(e-s)/2;

        if (arr[m]>t) return BS(arr,t,s,m-1);
        else if(arr[m]==t) return m;

        return BS(arr,t,m+1,e);
    }
}
