#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2024-07-05 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* Next = head->next->next;

        int i = -1;
        int j = -1;
        int k = -1;
        int temp = 1;
        vector<int> ans(2,-1);
        while(Next){
            if((curr->val > prev->val && curr->val > Next->val) || (curr->val < prev->val && curr->val < Next->val) ){
                if(i == -1) i = temp;
                

                if(j == -1) j = temp;
                else if(k == -1){
                    k = temp;
                    int dist = abs(j-k);
                    ans[0] = dist;
                }
                else if(k>-1 && j>-1){
                    j = k;
                    k = temp;
                    int dist = abs(j-k);
                    ans[0] = min(ans[0],dist);
                }
            }

            temp++;
            curr = curr->next;
            prev = prev->next;
            Next = Next->next;
        }

        if(k == -1) return ans;
        ans[1] = max(ans[1],abs(i-k));
        return ans;
    }
};