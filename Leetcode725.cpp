#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2024-09-08 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int c = 0;
        while(temp){
            temp = temp->next;
            c++;
        }
        int r = c%k;
        int s = c/k;
        temp = head;
        vector<ListNode*> v;
        if(r > 0){
            int i = 0;
            //v.push_back(temp);
            ListNode* t = temp;
            ListNode* p = NULL;
            while(r > 0){
                if(i == s+1){
                    p->next = NULL;
                    v.push_back(t);
                    t = temp;
                    p = NULL;
                    i = 0;
                    r--;
                }
                else{
                    p = temp;
                    temp = temp->next;
                    i++;
                }
            }
            if(i == s+1) v.push_back(t);
        }

        if(temp == NULL){
            while(v.size() < k){
                v.push_back(NULL);
            }

            return v;
        }

        ListNode* t = temp;
        ListNode* p = NULL;
        int i = 0;
        while(temp){
            if(i == s){
                p->next = NULL;
                v.push_back(t);
                t = temp;
                p = NULL;
                i = 0;
                //k--;
            }
            else{
                p = temp;
                temp = temp->next;
                i++;
            }
        }
        v.push_back(t);

        return v;
    }
};