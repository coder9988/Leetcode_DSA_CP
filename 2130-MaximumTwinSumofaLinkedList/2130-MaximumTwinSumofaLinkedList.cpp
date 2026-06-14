// Last updated: 6/15/2026, 12:50:22 AM
1class Solution {
2public:
3    int pairSum(ListNode* head) {
4        ListNode *slow = head, *fast = head;
5
6        // Find middle
7        while (fast && fast->next) {
8            slow = slow->next;
9            fast = fast->next->next;
10        }
11
12        // Reverse second half
13        ListNode *prev = nullptr;
14        while (slow) {
15            ListNode *nextNode = slow->next;
16            slow->next = prev;
17            prev = slow;
18            slow = nextNode;
19        }
20
21        // Calculate maximum twin sum
22        int ans = 0;
23        ListNode *first = head;
24        ListNode *second = prev;
25
26        while (second) {
27            ans = max(ans, first->val + second->val);
28            first = first->next;
29            second = second->next;
30        }
31
32        return ans;
33    }
34};