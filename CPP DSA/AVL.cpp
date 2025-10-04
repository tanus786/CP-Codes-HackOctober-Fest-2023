#include <iostream>
using namespace std;

class AVLTree{
public:
    int val;
    AVLTree* left;
    AVLTree* right;

    AVLTree(){
        val=0;
        left=NULL;
        right=NULL;
    }
    AVLTree(int data){
        val=data;
        left=NULL;
        right=NULL;
    }

    int height(AVLTree* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    AVLTree* new_node(AVLTree* root, int data){
        AVLTree* new_node = new AVLTree(data);
        return Insertion(root,new_node);
    }
    int BF(AVLTree* root){
        if(!root){
            return -1;
        }
        int factor = height(root->left)-height(root->right);
        return factor;
    }
    AVLTree* LeftRotate(AVLTree* root){
        AVLTree* next_root = root->right;
        AVLTree* left_child = root->right->left;
        next_root->left = root;
        root->right = left_child;
        return next_root;
    }
    AVLTree* RightRotate(AVLTree* root){
        AVLTree* next_root = root->left;
        AVLTree* right_child = root->left->right;
        next_root->right = root;
        root->left = right_child;
        return next_root;
    }

    AVLTree* Insertion(AVLTree* root,AVLTree* new_node){
        if(!root){
            root=new_node;
            return root;
        }
        if(new_node->val < root->val){
            root->left = Insertion(root->left, new_node);
        }
        else if (new_node->val > root->val){
            root->right = Insertion(root->right, new_node);
        }
        else {
            cout<<"No Duplicate"<<endl;
            return root;
        }
        int bf= BF(root);
        if(bf>1 && new_node->val < root->left->val){
            return RightRotate(root);
        }
        if(bf<-1 && new_node->val> root->right->val){
            return LeftRotate(root);
        }
        if(bf>1 && new_node->val > root->left->val){
            root->left = LeftRotate(root->left);
            return RightRotate(root);
        }
        if(bf<-1 && new_node->val < root->right->val){
            root->right = RightRotate(root->right);
            return LeftRotate(root);
        }
        return root;
    }
     void printInorder(AVLTree* r){
        if (r == NULL)
          return;
        printInorder(r -> left);
        cout << r -> val << " ";
        printInorder(r -> right);
      }
      void printPreorder(AVLTree * r){
        if (r == NULL)
          return;
        cout << r -> val << " ";
        printPreorder(r -> left);
        printPreorder(r -> right);
      }

    AVLTree* FindMin(AVLTree * node) {
        AVLTree * current = node;
        while (current -> left != NULL) {
          current = current -> left;
        }
        return current;
      }
      AVLTree* Deletion(AVLTree* root, int data){
      if(!root){
        return NULL;
      }
      else if (root->val > data){
        root->left = Deletion(root->left , data);
      }
      else if (root->val < data){
        root->right = Deletion(root->right , data);
      }
      else {
        if(root->left==NULL){
            AVLTree* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right==NULL){
            AVLTree* temp = root->left;
            delete root;
            return temp;
        }
        else {
            AVLTree* temp = FindMin(root->right);
            root->val = temp->val;
            root->right = Deletion(root->right, temp->val);
        }
      }
        int bf = BF(root);
        if(bf==2 && BF(root->left)>=0){
            return RightRotate(root);
        }
        else if(bf==2 && BF(root->left)==-1){
            root->left = LeftRotate(root->left);
            return RightRotate(root);
        }
        else if(bf==-2 && BF(root->right)<=0){
            return LeftRotate(root);
        }
        else if(bf==-2 && BF(root->right)==1){
            root->right = RightRotate(root->right);
            return LeftRotate(root);
        }
        return root;
      }
      /*
        AVLTree * minvalNode(AVLTree * node) {
    AVLTree * current = node;
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }
        AVLTree * deleteNode(AVLTree * r, int v) {
    // base case
    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    else if (v < r -> val) {
      r -> left = deleteNode(r -> left, v);
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (v > r -> val) {
      r -> right = deleteNode(r -> right, v);
    }
    // if key is same as root's key, then This is the node to be deleted
    else {
      // node with only one child or no child
      if (r -> left == NULL) {
        AVLTree * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        AVLTree * temp = r -> left;
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        AVLTree * temp = minvalNode(r -> right);
        // Copy the inorder successor's content to this node
        r -> val = temp -> val;
        // Delete the inorder successor BF
        r -> right = deleteNode(r -> right, temp -> val);
        //deleteNode(r->right, temp->val);
      }
    }

    int bf = BF(r);
    // Left Left Imbalance/Case or Right rotation
    if (bf == 2 && BF(r -> left) >= 0)
      return RightRotate(r);
    // Left Right Imbalance/Case or LR rotation
    else if (bf == 2 && BF(r -> left) == -1) {
      r -> left = LeftRotate(r -> left);
      return RightRotate(r);
    }
    // Right Right Imbalance/Case or Left rotation
    else if (bf == -2 && BF(r -> right) <= -0)
      return LeftRotate(r);
    // Right Left Imbalance/Case or RL rotation
    else if (bf == -2 && BF(r -> right) == 1) {
      r -> right = RightRotate(r -> right);
      return LeftRotate(r);
    }

    return r;
  }
  */
};

int main(){
    AVLTree* root = new AVLTree();
    root=NULL;
    AVLTree obj;
    root=obj.new_node(root,5);
    root=obj.new_node(root,31);
    root=obj.new_node(root,11);
    root=obj.new_node(root,23);
    root=obj.new_node(root,13);
    root=obj.new_node(root,76);
    root=obj.new_node(root,9);
//    new_node->val=9;
//    root=Insertion(root,new_node);
//    new_node->val=96;
//    root=Insertion(root,new_node);
    obj.printInorder(root);
    cout<<endl;
    obj.printPreorder(root);
    root=obj.Deletion(root,9);
    cout<<endl;
    obj.printInorder(root);
    cout<<endl;
    obj.printPreorder(root);

    return 0;

}
