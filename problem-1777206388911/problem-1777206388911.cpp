// Last updated: 4/26/2026, 5:56:28 PM
1class Solution {
2public:
3    bool validDigit(int n, int x) {
4        int rem = 0;
5        string s = to_string(n);
6        if(s[0]==(x+'0') || (n<10 && n != x))
7        {
8            return false;
9        }
10        while(n!=0)
11        {
12            rem = n%10;
13            if(rem==x)
14            {
15                return true;
16            }
17            n /= 10;
18        }
19        cout<<rem;
20        return false;
21    }
22};