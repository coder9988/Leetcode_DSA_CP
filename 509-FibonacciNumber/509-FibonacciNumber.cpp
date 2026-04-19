// Last updated: 4/19/2026, 6:00:44 PM
1class Solution {
2public:
3    int fib(int n) {
4        if(n==0 || n==1)
5        {
6            return n;
7        }
8        return fib(n-1) + fib(n-2);
9    }
10};