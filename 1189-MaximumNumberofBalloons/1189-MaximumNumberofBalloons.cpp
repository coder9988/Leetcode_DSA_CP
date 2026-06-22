// Last updated: 6/22/2026, 10:40:30 PM
1class Solution {
2public:
3    static int maxNumberOfBalloons(string& text) {
4        int freq[26]={0};
5        for(char c : text){
6            freq[c-'a']++;
7        }
8        return min({freq[0], freq[1], freq['l'-'a']>>1, freq['o'-'a']>>1, freq['n'-'a']});
9    }
10};