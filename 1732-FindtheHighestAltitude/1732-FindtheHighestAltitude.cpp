// Last updated: 6/20/2026, 1:42:59 AM
1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int max_height = 0;
5        int curr_height=0;
6
7        for(int i=0;i<gain.size();i++){
8            curr_height += gain[i];
9            if(curr_height> max_height) max_height = curr_height;
10        }
11
12        return max_height;
13    }
14};