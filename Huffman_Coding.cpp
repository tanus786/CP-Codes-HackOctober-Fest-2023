//Huffman Coding
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;a
    int frequency;
    Node *left, *right;
    Node(char value, int freq)
    {
        data = value;
        frequency = freq;
        left = right = NULL;
    }
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {

        return a->frequency > b->frequency;
    }
};

Node *generateTree(priority_queue<Node *, vector<Node *>,  Compare> box)
{
    while (box.size() > 1)
    {
        Node *left_node = box.top();
        box.pop();
        Node *right_node = box.top();
        box.pop();
        Node *node = new Node('$', left_node->frequency + right_node->frequency);
        node->left = left_node;
        node->right = right_node;
        box.push(node);
    }
    return box.top();
}

void print_codes(Node *root,vector<int>&vec)
{
   if(root->left==NULL && root->right==NULL)
   {
       cout<<root->data<<": ";
       for(auto i: vec)
       {
           cout<<i;
       }
       cout<<endl;
       return;
   }

    if(root->left)
    {
        vec.push_back(0);
        print_codes(root->left,vec);
        vec.pop_back();
    }
    if(root->right)
    {
        vec.push_back(1);
        print_codes(root->right,vec);
        vec.pop_back();
    }
}

void huffman_codes(char arr[], int freq[], int n)
{
    priority_queue<Node *, vector<Node *>, Compare> box;
    for (int i = 0; i < n; i++)
    {
        Node *node = new Node(arr[i], freq[i]);
        box.push(node);
    }
    vector<int>vec;
    Node *root=generateTree(box);
    print_codes(root,vec);
}

int main()
{
   char arr[]={'a','b','c','d','e','f'};
   int freq[]={50,10,30,5,3,2};
   huffman_codes(arr,freq,6);
    return 0;
}
