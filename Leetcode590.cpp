#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/n-ary-tree-postorder-traversal/?envType=daily-question&envId=2024-08-26 */

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> v;
    void dfs(Node* root){
        if(root == NULL) return;
        if(root->children.size() == 0) {
            v.push_back(root->val);
            return;
        }

        for(Node* temp : root->children){
            dfs(temp);
        }

        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        dfs(root);

        return v;
    }
};