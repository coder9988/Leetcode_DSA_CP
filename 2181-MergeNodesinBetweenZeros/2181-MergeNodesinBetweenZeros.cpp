// Last updated: 3/19/2026, 1:23:06 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    void solve(ListNode* end,int sum,ListNode* &ans)
14    {
15        while(end!=NULL)
16        {
17            if(end->val==0)
18            {
19                ans->next = new ListNode(sum);
20                ans = ans->next;
21                sum = 0;
22            }
23            else
24            {
25                sum += end->val;
26            }
27            end = end->next;
28        }
29    }
30    ListNode* mergeNodes(ListNode* head) {
31        ListNode* dummy = new ListNode(0);
32        ListNode* ans = dummy;
33        int sum = 0;
34        solve(head->next,sum,ans);
35        return dummy->next;
36    }
37
38};