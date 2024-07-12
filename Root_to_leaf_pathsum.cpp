#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1 */

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
  public:
    void check(Node* root,int sum,int &target){
        if(root== NULL) return;
        sum += root->data;
        if(root->left == NULL && root->right == NULL){
            if(sum == target){
                target = -1;
            }
            return;
        }
        
        
        if(sum < target){
            check(root->left,sum,target);
            check(root->right,sum,target);
        }
    }
    bool hasPathSum(Node *root, int target) {
        // Your code here
        int sum = 0;
        check(root,sum,target);
        if(target == -1) return true;
        return false;
    }
};