//1.入门篇-建立dp思维
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

//509斐波那契数
int fib(int n) 
{
    if(n<=1) return n;
    //1.确定dp数组以及下标的含义,第i个数的斐波那契数值是dp[i]
    vector<int> dp(n+1,0);
    //3.确定初始化值
    dp[0]=0;
    dp[1]=1;
    //4.确定遍历顺序
    for(int i=2;i<=n;i++)
    {
        //2.确定递推公式
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
    //5.举例推导dp数组
}

//1137第N个泰波那契数
int tribonacci(int n) 
{
    if(n<=1) return n;
    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

//70爬楼梯
int climbStairs(int n)
{
   if(n<=2) return n;
   vector<int> dp(n+1,0);
   dp[1]=1;
   dp[2]=2;
   for(int i=3;i<=n;i++)
   {
      dp[i]=dp[i-1]+dp[i-2];
   }   
   return dp[n];
}

//746使用最小花费爬楼梯
int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    vector<int> dp(n+1,0);
    dp[0]=0,dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }
    return dp[n];
}

//198打家劫舍
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    vector<int> dp(n,0);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1];
}

//213打家劫舍II
//拆环为链
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);

    //2种情况
    //1.偷第一家，必不偷最后一家
    vector<int> dp1(n-1,0);
    dp1[0]=nums[0];
    dp1[1]=nums[0];
    for(int i=2;i<n-1;i++){
        dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
    }

    //2.不偷第一家，可以偷最后一家
    vector<int> dp2(n,0);
    dp2[1]=nums[1];
    dp2[2]=max(nums[1],nums[2]);
    for(int i=3;i<n;i++){
        dp2[i]=max(dp2[i-1],dp2[i-2]+nums[i]);
    }

    return max(dp1[n-2],dp2[n-1]);
}

//740删除并获得点数
//本题本质上是打家劫舍，通过对sum数组预处理即可
//如果访问了数字x，就不能访问x+1和x-1
int deleteAndEarn(vector<int>& nums) {
    //先统计每个数字的总价值
    int maxValue=*max_element(nums.begin(),nums.end());
    vector<int> sum(maxValue+1,0);
    for(int i=0;i<nums.size();i++){
        sum[nums[i]]+=nums[i];
    }
    //2.对sum数组做遍历操作
    if(maxValue==1) return sum[1];
    if(maxValue==2) return max(sum[1],sum[2]);
    vector<int> dp(maxValue+1,0);
    dp[1]=sum[1];
    dp[2]=max(sum[1],sum[2]);
    for(int i=3;i<=maxValue;i++){
        dp[i]=max(dp[i-1],dp[i-2]+sum[i]);
    }
    return dp[maxValue];
}