void traversal(TreeNode* root){
    
    vector<int>pre,in,pos;
    stack<pair<TreeNode*,int>>st;
    st.push({root,1});
    while(!st.empty()){
        auto node = st.top();
        st.pop();
        if(node.second==1){
            pre.push_back(node.first->val);
            node.second++;
            st.push(node);

            if(node.first->left){
                st.push({node.first->left,1});
            }
        }
        else if(node.second==2){
            in.push_back(node.first->val);
            node.second++;
            st.push(node);
            if (node.first->right)
            {
                st.push({node.first->right, 1});
            }
        }
        else{
            pos.push_back(node.first->val);
        }
    }
}
