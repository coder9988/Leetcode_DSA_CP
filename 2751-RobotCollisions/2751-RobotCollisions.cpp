// Last updated: 4/1/2026, 10:57:00 PM
1class Solution {
2public:
3    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
4        int n = positions.size();
5        vector<int> order(n) ;
6        iota(order.begin(), order.end(), 0);
7        sort(order.begin(), order.end(), [&](int a, int b){
8            return positions[a] < positions[b];
9        });
10
11        stack<int> st;
12        vector<bool> dead(n, false);
13
14        for (int i : order) {
15            if (directions[i] == 'R') {
16                st.push(i) ;
17            } else {
18                while (!st.empty() && directions[st.top()] == 'R') {
19                    int top = st.top();
20                    if (healths[top] > healths[i]) {
21                        healths[top]-- ;
22                        dead[i] = true;
23                        break;
24                    } else if (healths[top] < healths[i]) {
25                        healths[i]--;
26                        dead[top] = true ;
27                        st.pop();
28                    } else {
29                        dead[i] = true;
30                        dead[top] = true ;
31                        st.pop();
32                        break;
33                    }
34                }
35                if (!dead[i]) st.push(i);
36            }
37        }
38
39        vector<int> result;
40        for (int i = 0; i < n; i++)
41            if (!dead[i]) result.push_back(healths[i]) ;
42
43        return result;
44    }
45};