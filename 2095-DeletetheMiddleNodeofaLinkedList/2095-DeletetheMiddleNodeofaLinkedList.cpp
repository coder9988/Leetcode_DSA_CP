// Last updated: 6/16/2026, 12:00:49 AM
1class Solution {
2public:
3    ListNode* deleteMiddle(ListNode* head) {
4        if (!head->next) return nullptr;
5
6        ListNode* slow = head;
7        ListNode* fast = slow->next->next;
8
9        while (fast && fast->next) {
10            slow = slow->next;
11            fast = fast->next->next;
12        }
13
14        slow->next = slow->next->next;
15        return head;
16    }
17};
18
19
20
21// Memory Deallocation
22// LeetCode environment automatically frees the bypassed middle node