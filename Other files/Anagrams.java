import java.util.*;

public class HR_anagrams {

    static boolean isAnagram(String a, String b) {
       
        String str1 = a;
        String str2 = b;

        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        
        if(str1.length() == str2.length()) {

          
            char[] charArray1 = str1.toCharArray();
            char[] charArray2 = str2.toCharArray();

          
            Arrays.sort(charArray1);
            Arrays.sort(charArray2);

           
            return Arrays.equals(charArray1, charArray2);

        }
        else
        {
            return false;
        }
    }
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
