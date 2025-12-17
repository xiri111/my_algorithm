#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<climits>
#include<unordered_map>
using namespace std;

//461汉明距离
int hammingDistance(int x,int y)
{
    int num = x ^ y;
    //求num中1的为数
    int cnt=0;
    while(num)
    {
        num=num & (num-1);
        cnt++;
    }
    return cnt;
}

//190颠倒二进制位
int reverseBits(int n)
{
    int m=0;
    for(int i=0;i<32;i++)
    {
        m<<=1;
        m+=n&1;
        n>>=1;
    }
    return m;
}

//136只出现一次的数字
int singleNumber(vector<int> &nums)
{
    //前提知识：n^n=0; a ^ b = b ^ a;
    int ans=0;
    for(int num:nums)
    {
        ans^=num;
    }
    return ans;
}

//318最大单词长度乘积
int maxProduct(vector<string> &words)
{
    // //法一：暴力循环
    // int maxNum=0;
    // int len=words.size();
    // for(int i=0;i<len-1;i++)
    // {
    //     int len_i=words[i].size();
    //     unordered_map<char,int> hashmap;
    //     for(int m=0;m<len_i;m++)
    //     {
    //         hashmap[words[i][m]]++;
    //     }
    //     for(int j=i+1;j<len;j++)
    //     {
    //         //检查words[i]和words[j]中有没有公共字母
    //         //如果有，continue
    //         //如果没有，maxNum=max(maxNum,cur)
    //         int len_j=words[j].size();
    //         bool noHave=true;
    //         for(int n=0;n<len_j;n++)
    //         {
    //             if(hashmap.find(words[j][n])!=hashmap.end())
    //             {
    //                 noHave=false;
    //                 break;
    //             }
    //         }
    //         if(!noHave) continue;
    //         else maxNum=max(maxNum,len_i*len_j);
    //     }
    // }
    // return maxNum;

    //法二：位运算
    //怎么快速判断两个字母串中是否含有重复数字呢？
    //可以位每个字母串建立一个长度为26的二进制数字，0代表该位置没有该字母，1代表该位置有该字母
    int max_prod=0;
    int n=words.size();
    vector<int> mask(n,0);
    vector<int> len(n,0);
    for(int i=0;i<n;i++)
    {
        int m=0;
        for(char c:words[i])
        {
            m |= 1 << (c - 'a');
            //1 | 1 = 1,0 | 1 = 1
        }
        mask[i]=m;
        len[i]=(int)words[i].size();
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if((mask[i] & mask[j]) == 0) 
            {
                max_prod=max(max_prod,len[i]*len[j]);
            }
        }
    }
    return max_prod;
}

//338比特位计数
vector<int> countBits(int n)
{
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        int num=i;
        while(num)
        {
            num&=(num-1);
            cnt++;
        }
        arr[i]=cnt;
    }
    return arr;
}

//268丢失的数字
int missingNumber(vector<int>& nums)
{
    int num=0;
    for(int i=0;i<nums.size();i++)
    {
        num=num^(i+1)^nums[i];
    }
    return num;
}

//693交替位二进制数
bool hasAlternatingBits(int n)
{
    unsigned int x=n ^ (n>>1);
    //如果x全为1，则返回true，否则返回false
    return (x&(x+1))==0;
}

//476数字的补数
int findComplement(int num)
{
    
}