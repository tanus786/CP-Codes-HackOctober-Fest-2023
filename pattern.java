import java.util.*;
public class pattern{
public static void main(String args[]){
/*solid rectangle 
		int n=4;
		int m=5;
		for(int i=1; i<=n; i++){
				for(int j=1; j<=m; j++){
					System.out.print("*");
				}
		System.out.println();	
		}*/
		
		/*hollow rectangle rows(i)=outer loops     column(j)=inner loops
		int n=4;
		int m=5;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				//cell(i,j)
				if(i==1||j==1||i==n||j==m){
					System.out.print("*");
				}
				else{
					System.out.print(" ");
				}
			}
			System.out.println();
		}*/
		
		
		/*half pyramid
		int n=4;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=i; j++){
					System.out.print("*");
			}
			System.out.println();
		}*/
		
		
		/*inverted half reverse pyramid
		int n=4;
		for(int i=n; i>=1; i--){
			for(int j=1; j<=i; j++){
					System.out.print("*");
			}
			System.out.println();
		}*/
		
		/*inverted half reverse pyramid with rotated by 180 degree..
		int n=4;
		for(int i=1; i<=n; i++){
			//inner loop = space print..
			for(int j=1; j<=n-i; j++){
				System.out.print(" ");
			}
			//inner loop =star print
			for(int j=1; j<=i; j++){
				System.out.print("*");
			}
			System.out.println();
		}*/
		
		/*pyramid with rotated by 180 degree..
		int n=4;
		for(int i=n; i>=1; i--){
			//inner loop = space print..
			for(int j=1; j<=n-i; j++){
				System.out.print(" ");
			}
			//inner loop =star print
			for(int j=1; j<=i; j++){
				System.out.print("*");
			}
			System.out.println();
		}*/
		
		/*half pyramid with numbers
		int n=5;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=i; j++){
					System.out.print(j+ " ");
			}
			System.out.println();
		}*/
		
		
		/*inverted half pyramid with numbers
		int n=5;
		for(int i=n; i>=1; i--){
			for(int j=1; j<=i; j++){
					System.out.print(j+ " ");
			}
			System.out.println();
		}*/
		
		
		/*floyd's triangle
		int n=5;
		int number=1;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=i; j++){
					System.out.print(number + " ");
					number ++ ;//number = number +1
			}
			System.out.println();
		}*/
		
		/*0-1 triangle
		int n=5;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=i; j++){
				int sum=i+j;
				if(sum%2==0) //even 
					System.out.print("1"+ " ");
				else{ //odd
					System.out.print("0"+ " ");
				}
			}
			System.out.println();
		}*/
		
		
		//1-0 triangle
		int n=5;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=i; j++){
				int sum=i+j;
				if(sum%2==0) //even 
					System.out.print("0"+ " ");
				else{ //odd
					System.out.print("1"+ " ");
				}
			}
			System.out.println();
		}
		
		
		
		
	}
}


