# Last updated: 8/29/2026, 7:19:48 PM
1class Solution:
2    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
3        d = {}
4        for i in nums:
5            d[i] = d.get(i,0)+1
6        newitems = sorted(d.items(),key = lambda x: (x[1],x[0]),reverse = True)
7        l = []
8        for i in range(k):
9            l.append(newitems[i][0])
10        return l