//二分答案——求最小
//注意部分题目可以优化二分边界，减少二分次数，从而减少代码运行时间
//也可以找一个比较大的二分上界（不推荐）
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cmath>
#include<unordered_map>

using namespace std;

//1283使结果不超过阈值的最小除数
int fun(int n,vector<int> nums)
{
    int sum=0;
    for(int num:nums)
    {
        sum+=(num+n-1)/n;//计算向上取整
    }
    return sum;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int maxNum=INT_MIN/2;
    int ans=0;
    for(int num:nums)
    {
        maxNum=max(maxNum,num);
    }
    //区间为[1,maxNum];
    int l=1,r=maxNum;
    while(l<=r)
    {
        int mid=(r-l)/2+l;
        int val=fun(mid,nums);
        if(val>threshold)
        {
            l=mid+1;
        }
        else 
        {
            ans=mid;
            r=mid-1;
        }
    }
    return ans;
}

//2187完成旅途中的最小时间
long long minimumTime(vector<int>& time, int totalTrips) {
    long long ans=0;
    sort(time.begin(),time.end());
    long long max_time = min(1LL*time[0] * totalTrips,LLONG_MAX);
    long long l=1,r=max_time;
    while(l<=r)
    {
        long long middle = (r-l)/2+l;
        long long cur = 0;
        for(int i=0;i<time.size();i++)
        {
            cur+=middle/time[i];
        }
        if(cur>=totalTrips)
        {
            ans=middle;
            r=middle-1;
        }
        else
        {
            l=middle+1;
        }
    }       
    return ans;
}

int main()
{
    int n=5;
    vector<int> arr={1,2,3};
    cout<<minimumTime(arr,n)<<endl;
    return 0;
}
