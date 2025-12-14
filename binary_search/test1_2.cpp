#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cmath>
#include<unordered_map>

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
        //二分查找：找到最后一个pefix[mid]<=queries[i]的位置
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(prefix[mid]<=queries[i])
            {
                //当前mid满足条件，更新len，并尝试更大的mid
                len=mid;
                l=mid+1;
            }
            else
            {
                //不满足条件，需要减小mid
                r=mid-1;
            }
        }
        ans.push_back(len);
        // //也可以直接使用upper_bound函数，找到第一个大于queries[i]的位置
        // for(int query:queries)
        // {
        //     auto it = upper_bound(prefix.begin(),prefix.end(),query);
        //     ans.push_back(it-prefix.begin()-1);
        // }
    }        
    return ans;
}

//1170比较字符串最小字母出现频次
int fun(string s)
{
    int minC = 'z'-'a';
    unordered_map<char,int> hashmap;
    for(int i=0;i<s.size();i++)
    {
        hashmap[s[i]]++;
        minC=min(minC,s[i]-'a');
    }
    char targetC=minC+'a'; 
    return hashmap[targetC];
}

vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> ans;
    int m=queries.size(),n=words.size();
    //把queries和words转化为int型数组，转换关系为f(n);
    vector<int> q_arr,w_arr;
    for(int i=0;i<m;i++)
    {
        int q_num=fun(queries[i]);
        q_arr.push_back(q_num);
    }
    for(int i=0;i<n;i++)
    {
        int w_num=fun(words[i]);
        w_arr.push_back(w_num);
    }
    
    sort(w_arr.begin(),w_arr.end());
    for(int i=0;i<m;i++)
    {
        int num=0;
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=(r-l)/2+l;
            if(w_arr[mid]>q_arr[i])
            {
                num=n-mid;
                r=mid-1;
            }
            else
            {   
                l=mid+1;
            }
        }
        ans.push_back(num);
    }
    return ans;
}

//2080区间内查询数字的频率
class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        
    }
    
    int query(int left, int right, int value) {
        
    }
};

//3488距离最小相等元素查询
vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            
}