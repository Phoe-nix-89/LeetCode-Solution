#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/ */

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
    long long sum = 0;
    long long ans = 0;
    void find(TreeNode* root){
        if(root == NULL) return;

        sum = ((sum)+(root->val))%1000000007;
        find(root->left);
        find(root->right);
    }
    int find(TreeNode* root,int temp){
        if(root == NULL) return 0;

        long long l = (find(root->left,0));
        long long r = (find(root->right,0));

        long long t1 = ((root->val + l%1000000007 + r%1000000007))%1000000007;
        long long t2 = ((sum - t1));
        //long long t3 = ((t1) * (t2))%1000000007;
        ans = max(ans,(t1*t2));
        //long long t3 = ((t1) * (t2))%1000000007;

        return t1;
    }
    int maxProduct(TreeNode* root) {
        find(root);

        find(root,0);

        return (int)(ans%1000000007);
    }
};