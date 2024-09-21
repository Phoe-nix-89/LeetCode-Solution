#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1 */

struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
  public:
    Node *copyList(Node *head) {
        // Write your code here
        unordered_map<int,Node*> s;
        Node* temp = new Node(-1);
        Node* t = temp;
        while(head){
            if(s.find(head->data) != s.end()){
                t->next = s[head->data];
                t = t->next;
            }
            else{
                Node* r = new Node(head->data);
                s[head->data] = r;
                t->next = s[head->data];
                t = t->next;
            }
            
            if(head->random != NULL){
                if(s.find(head->random->data) != s.end()){
                    t->random = s[head->random->data];
                }
                else{
                    Node* r = new Node(head->random->data);
                    s[head->random->data] = r;
                    t->random = s[head->random->data];
                }
            }
            
            head = head->next;
        }
        
        return temp->next;
    }
};