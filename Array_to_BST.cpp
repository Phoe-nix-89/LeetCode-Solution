#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};

/* https://www.geeksforgeeks.org/problems/array-to-bst4443/1 */

class Solution {
  public:
    vector<int> temp;
    Node* make(int i,int j){
        if(i>j) return NULL;
        
        int m = i+(j-i)/2;
        
        Node* t = new Node(temp[m]);
        
        t->left = make(i,m-1);
        t->right = make(m+1,j);
        
        return t;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        temp = nums;
        return make(0,nums.size()-1);
    }
};