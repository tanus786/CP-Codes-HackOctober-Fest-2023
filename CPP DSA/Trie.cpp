// Assuming to store strings only containing A-Z without any space i.e. word

#include <iostream>
using namespace std;

// Structure for the Node of the Trie
struct TrieNode
{
    bool is_entry;          // Checking if the entry is valid on a particular node or not
    TrieNode *children[26]; // For storing 26 Alphabets of english
};

// Wrapper structure for the Trie
struct Trie
{
    TrieNode *root; // Create this root node whenever declare any Trie, whose is_entry equals to false
};

// Helper Function for finding the index of the children of the Trie node
int LetterToIndex(char letter)
{
    return letter - 65; // As A->0 && Z->25
}

// Function for searching for the target in the Trie
TrieNode *TrieNodeSearch(TrieNode *current, string target, int index)
{
    if (index == target.length()) // Checking if the target node is at the current depth or not
    {
        if (current->is_entry) // If yes checking if it is a valid node or not
        {
            return current;
        }
        else // There is no valid node at this depth for the target we are searching
        {
            return NULL;
        }
    }

    char next_letter = target[index];                     // Finding the next letter for the node
    int next_index = LetterToIndex(next_letter);          // Finding the next children index where the next character points to in the Trie
    TrieNode *next_child = current->children[next_index]; // Storing the child for the current node in a variable

    if (next_child == NULL) // Checking if the child is valid or not
    {
        return NULL;
    }
    else
    {
        return TrieNodeSearch(next_child, target, index + 1); // Recussive call for searching the next character
    }
}

// Wrapper function for TrieNodeSearch
TrieNode *TrieSearch(Trie trie, string target)
{
    return TrieNodeSearch(trie.root, target, 0);
}

// Fuction for Insertion of the nod in a Trie
void TrieNodeInsert(TrieNode *current, string new_value, int index)
{
    if (index == new_value.length()) // Checking if the current node is at current depth or not if yes marking its entry as valid
    {
        current->is_entry = true;
    }
    else
    {
        char next_letter = new_value[index];                  // Storing the next letter of the string
        int next_index = LetterToIndex(next_letter);          // Finding the index for the children subtree
        TrieNode *next_child = current->children[next_index]; // Storing the point to the next child
        if (next_child == NULL)                               // Checking if the child node already exists or not
        {
            current->children[next_index] = new TrieNode;                        // If not creating the new child node
            TrieNodeInsert(current->children[next_index], new_value, index + 1); // Calling the recursive call to make next character node
        }
        else
        {
            TrieNodeInsert(next_child, new_value, index + 1); // If yes calling the fuction for crateing next character node
        }
    }
}

// Wrapper function for inserting the node in the Trie
void TrieInsert(Trie trie, string new_value)
{
    return TrieNodeInsert(trie.root, new_value, 0);
}

// Function to delete the node of the Trie
bool TrieNodeDelete(TrieNode *current, string target, int index)
{
    if (index == target.length()) // Checking if we have to remove the node is at correct depth or not
    {
        if (current->is_entry)
        {
            current->is_entry = false;
        }
    }
    else // Traversing to down to the trie same as search and insert
    {
        char next_letter = target[index];
        int next_index = LetterToIndex(next_letter);
        TrieNode *next_child = current->children[next_index];

        if (next_child != NULL)
        {
            if (TrieNodeDelete(next_child, target, index + 1))
            {
                current->children[next_index] = NULL;
            }
        }
    }
    //#Do not delete this node if it has either an entry or a child
    if (current->is_entry) // If current node is a valid node
    {
        return false;
    }

    for (auto x : current->children) //Checking if any sub-node/children node is a valid node or not.
    {
        if (x != NULL)
        {
            return false;
        }
    }

    return true;
}

// Wrapper Function to delete the node from the Trie
void TrieDelete(Trie tr, string target)
{
    TrieNodeDelete(tr.root, target, 0);
}
