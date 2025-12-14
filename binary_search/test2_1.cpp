#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cmath>
#include<unordered_map>

using namespace std;

//二分答案——求最小
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
            
}
int main()
{
    int threshold=6;
    vector<int> nums={1,2,5,9};
    cout<<smallestDivisor(nums,threshold)<<endl;
    return 0;
}