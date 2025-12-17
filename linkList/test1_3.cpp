//3.插入节点
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int val):val(val),next(nullptr){}
    ListNode(int val,ListNode* next):val(val),next(next){}
};

//2807在链表中插入最大公约数
//时间复杂度为O(min(num1,num2));
// int gcd(int num1,int num2)//求num1和num2的最大公约数
// {
//     int ans=1;
//     for(int i=2;i<=min(num1,num2);i++)
//     {
//         if(num1%i==0 && num2%i==0) ans=i;
//     }
//     return ans;
// }
//优化
//欧几里得算法（辗转相除）
//时间复杂度为O(log(min(num1,num2)));
//gcd是greatest common divisor的缩写
//lcm是leastest common multiple的缩写
int gcd(int num1,int num2)
{
    while(num2)
    {
        int t=num1%num2;
        num1=num2;
        num2=t;
    }
    return num1;
}
ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* cur=head;
    while(cur->next)
    {
        int num=gcd(cur->val,cur->next->val);
        ListNode* node=new ListNode(num,cur->next);
        cur->next=node;
        cur=cur->next->next;
    }
    return head;
}

//147对链表进行插入排序
//何为插入排序
//从左到右，每次把一个新元素，插入到前面已经排好序的部分中
//最好时间复杂度为o(n)  顺序
//最坏时间复杂度为o(n*n) 逆序
//平均每时间复杂度为o(n*n)
//空间复杂度为o(1)
//稳定排序
void insertionSort(vector<int>& a)
{
    int n=a.size();
    for(int i=1;i<n;i++)
    {
        int key=a[i];//当前要插入的元素
        int j=i-1;
        //把比key大的数往后挪
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        //放入key
        a[j+1]=key;
    }
}
ListNode* insertionSortList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* dummy=new ListNode(0);
    //dummy代表已排序链表的前驱
    dummy->next=nullptr;
    
    ListNode* cur=head;//当前待排序节点

    while(cur)
    {
        //保存cur的下一个节点，因为cur会被移动
        ListNode* post=cur->next;

        //在待排序链表中找到插入位置
        ListNode* prev=dummy;
        ListNode* node=dummy->next;

        //找到第一个大于等于cur值的节点
        while(node && node->val < cur->val)
        {
            prev=node;
            node=node->next;
        }

        //插入cur到正确位置
        prev->next=cur;
        cur->next=node;

        cur=post;
    }
    return dummy->next;
}

