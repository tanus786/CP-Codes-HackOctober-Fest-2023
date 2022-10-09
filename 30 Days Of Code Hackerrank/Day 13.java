import java.util.*;

class Person {
	protected String firstName;
	protected String lastName;
	protected int idNumber;
	
	// Constructor
	Person(String firstName, String lastName, int identification){
		this.firstName = firstName;
		this.lastName = lastName;
		this.idNumber = identification;
	}
	
	// Print person data
	public void printPerson(){
		 System.out.println(
				"Name: " + lastName + ", " + firstName 
			+ 	"\nID: " + idNumber); 
	}
	 
}

class Student extends Person{
	private int[] a;
    Student(String f , String l , int id , int a[])
    {
        super(f,l,id);
        this.a=a;
    }
    public void printPerson()
    {
        super.printPerson();
    }
    public String calculate()
    {
        int s=0;
        int k=a.length;
        for(int i=0;i<k;i++)
        {
            s=s+a[i];
        }
        s=s/k;
        if(s>=90&&s<=100)
        {
            return "O";
        }
        else if(s>=80&&s<90)
        {
            return "E";
        }
        else if(s>=70&&s<80)
        {
            return "A";
        }
        else if(s>=55&&s<70)
        {
            return "P";
        }
        else if(s>=40&&s<55)
        {
            return "D";
        }
        else
        {
            return "T";
        }
    }
}

class Solution {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String firstName = scan.next();
		String lastName = scan.next();
		int id = scan.nextInt();
		int numScores = scan.nextInt();
		int[] testScores = new int[numScores];
		for(int i = 0; i < numScores; i++){
			testScores[i] = scan.nextInt();
		}
		scan.close();
		
		Student s = new Student(firstName, lastName, id, testScores);
		s.printPerson();
		System.out.println("Grade: " + s.calculate());
	}
}