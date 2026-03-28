// Last updated: 3/28/2026, 11:05:25 PM
1class Solution {
2public:
3    string findTheString(vector<vector<int>>& lcp) {
4        int n=lcp.size();
5        string ans(n,0);
6        char ch='a';
7        for(int i=0;i<n;i++){
8            if(ans[i]!=0)continue;
9            if(ch>'z')return "";
10            for(int j=i;j<n;j++){
11                if(lcp[i][j])ans[j]=ch;
12            }
13            ch++;
14        }
15        vector<vector<int>>mat(n+1,vector<int>(n+1,0));
16        for(int i=n-1;i>=0;i--){
17            for(int j=n-1;j>=0;j--){
18                if(ans[i]==ans[j])mat[i][j]=mat[i+1][j+1]+1;
19                else mat[i][j]=0;
20                if(mat[i][j]!=lcp[i][j])return "";
21            }
22        }
23        return ans;
24    }
25};