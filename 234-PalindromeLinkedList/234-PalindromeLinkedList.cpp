// Last updated: 10/7/2026, 11:06:16 PM
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
13    bool isPalindrome(ListNode* head) {
14        ListNode* slow = head;
15        ListNode* fast = head->next;
16        while(fast!=NULL && fast->next!=NULL)
17        {
18            slow = slow->next;
19            fast = fast->next->next;
20        }
21        ListNode* curr = slow->next;
22        ListNode* prev = nullptr;
23        while(curr!=nullptr)
24        {
25            ListNode* next = curr->next;
26            curr->next = prev;
27            prev = curr;
28            curr = next; 
29        }
30        while(prev!=nullptr)
31        {
32            if(head->val != prev->val)
33            {
34                return false;
35            }
36            head=head->next;
37            prev=prev->next;
38        }
39        return true;
40    }
41};