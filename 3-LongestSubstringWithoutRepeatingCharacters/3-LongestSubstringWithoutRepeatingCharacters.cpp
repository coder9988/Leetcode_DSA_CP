// Last updated: 3/3/2026, 9:05:04 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int left = 0;
5        int maxlength = 0;
6        unordered_map<char,int> freq;
7        for(int right = 0;right<s.size();right++)
8        {
9            freq[s[right]]++;
10                while(freq[s[right]]>1)
11                {
12                    freq[s[left]]--;
13                    if(freq[s[left]]==0)
14                    {
15                        freq.erase(s[left]);
16                    }
17                    left++;
18                }
19                
20            maxlength = max(right-left+1,maxlength);
21        }
22        return maxlength;
23    }
24};