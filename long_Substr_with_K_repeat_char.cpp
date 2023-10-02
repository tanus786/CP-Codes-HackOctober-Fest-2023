#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestSubstring(string s, int k) {
    int n = s.length();
    
    if (n == 0 || k > n) {
        return 0;
    }
    
    if (k == 1) {
        return n;
    }
    
    // Create an array to count the occurrences of each character in the string.
    vector<int> charCount(26, 0);
    for (char c : s) {
        charCount[c - 'a']++;
    }
    
    // Find characters that occur less than k times.
    vector<char> invalidChars;
    for (int i = 0; i < 26; i++) {
        if (charCount[i] > 0 && charCount[i] < k) {
            invalidChars.push_back(i + 'a');
        }
    }
    
    if (invalidChars.empty()) {
        return n;
    }
    
    int result = 0;
    int start = 0;
    
    // Iterate through the string and split it based on invalid characters.
    for (int i = 0; i < n; i++) {
        if (find(invalidChars.begin(), invalidChars.end(), s[i]) != invalidChars.end()) {
            // When an invalid character is found, recursively check the substring before it.
            result = max(result, longestSubstring(s.substr(start, i - start), k));
            start = i + 1; // Update the starting index for the next substring.
        }
    }
    
    // Check the last substring.
    result = max(result, longestSubstring(s.substr(start), k));
    
    return result;
}

int main() {
    string s;
    int k;

    // Prompt the user to enter a string.
    cout << "Enter a string: ";
    cin >> s;

    // Prompt the user to enter the minimum repeating count (k).
    cout << "Enter the minimum repeating count (k): ";
    cin >> k;

    // Calculate the length of the longest substring with at least k repeating characters.
    int length = longestSubstring(s, k);
    
    // Display the result.
    cout << "The longest substring with at least " << k << " repeating characters is of length " << length << endl;
    
    return 0;
}

// Explanation of the code step by step:

// Include necessary header files for input/output, string manipulation, and vector handling.

// Define a function longestSubstring that takes a string s and an integer k as arguments and returns the length of the longest substring with at least k repeating characters.

// Get the length of the input string s and perform initial checks:

// If the string is empty (n == 0) or k is greater than the length of the string (k > n), return 0 because there can't be a valid substring in these cases.
// If k is 1, return the length of the entire string since any character repeated once satisfies the condition.
// Create a vector charCount to count the occurrences of each character in the string. Initialize it with zeros for all 26 lowercase letters.

// Find characters that occur less than k times and store them in the invalidChars vector.

// If there are no invalid characters (i.e., invalidChars is empty), return the length of the entire string because the whole string is a valid substring.

// Initialize result to 0, which will store the length of the longest valid substring, and start to 0, which will keep track of the starting index of the current substring.

// Iterate through the string s character by character and split it into substrings whenever an invalid character is encountered.

// When an invalid character is found, recursively check the substring before it using longestSubstring.
// Update result with the maximum of the current result and the length of the valid substring.
// Update start to the index after the invalid character to begin the next substring.
// After the loop, check the last substring and update result one last time.

// Return the result, which contains the length of the longest valid substring.

// In the main function:

// Prompt the user to enter a string and store it in the s variable.
// Prompt the user to enter the minimum repeating count k and store it in the k variable.
// Call the longestSubstring function to calculate the length of the longest valid substring.
// Display the result to the user.
// This code allows the user to input a string and a minimum repeating count k, and it calculates and displays the length of the longest substring that meets the specified criteria.
