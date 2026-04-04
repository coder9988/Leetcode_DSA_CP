// Last updated: 4/4/2026, 8:25:16 PM
1class Solution {
2public:
3    string decodeCiphertext(string s, int rows) {
4        if(s.empty()) return s;
5
6        int n = s.size();
7        int cols = (n + rows - 1) / rows;
8
9        string res;
10
11        for(int start=0; start<cols; start++){
12            int r=0, c=start;
13            while(r<rows && c<cols){
14                res += s[r*cols + c];
15                r++; c++;
16            }
17        }
18
19        while(!res.empty() && res.back()==' ') res.pop_back();
20        return res;
21    }
22};