#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1 */

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        // Your code here
        Node* temp = new Node(-1);
        Node* t = temp;
        int i = 1;
        while(i<=k){
            t->next = head;
            t = t->next;
            head = head->next;
            i++;
        }
        
        if(head == NULL) return temp->next;
        Node* newhead = head;
        t->next = NULL;
        while(head->next){
            head = head->next;
        }
        head->next = temp->next;
        return newhead;
    }
};