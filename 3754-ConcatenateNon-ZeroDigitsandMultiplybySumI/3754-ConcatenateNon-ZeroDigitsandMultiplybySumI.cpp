// Last updated: 7/8/2026, 1:52:53 AM
1class Solution {
2public:
3    long long sumAndMultiply(int n) {
4        string x = "";
5        int sum = 0;
6        long long number ;
7        string num = to_string(n);
8        for (char ch : num) {
9            if (ch != '0') {
10                sum += (ch - '0');
11                x += ch;
12            }
13        }
14        if (!x.empty()) {
15            number = stoll(x);
16        }
17        return static_cast<long long>(sum) * number;
18    }
19};