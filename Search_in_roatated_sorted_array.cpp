#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1 */

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int s = 0;
        int e = arr.size()-1;
        int mid;
        while(s<e){
            mid = s + (e-s)/2;
            if(arr[s] > arr[e]){
                if(arr[mid] > arr[s]){
                    s = mid;
                }
                else{
                    e = mid-1;
                }
            }
            else{
                s = mid+1;
            }
        }
        
        int x1 = 0;
        int y1 = s;
        int x2 = s+1;
        int y2 = arr.size()-1;
        while(x1<=y1){
            mid = x1 + (y1-x1)/2;
            if(arr[mid] == key) return mid;
            else if(arr[mid] > key) y1 = mid-1;
            else if(arr[mid] < key) x1 = mid+1;
        }
        
        while(x2<=y2){
            mid = x2 + (y2-x2)/2;
            if(arr[mid] == key) return mid;
            else if(arr[mid] > key) y2 = mid-1;
            else if(arr[mid] < key) x2 = mid+1;
        }
        
        return -1;
    }
};