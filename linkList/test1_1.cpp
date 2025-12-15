//1.遍历链表

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int val):val(val),next(nullptr){}
    ListNode(int val,ListNode* next):val(val),next(next){}
};

//1290二进制链表转整数
int getDecimalValue(ListNode* head)
{
    int ans=0;
    while(head)
    {
        ans=ans*2+head->val;
        head=head->next;
    }
    return ans;
}
//2058找出临界点之间的最小和最大距离
vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    int maxDist=INT_MIN/2,minDist=INT_MAX/2;
    vector<int> arr;//用来记录临界点的下标
    int preNum=0,curNum=0,nextNum=0;
    int index=0;
    while(head)
    {
        if(preNum==0)//说明当前节点是第一个节点
        {
            preNum=head->val;
            head=head->next;
            index++;
        }
        else if(head->next==nullptr)
        {
            break;
        }
        else
        {
            curNum=head->val;
            head=head->next;
            nextNum=head->val;
            if((curNum>nextNum && curNum>preNum)||(curNum<nextNum && curNum<preNum))
            {
                arr.push_back(index);
            }
            index++;
            preNum=curNum;
        }
    }
    int n=arr.size();
    if(n<2) return {-1,-1};
    else
    {
        maxDist=arr[n-1]-arr[0];
        for(int i=1;i<n;i++)
        {
            minDist=min(minDist,arr[i]-arr[i-1]);
        }
        return {minDist,maxDist};
    }       
}

//2181合并0之间的节点
ListNode* mergeNodes(ListNode* head) {
    ListNode* dummy=new ListNode();
    ListNode* tail=dummy;
    int sum=0;
    for(ListNode* cur=head->next;cur;cur=cur->next)
    {
        if(cur->val==0)
        {
            ListNode* node=new ListNode(sum);
            sum=0;
            tail->next=node;
            tail=node;
        }
        else
        {
            sum+=cur->val;
        }
    }
    ListNode* result =dummy->next;
    delete dummy;
    return result;
}

//725分隔链表
vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
}