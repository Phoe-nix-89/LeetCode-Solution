#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/merge-nodes-in-between-zeros/description/ */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* t = new ListNode(-1);
        ListNode* r = t;
        ListNode* temp = head->next;
        int val = 0;
        while(temp){

            if(temp->val == 0){
                ListNode* n = new ListNode(val);
                r->next = n;
                r = r->next;
                val = 0;
            }
            else{
                val += temp->val;
            }

            temp = temp->next;
        }

        return t->next;
    }
};