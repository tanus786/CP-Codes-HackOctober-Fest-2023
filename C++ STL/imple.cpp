// C based program to implement reverse DNS lookup
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// There are atmost 27 different chars in a valid URL
// assuming URL consists [a-z] and (.)
#define CHARS 27

// Maximum length of a valid URL
#define MAX 100

// A utility function to find index of child for a given character 'c'
int getIndex(char c)
{
	return (c == '.') ? 26 : (c - 'a');
}

// A utility function to find character for a given child index.
char getCharFromIndex(int i)
{
	return (i == 26) ? '.' : ('a' + i);
}

// Trie Node.
struct trieNode
{
	bool isLeaf;
	char *ipAdd;
	struct trieNode *child[CHARS];
};

// Function to create a new trie node.
struct trieNode *newTrieNode(void)
{
	struct trieNode *newNode = new trieNode;
	newNode->isLeaf = false;
	newNode->ipAdd = NULL;
	for (int i = 0; i<CHARS; i++)
		newNode->child[i] = NULL;
	return newNode;
}

// This method inserts a URL and corresponding IP address
// in the trie. The last node in Trie contains the ip address.
void insert(struct trieNode *root, char *URL, char *ipAdd)
{
	// Length of the URL
	int len = strlen(URL);
	struct trieNode *pCrawl = root;

	// Traversing over the length of the URL.
	for (int level = 0; level<len; level++)
	{
		// Get index of child node from current character
		// in URL[] Index must be from 0 to 26 where
		// 0 to 25 is used for alphabets and 26 for dot
		int index = getIndex(URL[level]);

		// Create a new child if not exist already
		if (!pCrawl->child[index])
			pCrawl->child[index] = newTrieNode();

		// Move to the child
		pCrawl = pCrawl->child[index];
	}

	//Below needs to be carried out for the last node.
	//Save the corresponding ip address of the URL in the
	//last node of trie.
	pCrawl->isLeaf = true;
	pCrawl->ipAdd = new char[strlen(ipAdd) + 1];
	strcpy(pCrawl->ipAdd, ipAdd);
}

// This function returns IP address if given URL is
// present in DNS cache. Else returns NULL
char *searchDNSCache(struct trieNode *root, char *URL)
{
	// Root node of trie.
	struct trieNode *pCrawl = root;
	int len = strlen(URL);

	// Traversal over the length of URL.
	for (int level = 0; level<len; level++)
	{
		int index = getIndex(URL[level]);
		if (!pCrawl->child[index])
			return NULL;
		pCrawl = pCrawl->child[index];
	}

	// If we find the last node for a given ip address,
	// print the ip address.
	if (pCrawl != NULL && pCrawl->isLeaf)
		return pCrawl->ipAdd;

	return NULL;
}

// Driver function.
int main()
{
	char URL[][50] = { "www.samsung.com", "www.samsung.net",
					"www.google.in"
					};
	char ipAdd[][MAX] = { "107.108.11.123", "107.109.123.255",
						"74.125.200.106"
						};
	int n = sizeof(URL) / sizeof(URL[0]);
	struct trieNode *root = newTrieNode();

	// Inserts all the domain name and their corresponding
	// ip address
	for (int i = 0; i<n; i++)
		insert(root, URL[i], ipAdd[i]);

	// If forward DNS look up succeeds print the url along
	// with the resolved ip address.
	char url[] = "www.samsung.com";
	char *res_ip = searchDNSCache(root, url);
	if (res_ip != NULL)
		printf("Forward DNS look up resolved in cache:\n%s --> %s",
			url, res_ip);
	else
		printf("Forward DNS look up not resolved in cache ");

	return 0;
}
