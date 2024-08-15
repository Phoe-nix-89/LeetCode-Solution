#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    int add(Node* head){
        if(head == NULL) return 1;
        
        int r = add(head->next);
        int temp = head->data + r;
        head->data = temp%10;
        
        return temp/10;
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        int r = add(head);
        if(r == 1){
            Node* n = new Node(1);
            n->next = head;
            return n;
        }
        
        return head;
    }
};