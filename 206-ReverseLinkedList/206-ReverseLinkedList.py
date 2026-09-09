# Last updated: 9/10/2026, 1:01:41 AM
1# Definition for singly-linked list.
2# class ListNode:
3#     def __init__(self, val=0, next=None):
4#         self.val = val
5#         self.next = next
6class Solution:
7    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
8        curr = head
9        prev = None
10        while(curr!=None):
11            nxt = curr.next
12            curr.next = prev
13            prev = curr
14            curr = nxt
15        return prev
16            
17        
18        