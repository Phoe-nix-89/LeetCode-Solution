#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/find-length-of-loop/1 */

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
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* s = head;
        Node* f = head;
        
        if(head->next == NULL) return 0;
        s = s->next;
        f = f->next->next;
        while(f!=NULL && f->next!=NULL){
            if(s == f) break;
            s = s->next;
            f = f->next->next;
        }
        
        if(f == NULL || f->next == NULL) return 0;
        
        Node* temp = head;
        while(temp != s){
            temp = temp->next;
            s = s->next;
        }
        int c = 1;
        temp = temp->next;
        while(temp!=s){
            temp = temp->next;
            c++;
        }
        
        return c;
    }
};