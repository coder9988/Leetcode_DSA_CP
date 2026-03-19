// Last updated: 3/19/2026, 1:49:06 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    bool hasCycle(ListNode* head) {
12        map<ListNode*, int> visited;
13        while (head != NULL) {
14            if (visited[head] > 1) {
15                return true;
16            }
17                        visited[head]++;
18            head = head->next;
19
20        }
21        return false;
22    }
23};