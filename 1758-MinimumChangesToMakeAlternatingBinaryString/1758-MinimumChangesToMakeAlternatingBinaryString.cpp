// Last updated: 3/5/2026, 1:40:22 PM
1class Solution {
2public:
3    int minOperations(string& s) {
4        //op[0] count op need for "0101.." 
5        //op[1] count op need for "1010.."
6        int n=s.size(), op[2]={0};
7        for(int i=0; i<n; i+=2){
8            op[s[i]=='0']++;
9            if (i+1<n) [[likely]]
10                op[s[i+1]=='1']++;
11        }
12        return min(op[0], op[1]);
13    }
14};