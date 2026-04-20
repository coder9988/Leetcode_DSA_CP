// Last updated: 4/20/2026, 8:55:20 PM
1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        const int n=colors.size();
5        int c0=colors[0], cN=colors[n-1];
6        int lMax=0, rMax=0;
7        for(int i=0; i<n; i++){
8            int c=colors[i];
9            if (c0!=c) lMax=max(lMax, i);
10            if (cN!=c) rMax=max(rMax, n-1-i);
11        }
12        return max(lMax, rMax);
13    }
14};