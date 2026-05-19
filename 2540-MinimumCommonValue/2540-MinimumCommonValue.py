# Last updated: 5/19/2026, 8:35:47 PM
1class Solution:
2    def getCommon(self, nums1, nums2) :
3        n1, n2= len(nums1), len(nums2)
4        p1, p2=0, 0
5        while p1<n1 and p2<n2:
6            x=nums1[p1]
7            y=nums2[p2]
8            if x==y: return x
9            elif x>y: p2+=1
10            else: p1+=1
11        return -1
12        