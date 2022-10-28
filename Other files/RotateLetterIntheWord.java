package testcode;

import java.util.Scanner;

public class RotateLetterIntheWord {
	public static void main(String args[]) {
		// Create scanner object
		Scanner scanner = new Scanner(System.in);
		try {
			System.out.println("Enter the word:");
			// Read the word using scanner and store it in to the variable 'word'
			String word = scanner.nextLine();
			System.out.println("Enter the number of position you want to rotate:");
			// Read the number of positions to variable rotatePositionCount
			int rotatePositionCount = scanner.nextInt();
			//Create a new array with the letters in the word, by using split function
			String[] letters = word.split("");
			//Rotate letters rotatePositionCount times
			for(int i=0;i<rotatePositionCount;i++) {
				//Rotate a letter left side and assigned to the variable 'letter'
				letters=rotateOnes(letters);
			}
			//Print the rotated String
			System.out.println("Rotated String: "+String.join("", letters));

		} catch (Exception e) {
			System.out.println(e.getMessage());
		}

	}
	
	static String[] rotateOnes(String[] wordArray) {
		//This function is used to rotate string array letters position 1 digit left
		//Store the first letter in a variable 'firstLetter'
		String firstLetter=wordArray[0];
		for (int i = 0; i < wordArray.length-1; i++) {
			//Shift element of array 
			wordArray[i]=wordArray[i+1];
		}
		//First element of array update
		wordArray[wordArray.length-1]=firstLetter;
		//rotated string array will be in the variable 'wordArray'
		return wordArray;
	}
}
