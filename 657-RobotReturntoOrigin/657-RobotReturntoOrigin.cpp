// Last updated: 4/5/2026, 9:46:50 PM
1class Solution {
2public:
3    bool judgeCircle(string& moves) {
4        int H=0, V=0;
5        for(char c: moves){
6            H+=(c=='R');
7            H-=(c=='L');
8            V+=(c=='U');
9            V-=(c=='D');
10        }
11        return (H==0) & (V==0);
12    }
13};