#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//1356根据数字二进制下1的数目排序
//如何计算一个数的二进制中的1的数量
//方法1:直接计算n中1的数量
// static int bitCount(int n)
// {
//     int cnt=0;//计数器
//     while(n>0) 
//     {
//         if((n&1) == 1 ) cnt++;
//         n>>=1;//n向右移动一位
//     }
//     return cnt;
// }

//方法2：只循环n的二进制中的1的数量m,每次消掉最后一个1
static int bitCount(int n)
{
    int cnt=0;
    while(n)
    {
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

// static bool cmp(int a,int b)
// {
//     if(bitCount(a)<bitCount(b))
//         return true;
//     else if(bitCount(a)==bitCount(b)) 
//     {
//         if(a<b) return true;
//     }
//     return false;
// }

//也可以使用lambda表达式

//关于lambda表达式
//lambda表达式实际上是一个匿名类的成员函数
//该类由编译器为lambda创建，该函数被隐式地定义为内联
//因此，调用lambda表达式相当于直接调用它的operator()函数
//这个函数可以被编译器内联优化（建议）

//[capture clause] (parameters) mutable -> return-type { function body }

//编译器根据[]来判断接下来的代码是否为lambda函数
//捕捉列表能够捕捉上下文中的变量供lambda函数使用。

//默认情况下，lambda函数总是一个const函数，mutable可以取消其常量性
//使用该修饰符时，参数列表不可省略（即使参数为空）。
vector<int> sortByBits(vector<int>& arr) {
    // sort(arr.begin(),arr.end(),cmp);
    //对非静态成员函数的引用必须通过调用
    //cmp不能直接作为sort的第三个参数 
    sort(arr.begin(),arr.end(),[](int a,int b){
        int bitA=bitCount(a);
        int bitB=bitCount(b);
        if(bitA==bitB) 
            return a<b;
        return bitA<bitB;
    });
    return arr;
}