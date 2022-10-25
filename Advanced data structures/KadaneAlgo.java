public class KadaneAlgo{
    public static void main(String[] args) {
        int arr[]= {1,2,3,-2,5};
        int max_so_far=0;
        int max_end_here=0;
        for(int i=0;i<arr.length;i++){
            max_end_here+=arr[i];
            
            if(max_so_far<max_end_here){
                max_so_far=max_end_here;
            }
            if(max_end_here<0){
                max_end_here=0;
            }
        }

        System.out.println("maxmimun subarray sum"+max_so_far);
    }
}