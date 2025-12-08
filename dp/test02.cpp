#include<iostream>
#include<vector>
#include<string>

using namespace std;

//62不同路径
int uniquePaths(int m,int n)
{
    //dp[i][j]表示从（0，0）开始，到（i，j）有多少条路径
    //状态转移方程：dp[i][j]=dp[i-1][j]+dp[i][j-1]
    vector<vector<int>> dp(m,vector<int>(n,0));
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m-1][n-1];
}

//64最小路径和
int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0]=grid[0][0];
    for(int i=1;i<m;i++) dp[i][0]=dp[i-1][0]+grid[i][0];   
    for(int j=1;j<n;j++) dp[0][j]=dp[0][j-1]+grid[0][j];
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
        }
    }   
    return dp[m-1][n-1];
}

//63不同路径II
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            
}