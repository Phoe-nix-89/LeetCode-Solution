#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/?envType=daily-question&envId=2024-07-18 */

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
    vector<TreeNode*> v;
    unordered_map<TreeNode*,unordered_set<TreeNode*>> m;
    void find(TreeNode* root,TreeNode* temp){
        if(root == NULL) return;

        find(root->left,root);
        find(root->right,root);

        if(temp != root){
            m[root].insert(temp);
        }
        if(root->left) m[root].insert(root->left);
        if(root->right) m[root].insert(root->right);

        if(root->left == NULL && root->right == NULL){
            v.push_back(root);
        }
    }
    int countPairs(TreeNode* root, int distance) {
        find(root,root);
        queue<pair<TreeNode*,int>> q;
        int ans = 0;
        //unordered_map<int,unordered_set<int>> p;

        for(TreeNode* t : v){
            unordered_set<TreeNode*> s;
            q.push({t,0});
            s.insert(t);
            while(q.size()){
                TreeNode* temp = q.front().first;
                int d = q.front().second;
                q.pop();
                if(temp != t && (temp->left == NULL && temp->right == NULL) && d<=distance ){
                    ans++;
                }

                if(d>=distance) continue;

                for(TreeNode* x : m[temp]){
                    if(s.find(x) == s.end()){
                        q.push({x,d+1});
                        s.insert(x);
                    }
                }
            }
        }

        ans = ans/2;

        

        return ans;
    }
};