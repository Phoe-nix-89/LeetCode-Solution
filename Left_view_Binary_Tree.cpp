#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1 */

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   if(!root) return ans;
   queue<pair<Node*,int>> q;
   q.push({root,1});
   int l = 1;
   
   while(q.size()){
       auto x = q.front();
       q.pop();
       
       if(x.first->left) q.push({x.first->left,x.second+1});
       if(x.first->right) q.push({x.first->right,x.second+1});
       
       if(x.second == l){
           ans.push_back(x.first->data);
           l++;
       }
   }
   
   return ans;
}