//排序匹配
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
//55跳跃游戏
bool canJump(vector<int>& nums) {
    //判断最大覆盖范围是否大于等于nums.size()-1
    int cover=0;
    if(nums.size()==1) return true;
    for(int i=0;i<=cover;i++)
    {
        cover=max(cover,i+nums[i]);
        if(cover>=nums.size()-1) return true;
    } 
    return false;
}

//455分发饼干
int findContentChildren(vector<int>& g, vector<int>& s) {
    //关于sort函数的第三个参数
    //比较函数需要返回 bool 值
    //返回true，第一个参数在第二个参数前面
    //返回false，第二个参数在第一个参数前面

    //排序+双指针
    sort(s.begin(),s.end());
    sort(g.begin(),g.end());
    int i=0,j=0,cnt=0;
    while(i < (int)g.size() && j < (int)s.size())
    {
        if(s[j] >= g[i])
        {
            cnt++;
            i++;
            j++;
        }
        else j++;
    }
    return cnt;
}

//122买卖股票的最佳时机II
int maxProfit(vector<int>& prices) {
    int profit=0;
    for(size_t i=1;i<prices.size();i++)
    {
        if(prices[i]>prices[i-1])
        {
            //如果第二天价格比第一天高，则第一天买入，第二天卖出
            profit+=prices[i]-prices[i-1];
        }
    }    
    return profit;
}  

//376摆动序列
int wiggleMaxLength(vector<int>& nums) {
        
}