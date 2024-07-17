#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1 */

// Below in the main code :-

class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
        unordered_map<int,vector<int>> m;
        Node* root;
        for(int i=0;i<parent.size();i++){
            if(parent[i] == -1){
                root = new Node(i);
            }
            else{
                m[parent[i]].push_back(i);
            }
        }
        
        unordered_map<int,Node*> m2;
        m2[root->data] = root;
        
        for(auto x : m){
            Node* temp;
            if(m2.find(x.first) == m2.end()){
                temp = new Node(x.first);
                m2[x.first] = temp;
            }
            else{
                temp = m2[x.first];
            }
            Node* l = NULL;
            Node* r = NULL;
            
            if(m2.find(x.second[0]) == m2.end()){
                l = new Node(x.second[0]);
                m2[x.second[0]] = l;
            }
            else{
                l = m2[x.second[0]];
            }
            
            if(x.second.size() > 1){
                if(m2.find(x.second[1]) == m2.end()){
                    r = new Node(x.second[1]);
                    m2[x.second[1]] = r;
                }
                else{
                    r = m2[x.second[1]];
                }
            }
            
            temp->left = l;
            temp->right = r;
        }
        
        return root;
    }
};