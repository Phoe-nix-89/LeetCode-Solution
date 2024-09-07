#include<bits/stdc++.h>
using namespace std;

/**/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    //ListNode* temp;
    ListNode* t;
    bool ans = false;
    void check(TreeNode* root,ListNode* temp,int c){
        if(root == NULL){
            if(temp == NULL){
                ans = true;
            }
            return;
        }

        if(temp == NULL){
            ans = true;
            return;
        }

        if(temp->val == root->val){
            check(root->left,temp->next,c+1);
            check(root->right,temp->next,c+1);
        }
    }
    void find(TreeNode* root,ListNode* head){
        if( root == NULL) return;

        if(ans == true) return;

        if(root->val == head->val){
            ListNode* temp = head;
            check(root,temp,1);
            if(ans == true) return;
        }

        find(root->left,head);
        find(root->right,head);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        ListNode* temp;
        //temp = head;
        t = head;
        int c = 0;
        find(root,head);
        return ans;
    }
};