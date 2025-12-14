#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

//744寻找比目标字母大的最小字母
char nextGreatestLetter(vector<char>& letters, char target) {
    int n=letters.size();
    int left=0,right=n-1;
    if(letters[n-1]<=target) return letters[0];
    while(left<=right)
    {   
        int mid=(right-left)/2+left;
        if(letters[mid]<=target) left=mid+1;
        else if(letters[mid]>target) right=mid-1;
    }
    return letters[left];   
}

//2529正整数和负整数的最大计数
int maximumCount(vector<int>& nums) {
    int pos=0,neg=0;
    // //法一：线性遍历
    // for(int num:nums)
    // {
    //     if(num>0) pos++;
    //     else if(num<0) neg++;
    // }
    int l=0,r=nums.size()-1;
    while(l<r)
    {
        if(nums[l]>0) pos++;
        else if(nums[l]<0) neg++;
        if(nums[r]>0) pos++;
        else if(nums[r]<0) neg++;
        l++;
        r--;
    }
    if(l==r)
    {
        if(nums[l]>0) pos++;
        else if(nums[l]<0) neg++;
    }
    
    return max(pos,neg);
}