#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1 */

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// This function should return head to the DLL
class Solution {
  public:
    vector<Node*> v;
    void in(Node* root){
        if(root == NULL) return;
        
        in(root->left);
        v.push_back(root);
        in(root->right);
    }
    Node* bToDLL(Node* root) {
        // code here
        in(root);
        if(v.size() == 1) return v[0];
        
        int i = 0;
        int j = 1;
        while(j<v.size()){
            v[i]->right = NULL;
            v[j]->left = NULL;
            v[i]->right = v[j];
            v[j]->left = v[i];
            
            i++;
            j++;
        }
        
        v[0]->left = NULL;
        v[v.size()-1]->right = NULL;
        return v[0];
    }
};