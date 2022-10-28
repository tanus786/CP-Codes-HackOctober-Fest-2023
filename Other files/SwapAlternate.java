public class SwapAlternate {
    public static void main(String[] args) {
        int[] even = {1,2,3,4,5,6};
        int[] odd = {10,20,30,40,50};
        swapAlternate(odd,5);
        PrintArray(odd , 5);
    }

    static void swapAlternate(int arr[] , int size){
        for(int i = 0;i<size ; i+=2) {
            if(i+1 < size){
                int temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
            }
        }
    static void PrintArray(int arr[] , int n ){
        for(int i = 0 ;i<n;i++){
            System.out.println(arr[i] + " ");
    }
    }
}
