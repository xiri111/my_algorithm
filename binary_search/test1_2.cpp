#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;

//2300咒语和药水的成功对数
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    vector<int> res;       
    int m=spells.size(),n=potions.size();
    sort(potions.begin(),potions.end());
    for(int i=0;i<m;i++)
    {
        int ans=0;
        int left=0,right=n-1;
        while(left<=right)
        {
            int mid=(right-left)/2+left;
            if(1ll*spells[i]*potions[mid]<success)
            {
                left=mid+1;
            }
            else if(1ll*spells[i]*potions[mid]>=success)
            {
                right=mid-1;
            }
        }

        res.push_back(n-left);
    }
    return res;
}

//1385两个数组间的距离值
int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    // int ans=0;
    // sort(arr2.begin(),arr2.end());
    // int m=arr1.size(),n=arr2.size();
    // //法一：双层for循环
    // // for(int i=0;i<m;i++)
    // // {
    // //     bool flag=true;
    // //     for(int j=0;j<n;j++)
    // //     {
    // //         if(abs(arr2[j]-arr1[i])<=d) 
    // //         {
    // //             flag=false;
    // //             break;
    // //         }
    // //     }
    // //     ans+=(flag?1:0);
    // // }

    // //法二：排序+二分查找
    // //遍历arr1，设x=arr1[i],判断arr2中是否存在元素 在区间[x-d,x+d]中
    // for(int i=0;i<m;i++)
    // {
    //     //使用lower_bound查找第一个不小于arr1[i]-d的元素位置
    //     //lower_bound的时间复杂度为logn
    //     auto it=lower_bound(arr2.begin(),arr2.end(),arr1[i]-d);

    //     //没找到或找到的元素大于arr1[i]-d
    //     if(it == arr2.end() || *it > arr1[i]+d)
    //         ans++;
    // }
    // return ans;

    //法三：排序+双指针
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    int ans=0;
}

//2389和有限的最长子序列
vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    vector<int> ans;
    sort(nums.begin(),nums.end());
    int m=nums.size(),n=queries.size();
    //求nums的前缀和数组prefix
    vector<int> prefix(m+1,0);
    for(int i=0;i<m;i++)
    {
        prefix[i+1]=prefix[i]+nums[i];
    }

    for(int i=0;i<n;i++)
    {
        int l=1,r=m;
        int len=0;
        while(l<=r)
        {
            int mid=(r-l)/2+l;
            if(prefix[mid]==queries[i])
            {
                len=mid;
                break;
            }
            else if(prefix[mid]>queries[i])
            {
                r=mid-1;
                len=l;
            }
            else
            {
                l=mid;
                len=l;
            }
        }
        ans.push_back(len);
    }        
    return ans;
}

int main()
{
    vector<int> nums = {4,5,2,1};
    vector<int> queries = {3,10,21};
    vector<int> ans = answerQueries(nums,queries);
    for(int num:ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}