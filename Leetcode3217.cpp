#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/ */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int x : nums){
            s.insert(x);
        }
        ListNode* t = new ListNode(-1);
        ListNode* temp = t;
        while(head){
            if(s.find(head->val) == s.end()){
                temp->next = head;
                temp = temp->next;
            }
            head = head->next;
        }

        temp->next = NULL;
        return t->next;
    }
};