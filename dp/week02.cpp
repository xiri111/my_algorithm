#include<iostream>
#include<vector>
#include<string>
#include<climits>

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
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    //如果在起点或者终点出现障碍，则直接返回0
    if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0]=1;
    for(int i=1;i<m;i++)
    {
        if(obstacleGrid[i][0]==1) 
        {
            break;
        }
        dp[i][0]=1;
    }       
    for(int j=1;j<n;j++)
    {
        if(obstacleGrid[0][j]==1) 
        {
            break;
        }
        dp[0][j]=1;
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(obstacleGrid[i][j]==1) continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }     
    return dp[m-1][n-1];
}

//120三角形最小路径和
int minimumTotal(vector<vector<int>>& triangle) {
    // //方法一：空间复杂度为n*n
    // int n=triangle.size();//n为三角形的行数
    // vector<vector<int>> dp;
    // for(int index = 1;index<=n;index++)
    // {
    //     vector<int> arr(index,0);
    //     dp.push_back(arr);
    // }
    // dp[0][0]=triangle[0][0];
    // for(int i=1;i<n;i++)
    // {
    //     dp[i][0]=dp[i-1][0] + triangle[i][0];
    //     dp[i][i]=dp[i-1][i-1] + triangle[i][i];
    //     for(int j=1;j<i;j++)
    //     {
    //         dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
    //     }
    // }
    // //求出dp[n-1]中最小的数
    // int ans=INT_MAX/2;
    // for(int k=0;k<n;k++)
    // {
    //     ans=min(ans,dp[n-1][k]);
    // }
    // return ans;

    //方法二：实现空间优化！
    int n=triangle.size();
    vector<int> dp=triangle.back();//把triangle的最后一行当作初始值
    //从倒数第二行开始向上计算
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
        }
    }
    return dp[0];
}

//931下降路径最小和
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size();       
    vector<int> dp=matrix.front();
    if(n==1) return matrix[0][0];
    vector<int> cur=dp;
    for(int i=1;i<n;i++)
    {
        cur[0]=min(dp[0],dp[1])+matrix[i][0];
        cur[n-1]=min(dp[n-1],dp[n-2])+matrix[i][n-1];
        for(int j=1;j<n-1;j++)
        {
            cur[j]=min(dp[j-1],min(dp[j],dp[j+1]))+matrix[i][j];
        }
        dp=cur;
    }
    int ans=INT_MAX/2;
    for(int num:dp)
    {
        ans=min(ans,num);
    }
    return ans;
}

//221最大正方形
int maximalSquare(vector<vector<char>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
        
}