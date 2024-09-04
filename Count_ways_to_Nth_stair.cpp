#include<bits/stdc++.h>
using namespace std;

/* https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1 */

class Solution{
	public:
		int nthStair(int n){
		    //  Code here
		    int o = 0;
		    int t = 0;
		    int c = 1;
		    o = n;
		    while(o >= 2){
		        t += 1;
		        o-=2;
		        c++;
		    }
		    
		    return c;
		}
};