#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1 */

struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};


class Solution {
  public:
    // Function should return all the ancestor of the target node
    vector<int> ans;
    int t;
    void find(Node* root , vector<int> temp){
        if(root == NULL) return;
        if(root->data == t) {
            ans = temp;
            return;
        }
        
        temp.push_back(root->data);
        
        find(root->left,temp);
        find(root->right,temp);
    }
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int> temp;
        t = target;
        find(root,temp);
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};