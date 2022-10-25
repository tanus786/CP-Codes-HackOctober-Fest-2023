import java.util.*;
public class Main {
  public static int findminflips(char[] str, int n, int k) {
    int flips = 0;
    for (int i = 0; i < n - k; i++) {
      boolean flag = false;
      for (int j = 0; j < k; j++) {
        if (str[i + j] == '1')
          flag = true;
      }
      if (flag == false)
      {
        str[i + k - 1] = '1';
        flips++;
      }
    }
    return flips;
  }
  public static void main(String args[]) {
    String str = "0100001";
    int n = 7;
    int k = 3;
    System.out.println(findminflips(str.toCharArray(), n, k));
  }
}
