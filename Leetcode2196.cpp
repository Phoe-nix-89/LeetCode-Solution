#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2024-07-15 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// The code starts from here

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int,pair<int,int>> m;
        unordered_set<int> s;
        for(int i=0;i<desc.size();i++){
            m[desc[i][0]].first = -1;
            m[desc[i][0]].second = -1;
        }
        for(int i=0;i<desc.size();i++){
            if(desc[i][2] == 1){
                m[desc[i][0]].first = desc[i][1];
            }
            else{
                m[desc[i][0]].second = desc[i][1];
            }

            s.insert(desc[i][1]);
        }
        int root = -1;
        for(int i=0;i<desc.size();i++){
            if(s.find(desc[i][0]) == s.end()){
                root = desc[i][0];
                break;
            }
            
        }
        TreeNode* rt = new TreeNode(root);
        stack<TreeNode*> st;
        st.push(rt);
        
        
        while(st.size()){
            TreeNode* temp = st.top();
            st.pop();
            if(m.find(temp->val) != m.end() && m[temp->val].first != -1){
                TreeNode* l = new TreeNode(m[temp->val].first);
                temp->left = l;
                st.push(l);
            }
            if(m.find(temp->val) != m.end() && m[temp->val].second != -1){
                TreeNode* r = new TreeNode(m[temp->val].second);
                temp->right = r;
                st.push(r);
            }
        }
        

        return rt;
    }
};