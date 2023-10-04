// Word Break
// PROBLEM LINK: https://practice.geeksforgeeks.org/problems/word-break1352/1
// Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

// Note: From the dictionary B each word can be taken any number of times and in any order.
// Example 1:

// Input:
// n = 12
// B = { "i", "like", "sam",
// "sung", "samsung", "mobile",
// "ice","cream", "icecream",
// "man", "go", "mango" }
// A = "ilike"
// Output:
// 1
// Explanation:
// The string can be segmented as "i like".

// CODE:



//User function Template for Java
class TrieNode
{
    TrieNode arr[];
    boolean eow;
    TrieNode()
    {
        arr = new TrieNode[26];
        for(int i=0;i<26;i++)
        arr[i] = null;
        
        eow = false;
    }
}
class Sol
{
    public static int wordBreak(String A, ArrayList<String> B )
    {
        //code here
        TrieNode root = new TrieNode();
        for(int i=0;i<B.size();i++)
        insert(root,B.get(i));
        
        if(find(root,A))
        return 1;
        else
        return 0;
        
    }
    public static void insert(TrieNode root, String key)
    {
        TrieNode curr = root;
        for(int i=0;i<key.length();i++)
        {
            char ch = key.charAt(i);
            if(curr.arr[ch-'a']==null)
            curr.arr[ch-'a'] = new TrieNode();
            
            curr = curr.arr[ch-'a'];
        }
        curr.eow = true;
    }
    public static boolean search(TrieNode root, String key)
    {
        TrieNode curr = root;
        for(int i=0;i<key.length();i++)
        {
            char ch = key.charAt(i);
            if(curr.arr[ch-'a']==null)
            return false;
            
            curr = curr.arr[ch-'a'];
        }
        return curr.eow;
    }
    public static boolean find(TrieNode root, String A)
    {
        if(A.length()==0)
        return true;
        
        for(int i=1;i<=A.length();i++)
        {
            String first = A.substring(0,i);
            String second = A.substring(i);
            if(search(root,first)&&find(root,second))
            return true;
        }
        return false;
    }
}
