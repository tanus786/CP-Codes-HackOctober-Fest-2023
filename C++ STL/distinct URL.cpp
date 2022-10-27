// C++ program to print distinct URLs using Trie
// and Doubly Linked List
#include <bits/stdc++.h>
using namespace std;

// Alphabet size (# of symbols)
const int ALPHABET_SIZE = 256;

// A linked list node
struct DLLNode
{
	string data;
	DLLNode* next, * prev;
};

// trie node
struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE];

	// isLeaf is true if the node represents
	// end of a word
	bool isLeaf;

	DLLNode* LLptr;
};

/* Given a reference (pointer to pointer) to the
head of a list and an int, inserts a new node
on the front of the list. */
void push(DLLNode*& head_ref, string new_data)
{
	DLLNode* new_node = new DLLNode;

	// put in the data
	new_node->data = new_data;

	// Make next of new node as head and previous
	// as NULL
	new_node->next = (head_ref);
	new_node->prev = NULL;

	// change prev of head node to new node
	if(head_ref != NULL)
		head_ref->prev = new_node;

	// move the head to point to the new node
	head_ref = new_node;
}

/* Function to delete a node in a Doubly Linked List.
head_ref --> pointer to head node pointer.
del --> pointer to node to be deleted. */
void deleteNode(DLLNode*& head_ref, DLLNode* del)
{
	// base case
	if (head_ref == NULL || del == NULL)
		return;

	// If node to be deleted is head node
	if (head_ref == del)
		head_ref = del->next;

	// Change next only if node to be deleted is
	// NOT the last node
	if (del->next != NULL)
		del->next->prev = del->prev;

	// Change prev only if node to be deleted is
	// NOT the first node
	if (del->prev != NULL)
		del->prev->next = del->next;

	// Finally, free the memory occupied by del
	delete(del);
	return;
}

// Returns new trie node (initialized to NULLs)
TrieNode* getNewTrieNode(void)
{
	TrieNode* pNode = new TrieNode;

	if (pNode)
	{
		pNode->isLeaf = false;

		for (int i = 0; i < ALPHABET_SIZE; i++)
			pNode->children[i] = NULL;

		pNode->LLptr = NULL;
	}

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(TrieNode* root, string key, DLLNode*& head)
{
	int index;
	TrieNode* pCrawl = root;

	for (int level = 0; level < key.length(); level++)
	{
		index = int(key[level]);
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNewTrieNode();

		pCrawl = pCrawl->children[index];
	}

	if (pCrawl->isLeaf)
	{
		// cout << "Duplicate Found " << key << endl;
		// delete from linked list
		if (pCrawl->LLptr)
			deleteNode(head, pCrawl->LLptr);
		pCrawl->LLptr = NULL;
	}
	else
	{
		// mark last node as leaf
		pCrawl->isLeaf = true;

		// insert to linked list
		push(head, key);
		pCrawl->LLptr = head;
	}
}

// Driver function
int main()
{
	string urls[] = {
		"https://www.geeksforgeeks.org",
		"https://write.geeksforgeeks.org",
		"http://quiz.geeksforgeeks.org",
		"http://qa.geeksforgeeks.org",
		"https://practice.geeksforgeeks.org",
		"https://ide.geeksforgeeks.org",
		"http://quiz.geeksforgeeks.org",
		"https://practice.geeksforgeeks.org",
		"https://ide.geeksforgeeks.org",
		"http://quiz.geeksforgeeks.org",
		"http://qa.geeksforgeeks.org",
		"https://practice.geeksforgeeks.org"
		};

	TrieNode* root = getNewTrieNode();

	// Start with the empty list
	DLLNode* head = NULL;
	int n = sizeof(urls)/sizeof(urls[0]);

	// Construct Trie from given URLs
	for (int i = 0; i < n; i++)
		insert(root, urls[i], head);

	// head of linked list will point to last
	// distinct URL
	cout << head->data << endl;

	return 0;
}
