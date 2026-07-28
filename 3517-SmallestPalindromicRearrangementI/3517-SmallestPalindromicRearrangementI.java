// Last updated: 7/29/2026, 2:46:13 AM
1class Solution {
2    public String smallestPalindrome(String s) {
3        int n = s.length();
4
5        String middleChar = (n & 1) == 1
6                ? s.charAt(n / 2) + ""
7                : "";
8
9        StringBuilder half = new StringBuilder();
10        int[] hashTable = new int[26];
11
12        for(int i = 0; i < n / 2; i++){
13            hashTable[s.charAt(i) - 'a']++;
14        }
15
16        for(int i = 0; i < 26; i++){
17            half.append(
18                ((char)(i + 'a') + "").repeat(hashTable[i])
19            );
20        }
21
22        return half.toString()
23                + middleChar
24                + half.reverse().toString();
25    }
26}