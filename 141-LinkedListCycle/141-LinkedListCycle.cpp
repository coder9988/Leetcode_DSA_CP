// Last updated: 3/19/2026, 1:46:25 PM
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
11    bool hasCycle(ListNode *head) {
12        map<ListNode*,int> visited ;
13        while(head!=NULL)
14        {
15            head = head->next;
16            visited[head]++;
17            if(visited[head]>1)
18            {
19                return true;
20            }
21        }
22        return false;
23    }
24};