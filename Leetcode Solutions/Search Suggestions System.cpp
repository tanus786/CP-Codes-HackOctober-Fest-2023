/* Author :  JaiSehgal007 */

/* Search Suggestions System */

/* Link to the Problem : https://leetcode.com/problems/search-suggestions-system/ */

/*

PROBLEM DESCRIPTION::

You are given an array of strings products and a string searchWord.
Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with 
searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.
Return a list of lists of the suggested products after each character of searchWord is typed.

*/

/*

EXAMPLES RELATED TO PROBLEM::

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
Example 2:

Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.

*/

/*--------------------------------------------------SOLUTION--------------------------------------------------------*/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
           sort(products.begin(),products.end());
           vector<vector<string>>result;
           int start,bsStart=0,n=products.size();
           string prefix="";
           for(auto ch:searchWord){
               prefix+=ch;
               start=lower_bound(products.begin()+bsStart,products.end(),prefix)-products.begin();
               vector<string>res;

               for(int i=start;i<start+3 and i<n and !products[i].compare(0,prefix.size(),prefix);i++){
                   res.push_back(products[i]);
               }
               result.push_back(res);
               bsStart=start;

           }     
           return result;
    }
};
