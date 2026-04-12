// Last updated: 4/12/2026, 2:04:56 PM
1class Solution {
2public:
3    string trafficSignal(int timer) {
4        if(timer==0) return "Green";
5        if(timer==30) return "Orange";
6        if(timer>30 && timer<=90)
7        {
8            return "Red";
9        }
10        else
11        {
12            return "Invalid";
13        }
14    }
15};