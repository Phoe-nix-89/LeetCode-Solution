#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/?envType=daily-question&envId=2024-09-10 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int find(int n1,int n2){
        if(n1%n2 == 0) return n2;
        else if(n2%n1 == 0) return n1;
        int ans = 1;
        while(true){
            int t = min(n1,n2);
            bool f = false;
            for(int i=2;i<t;i++){
                if(n1%i ==0 && n2%i == 0){
                    ans = ans * i;
                    f = true;
                    n1 = n1/i;
                    n2 = n2/i;
                    break;
                }
            }

            if(f == false) break;
        }

        return ans;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;

        while(temp2 != NULL){
            int t1 = temp1->val;
            int t2 = temp2->val;

            int n = find(t1,t2);

            ListNode* temp = new ListNode(n);
            temp1->next = temp;
            temp->next = temp2;

            temp1 = temp1->next->next;
            temp2 = temp2->next;
        }

        return head;
    }
};