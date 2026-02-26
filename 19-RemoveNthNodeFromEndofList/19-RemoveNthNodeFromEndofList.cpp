// Last updated: 2/26/2026, 11:27:48 PM
1class Solution {
2public:
3    ListNode* removeNthFromEnd(ListNode* head, int n) {
4        ListNode* res = new ListNode(0, head);
5        ListNode* dummy = res;
6
7        for (int i = 0; i < n; i++) {
8            head = head->next;
9        }
10
11        while (head != nullptr) {
12            head = head->next;
13            dummy = dummy->next;
14        }
15
16        dummy->next = dummy->next->next;
17
18        ListNode* result = res->next;
19        delete res;
20        return result;        
21    }
22};