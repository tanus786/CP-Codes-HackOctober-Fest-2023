
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Function that matches an input string with a given wildcard pattern
bool isMatch(string word, string pattern, int n, int m, auto &lookup)
{
    // If both the input string and pattern reach their end,
    // return true
    if (m < 0 && n < 0) {
        return true;
    }
 
    // If only the pattern reaches its end, return false
    else if (m < 0) {
        return false;
    }
 
    // If only the input string reaches its end, return true
    // if the remaining characters in the pattern are all '*'
    else if (n < 0)
    {
        for (int i = 0; i <= m; i++)
        {
            if (pattern[i] != '*') {
                return false;
            }
        }
 
        return true;
    }
 
    // If the subproblem is encountered for the first time
    if (!lookup[m][n])
    {
        if (pattern[m] == '*')
        {
            // 1. '*' matches with current characters in the input string.
            // Here, we will move to the next character in the string.
 
            // 2. Ignore '*' and move to the next character in the pattern
            lookup[m][n] = isMatch(word, pattern, n - 1, m, lookup) ||
                        isMatch(word, pattern, n, m - 1, lookup);
        }
        else {
            // If the current character is not a wildcard character, it
            // should match the current character in the input string
            if (pattern[m] != '?' && pattern[m] != word[n]) {
                lookup[m][n] = 0;
            }
            // check if pattern[0…m-1] matches word[0…n-1]
            else {
                lookup[m][n] = isMatch(word, pattern, n - 1, m - 1, lookup);
            }
        }
    }
 
    return lookup[m][n];
}
 
// Wildcard Pattern Matching Implementation in C++
int main()
{
    string word = "xyxzzxy";
    string pattern = "x***x?";
 
    int n = word.length();
    int m = pattern.length();
 
    // Create a DP lookup table
    vector<vector<bool>> lookup(m + 1, vector<bool>(n + 1, false));
 
    if (isMatch(word, pattern, n - 1, m - 1, lookup)) {
        cout << "Match";
    }
    else {
        cout << "No Match";
    }
 
    return 0;
}
Download  Run Code

Output:

Match

The time complexity of the above top-down solution is O(m.n) and requires O(m.n) extra space, where n is the length of the text and m is the length of the pattern.

 
Following is an iterative C++, Java, and Python implementation of the above code:


#include <iostream>
#include <string>
using namespace std;
 
// Function that matches the input string with a given wildcard pattern
bool isMatch(string word, string pattern)
{
    // get the length of string and wildcard pattern
    int n = word.length();
    int m = pattern.length();
 
    // create a DP lookup table
    // all elements are initialized by false by default
    bool T[n+1][m+1];
 
    // if both pattern and string are empty: match
    T[0][0] = true;
 
    // handle empty string case (i == 0)
    for (int j = 1; j <= m; j++)
    {
        if (pattern[j-1] == '*') {
            T[0][j] = T[0][j-1];
        }
    }
 
    // build a matrix in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (pattern[j-1] == '*') {
                T[i][j] = T[i-1][j] || T[i][j-1];
            }
            else if (pattern[j-1] == '?' || word[i-1] == pattern[j-1]) {
                T[i][j] = T[i-1][j-1];
            }
        }
    }
 
    // last cell stores the answer
    return T[n][m];
}
 
// Wildcard Pattern Matching Implementation in C
int main()
{
    string word = "xyxzzxy";
    string pattern = "x***x?";
 
    if (isMatch(word, pattern)) {
        cout << "Match" << endl;
    }
    else {
        cout << "No Match" << endl;
    }
 
    return 0;
}
