// Last updated: 4/6/2026, 9:11:21 PM
1class Solution {
2public:
3    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
4
5        // dir represents current direction
6        // 0 = North, 1 = East, 2 = South, 3 = West
7        int dir = 0;
8
9        // Store obstacles for quick lookup
10        map<pair<int,int>, bool> mp;
11        for(auto it : obstacles){
12            mp[{it[0], it[1]}] = true;
13        }
14
15        // Current position of robot
16        int x = 0, y = 0;
17
18        // Maximum distance squared from origin
19        int ans = 0;
20
21        for(auto it : commands){
22
23            // Handle turning commands
24            if(it < 0){
25                if(it == -1) 
26                    dir = (dir + 1) % 4;        // turn right
27                else 
28                    dir = (dir - 1 + 4) % 4;    // turn left
29            }
30
31            // Handle forward movement
32            else{
33
34                // Moving North
35                if(dir == 0){
36                    int maxi = y + it;
37
38                    // Move step-by-step until obstacle or limit reached
39                    while(y < maxi && !mp[{x, y+1}])
40                        y++;
41                }
42
43                // Moving East
44                else if(dir == 1){
45                    int maxi = x + it;
46
47                    while(x < maxi && !mp[{x+1, y}])
48                        x++;
49                }
50
51                // Moving South
52                else if(dir == 2){
53                    int mini = y - it;
54
55                    while(y > mini && !mp[{x, y-1}])
56                        y--;
57                }
58
59                // Moving West
60                else if(dir == 3){
61                    int mini = x - it;
62
63                    while(x > mini && !mp[{x-1, y}])
64                        x--;
65                }
66
67                // Update maximum squared distance
68                ans = max(ans, x*x + y*y);
69            }
70        }
71
72        return ans;
73    }
74};