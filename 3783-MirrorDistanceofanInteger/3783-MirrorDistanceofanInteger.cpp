// Last updated: 4/18/2026, 10:32:40 PM
1class Solution {
2public:
3    int mirrorDistance(int n) {
4        
5        // int flip = 0;
6        int rem = n;
7        string flip = "";
8        while(rem!=0)
9        {
10            int d = rem%10;
11            flip += to_string(d);
12            rem /=10;
13        }
14        int flip2 = stoi(flip);
15        return abs(n-flip2);
16    }
17};