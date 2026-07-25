# Last updated: 7/26/2026, 1:18:28 AM
1class Solution(object):
2    def maxProduct(self, n):
3        """
4        :type n: int
5        :rtype: int
6        """
7        l = []
8        while n!=0:
9            l.append(n%10)
10            n/=10
11        l.sort(reverse=True)
12        return l[0]*l[1]
13
14        