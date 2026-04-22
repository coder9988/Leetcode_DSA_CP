// Last updated: 4/22/2026, 9:08:38 PM
1class Solution {
2public:
3    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
4        vector<string>ans;
5        int l=q[0].size();
6        for(int i=0;i<q.size();i++){
7            for(int j=0;j<d.size();j++){
8                int c=0;
9                for(int k=0;k<l;k++){
10                    if(q[i][k]!=d[j][k])c++;
11                }
12                if(c<=2){
13                    ans.push_back(q[i]);
14                    // avoid duplicates
15                    break;
16                }
17            }
18        }return ans;
19    }
20};