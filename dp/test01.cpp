//1.斐波那契类型
#include<iostream>
#include<vector>
#include<algorithm>

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
    vector<int> dp(cost.size()+1,0);
    //dp[i]表示到第i个台阶所需的最小花费
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=cost.size();i++)
    {
        dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }
    return dp[cost.size()];
}

//198打家劫舍
int rob(vector<int>& nums) {
    //dp[i]：考虑下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i]。
    if(nums.size()==1) return nums[0];
    vector<int> dp(nums.size(),0);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<nums.size();i++)
    {
        dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[nums.size()-1];
}

//740删除并获得点数
int deleteAndEarn(vector<int>& nums) {
            
}