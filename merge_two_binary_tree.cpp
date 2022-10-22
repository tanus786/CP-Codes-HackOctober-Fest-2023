#include <bits/stdc++.h>
using namespace std;
class TreeNode{
   public:
      int val;
      TreeNode *left, *right;
      TreeNode(int data){
         val = data;
         left = right = NULL;
      }
};
void insert(TreeNode **root, int val){
   queue<TreeNode*> q;
   q.push(*root);
   while(q.size()){
      TreeNode *temp = q.front();
      q.pop();
      if(!temp->left){
         temp->left = new TreeNode(val);
         return;
      }
      else{
         q.push(temp->left);
      }
      if(!temp->right){
         temp->right = new TreeNode(val);
         return;
      }
      else{
         q.push(temp->right);
      }
   }
}
TreeNode *make_tree(vector<int> v){
   TreeNode *root = new TreeNode(v[0]);
   for(int i = 1; i<v.size(); i++){
      insert(&root, v[i]);
   }
   return root;
}
void tree_level_trav(TreeNode*root){
   if (root == NULL) return;
   cout << "[";
   queue<TreeNode *> q;
   TreeNode *curr;
   q.push(root);
   q.push(NULL);
   while (q.size() > 1) {
      curr = q.front();
      q.pop();
      if (curr == NULL){
         q.push(NULL);
      }
      else {
         if(curr->left)
            q.push(curr->left);
         if(curr->right)
            q.push(curr->right);
         if(curr->val == 0){
            cout << "null" << ", ";
         }
         else{
            cout << curr->val << ", ";
         }
      }
   }
   cout << "]"<<endl;
}
class Solution {
public:
   TreeNode* mergeTrees(TreeNode* n1, TreeNode* n2) {
      if(!n1 && n2){
         return n2;
      }
      else if(!n2 && n1)return n1;
      else if(!n1 && !n2)return NULL;
      n1->val+=n2->val;
      n1->left = mergeTrees(n1->left,n2->left);
      n1->right = mergeTrees(n1->right,n2->right);
      return n1;
   }
};
main(){
   Solution ob;
   vector<int> v1;
   vector<int> v2;
   cout<<"enter no. of elements: ";
   int n;
   cin>>n;
   cout<<"\nenter elements of tree 1: ";
   for(int i=0;i<n;i++){
      int x;
      cin>>x;
      v1.push_back(x);
   }
    cout<<"\nenter elements of tree 2: ";
   for(int i=0;i<n;i++){
      int y;
      cin>>y;
      v2.push_back(y);
   }
   TreeNode *root1 = make_tree(v1);
   TreeNode *root2 = make_tree(v2);
   root1 = ob.mergeTrees(root1, root2);
   tree_level_trav(root1);
}
