// Last updated: 5/2/2026, 11:11:12 PM
1class Solution {
2public:
3    bool isGood(int n) {
4        int f = false, s = false;
5        while(n > 0) {
6            int ld = n % 10;
7            if(ld == 3 || ld == 4 || ld == 7) f = true; // these don't give a valid digit after rotating so if these exists (f becomes true) we returb false
8            if(ld == 2 || ld == 5 || ld == 6 || ld == 9) s = true; // these rotate and give a valid digit so if atleast any one exists it can give us a different number so we return true if s is true only when f is false
9            n /= 10;
10        }
11        if(f) return false;
12        else if(s) return true;
13        return false;
14    }
15    int rotatedDigits(int n) {
16        int ans = 0;
17        for(int i=1;i<=n;i++) {
18            if(isGood(i)) ans++;
19        }
20        return ans;
21    }
22};