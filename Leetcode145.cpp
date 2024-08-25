#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/binary-tree-postorder-traversal/?envType=daily-question&envId=2024-08-25 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root) st.push(root);
        while(st.size()){
            TreeNode* temp = st.top();
            st.pop();

            if(temp->left){
                st.push(temp->left);
            }
            if(temp->right){
                st.push(temp->right);
            }

            ans.push_back(temp->val);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};