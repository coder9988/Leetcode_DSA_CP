// Last updated: 5/5/2026, 8:30:32 PM
1class Solution {
2public:
3    ListNode* rotateRight(ListNode* head, int k) {
4        if (head==NULL) return NULL;
5        if (k==0) return head;
6        ListNode* cur=head, *first=head;
7        int n=1;
8        while(cur->next){
9            cur=cur->next;
10            n++;
11        } 
12        cur->next=first;
13        int pos=n+(-k)%n;
14        ListNode* ans=head, *prev;
15        for(int i=0; i<pos; i++){
16            prev=ans;
17            ans=ans->next;
18        }
19        prev->next=NULL;
20        return ans;    
21    }
22};