import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int test=sc.nextInt();
        int i, j, min, cMax, vMax, c1, c2;
        String s;
        int vCount, cCount;
        for(i=1; i<=test; i++){
            min= Integer.MIN_VALUE;
            cCount=0; vCount=0;
            int[] arr=new int[26];
            s=sc.next();
            int length=s.length();
            for(j=0; j<length; j++){
                int ch=s.charAt(j);
                arr[ch%65]++;
                switch(s.charAt(j)){
                    case 'A': case 'E': case 'I': case 'O': case 'U': vCount++;
                    break;
                    default:cCount++;
                }
            }
            cMax=arr[1];
            vMax=arr[0];
            for(j=0; j<26; j++) {
                    if(j==0 || j==4 || j==8 || j==14 || j==20){
                        if(arr[j]>vMax)
                            vMax=arr[j];
                    }
                    else if(arr[j]>cMax)
                        cMax=arr[j];
                    if(min<arr[j])
                        min=arr[j];
                //System.out.println(arr[j]);
            }
            c1=((vCount-vMax)*2)+cCount;
            c2=((cCount-cMax)*2)+vCount;
            if(c1<c2)
                System.out.println("Case #"+i+": "+c1);
            else
                System.out.println("Case #"+i+": "+c2);
        }

    }
}
