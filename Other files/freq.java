import java.util.* ;
class Freq
{
public static void main(String[] args)
    {
int l,i,flag=0;
Scanner sc= new Scanner(System.in);
System.out.print("enter the string");
String str = sc.nextLine();
l=str.length();
for(i=0;i<l/2;i++)
          {
if (str.charAt(i) == str.charAt(l-i-1) )
              {
flag = 1;
break ;
              }
          }
if (flag==1)
System.out.println("string is palindrome");
else
System.out.print("string not palindrome");
    }
}
