//4.反转链表
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

//206反转链表
//原地反转
ListNode* reverseList(ListNode* head)
{
    ListNode* prev=nullptr;
    ListNode* cur=head;

    while(cur)
    {
        ListNode* nextNode=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextNode;
    }

    return prev;
}

//92反转链表II
ListNode* reverseBetween(ListNode* head,int left,int right)
{
    if(!head || left==right) return head;

    ListNode* dummy=new ListNode(0,head);
    ListNode* prevL=dummy;
    for(int i=0;i<left-1;i++)
    {
        prevL=prevL->next;
    }
    ListNode* cur=prevL->next;

    //头插right-left次：每次把cur后面的节点搬到prevL后面
    for(int i=0;i<right-left;i++)
    {   
        ListNode* move=cur->next;
        cur->next=move->next;//摘掉move
        move->next=prevL->next;
        prevL->next=move;
    }
    return dummy->next;
}