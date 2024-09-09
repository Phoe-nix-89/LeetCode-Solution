#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/spiral-matrix-iv/?envType=daily-question&envId=2024-09-09 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> arr(m,vector<int> (n,-1));
        int mini = 0;
        int maxi = m-1;
        int minj = 0;
        int maxj = n-1;
        
        while(head != NULL && (mini<=maxi && minj<=maxj)){
            int j = minj;
            while(head != NULL && j<=maxj){
                arr[mini][j] = head->val;
                head = head->next;
                j++;
            }
            mini++;
            if(head == NULL || mini>maxi || minj>maxj) break;
            int i = mini;
            while(head != NULL && i<=maxi){
                arr[i][maxj] = head->val;
                head = head->next;
                i++;
            }
            maxj--;
            if(head == NULL || mini>maxi || minj>maxj) break;
            j = maxj;
            while(head != NULL && j>=minj){
                arr[maxi][j] = head->val;
                head = head->next;
                j--;
            }
            maxi--;
            if(head == NULL || mini>maxi || minj>maxj) break;
            i = maxi;
            while(head != NULL && i>=mini){
                arr[i][minj] = head->val;
                head = head->next;
                i--;
            }
            minj++;
            if(head == NULL || mini>maxi || minj>maxj) break;
        }

        return arr;
    }
};