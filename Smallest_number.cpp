#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/smallest-number5829/1 */

class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(s > (9*d)) return "-1";
        int n = s/d;
        int r = s%d;
        string ans = "";
        for(int i=0;i<d;i++){
            ans += to_string(n);
        }
        //cout<<ans<<endl;
        if(ans[0] == '0'){
            int temp = ans[0] - '0';
            temp += 1;
            char c = char(temp + '0');
            ans[0] = c;
            r--;
        }
        for(int i=(d-1);i>=0;i--){
            while(ans[i] != '9' && r > 0){
                int temp = ans[i] - '0';
                temp += 1;
                char c = char(temp + '0');
                ans[i] = c;
                r--;
            }
        }
        
        int i = 0;
        int j = d-1;
        int temp1 = ans[i] - '0';
        int temp2 = ans[j] - '0';
        while(i=j && temp2 < 9 && temp1 > 1){
            temp2 += 1;
            temp1 -= 1;
        }
        
        char c1 = char(temp1 + '0');
        char c2 = char(temp2 + '0');
        ans[i] = c1;
        ans[j] = c2;
        if(i!=j && temp1 == 1 && temp2 == 9){
            i++;
            j--;
        }
        else if(i!=j && temp1 == 1) i++;
        else if(i!=j && temp2 == 9) j--;
        
        
        while(i<j){
            int t1 = ans[i] - '0';
            int t2 = ans[j] - '0';
            if(t1 <= 1 && t2 == 9){
                i++;
                j--;
            }
            else if(t2 < 9){
                if(i == 0){
                    int temp1 = ans[i] - '0';
                    int temp2 = ans[j] - '0';
                    while(temp2 < 9 && temp1 > 1){
                        temp2 += 1;
                        temp1 -= 1;
                    }
                    
                    char c1 = char(temp1 + '0');
                    char c2 = char(temp2 + '0');
                    ans[i] = c1;
                    ans[j] = c2;
                    
                    if(temp1 == 1 && temp2 == 9){
                        i++;
                        j--;
                    }
                    else if(temp1 == 1) i++;
                    else if(temp1 > 1) j--;
                }
                else if(i>0){
                    int temp1 = ans[i] - '0';
                    int temp2 = ans[j] - '0';
                    while(temp2 < 9 && temp1 > 0){
                        temp2 += 1;
                        temp1 -= 1;
                    }
                    
                    char c1 = char(temp1 + '0');
                    char c2 = char(temp2 + '0');
                    ans[i] = c1;
                    ans[j] = c2;
                    
                    if(temp1 == 0 && temp2 == 9){
                        i++;
                        j--;
                    }
                    else if(temp1 == 0) i++;
                    else if(temp1 > 0) j--;
                }
            }
            else{
                if(i == 0 && (t2 == 9 || t1 > 1)) j--;
                else if(i > 0 && (t2 == 9 || t1 > 0)) j--;
            }
        }
        
        return ans;
    }
};