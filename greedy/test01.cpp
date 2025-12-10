#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//455分发饼干
int findContentChildren(vector<int>& g, vector<int>& s) {
    //局部最优是大饼干给胃口大的孩子，充分利用饼干尺寸喂饱一个
    //全局最优是喂饱尽可能多的孩子

    //关于sort函数的第三个参数
    //比较函数需要返回 bool 值
    //返回true，第一个参数在第二个参数前面
    //返回false，第二个参数在第一个参数前面

    sort(s.begin(),s.end(),greater<int>());
    sort(g.begin(),g.end(),greater<int>());

    int ans=0;
    int s_index=0,g_index=0;
    for(g_index;g_index<g.size();g_index++)
    {
        if(s_index<s.size())
        {
            if(g[g_index]>s[s_index]) continue;
            else if(g[g_index]<=s[s_index]) 
            {
                ans++;
                s_index++;
            } 
        }
        else break;
    }
    return ans;
}

//376摆动序列
int wiggleMaxLength(vector<int>& nums) {
           
}