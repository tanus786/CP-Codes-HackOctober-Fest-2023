import java.util.*;
import java.lang.*;
import static java.lang.Integer.MIN_VALUE;

public class Pb1 {
    public static void main(String [] args){

        Scanner sc = new Scanner(System.in);
        int [] arr = {1,3,5,7,8,9};
        sMax(arr);
    }
    static int sum(int []arr){
        int sum=0;
        for (int i:arr)
            sum = sum+i;
        return sum;
    }
    static void Search(int []arr,int key) {
        int i;
        for (i=0; i< arr.length;i++){
            if (arr[i] == key) {
                System.out.println("Key is found at index :" + i);
                System.exit(0);
            }
        }
        System.out.println("Key is not found!!!");
    }

    static void max(int []arr){
        int mx=MIN_VALUE;
        for (int i:arr) {
            if (i > mx){
                mx=i;
            }
        }
        System.out.println(mx);
    }

    static void sMax(int []a){
        int max2;
        int max1=max2=a[0];
        for(int i=0; i<a.length; i++){
            if(a[i]>max1){
                max2=max1;
                max1=a[i];
            }
            else if (a[i]>max2){
                max2=a[i];
            }
        }
        System.out.println("Second largest element is:"+max2);

    }
}
