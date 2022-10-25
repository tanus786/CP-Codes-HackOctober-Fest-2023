import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class GoodBadString {
    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(bf.readLine());
        for(int i=0;i<t;i++){
           String str  = bf.readLine();
           String temp="";
           for(int j=0;j<str.length();j++){
                if(j==0 || temp.charAt(temp.length()-1)!=str.charAt(j)){
                    temp+=str.charAt(j);
                }
           }
           System.out.println(temp);
        }   
        
