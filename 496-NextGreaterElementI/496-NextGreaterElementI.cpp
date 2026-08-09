// Last updated: 8/9/2026, 7:20:47 PM
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        int i = 0;
5        stack<int> st;
6        vector<int> ans;
7        unordered_map<int,int> next;
8        for(int i =0;i<nums2.size();i++)
9        {
10            while(!st.empty() && st.top() < nums2[i] )
11            {
12                next[st.top()] = nums2[i];
13                st.pop();
14            }
15            st.push(nums2[i]);
16        }
17        while(!st.empty())
18        {
19            next[st.top()] = -1;
20            st.pop();
21        }
22        for(int x:nums1)
23        {
24            ans.push_back(next[x]);
25        }
26        return ans;
27    }
28};