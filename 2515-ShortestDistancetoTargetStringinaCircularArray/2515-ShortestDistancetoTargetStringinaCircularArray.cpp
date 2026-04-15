// Last updated: 4/15/2026, 10:41:36 PM
1class Solution {
2public:
3    static int closestTarget(vector<string>& words, string& target, int startIndex) {
4        const int n=words.size();
5        int d=0;
6        for(; d<=n-1; d++){
7            const int l=startIndex>=d?startIndex-d:n+startIndex-d;
8            const int r=startIndex+d>=n?startIndex+d-n:startIndex+d;
9            const string& x=words[l];
10            const string& y=words[r];
11            if (x==target || y==target) return d;
12        }
13        return -1;
14        
15    }
16};