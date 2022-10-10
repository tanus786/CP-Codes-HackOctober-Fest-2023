import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        HashMap<String,Integer> nm=new HashMap<>();
        for(int i = 0; i < n; i++){
            String na = in.next();
            int p = in.nextInt();
            nm.put(na,p);
        }
        while(in.hasNext()){
            String s = in.next();
            if(nm.containsKey(s))
            {
                System.out.println(s+"="+nm.get(s));
            }
            else
            {
                System.out.println("Not found");
            }
        }
        in.close();
    }
}