// Last updated: 6/21/2026, 8:17:15 PM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& numbers, int target) {
4        vector<int>ans;
5
6        int st = 0;
7        int end = numbers.size()-1;
8
9        while(st < end){
10            int sum = numbers[st] + numbers[end];
11
12            if(sum == target){
13                return {st+1, end+1};
14
15            }else if(sum < target){
16                st++;
17            }else{
18                end--;
19            }
20        }
21
22        return {};
23    }
24};