//2.删除节点
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

//203移出链表元素
ListNode* removeElements(ListNode* head,int val)
{
    ListNode* dummy=new ListNode(0,head);
    ListNode* prev=dummy,* cur=head;
    
    while(cur)
    {
        if(cur->val==val)
        {
            ListNode* toDelete = cur;
            cur=cur->next;
            prev->next=cur;
            delete toDelete;//在断链前把要删的节点保存下来并delete
        }
        else
        {
            prev=cur;
            cur=cur->next;
        }
    }
    ListNode* result=dummy->next;
    delete dummy;
    return result;
}

//3217从链表中移除在数组中存在的节点
ListNode* modifiedList(vector<int>& nums,ListNode* head)
{
    sort(nums.begin(),nums.end());
    ListNode* dummy=new ListNode(0,head);
    ListNode* prev=dummy,* cur=head;
    while(cur)
    {
        bool flag = binary_search(nums.begin(), nums.end(), cur->val);
      
        if(!flag)
        {
            prev=cur;
            cur=cur->next;
        }
        else
        {
            cur=cur->next;
            prev->next=cur;
        }
    }
    ListNode* result=dummy->next;
    delete dummy;
    return result;
}
//为什么我断链+delete会报错？
//答：我的链表逻辑没错，而是平台的内存管理方式和我手动delete冲突了

//83删除排序链表中的重复元素
//思路：当cur->val == cur->next->val时，删除节点cur->next;
ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *cur=head;
    while(cur->next)
    {
        if(cur->val == cur->next->val)
        {
            cur->next=cur->next->next;
        }
        else
        {
            cur=cur->next;
        }
    }       
    return head;
}
//82删除排序链表中的重复元素II
ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* dummy=new ListNode(0,head);
    ListNode* prev=dummy;
    ListNode* cur=head;
    //用节点cur来扫描，遇到重复就跳过整段，否则就把它接到链表尾部
    while(cur)
    {
        bool dup=false;
        while(cur->next && cur->val==cur->next->val)
        {
            dup=true;
            cur=cur->next;
        }
        if(dup)
        {
            cur=cur->next;
            prev->next=cur;
        }
        else
        {
            prev=cur;
            cur=cur->next;
        }
    }
    return dummy->next;
}

//237删除链表中的节点
void deleteNode(ListNode* node)
{

}

//1669合并两个链表
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    //创建虚拟头节点
    ListNode* dummy=new ListNode(0,list1);
    ListNode* prev_a=dummy;
    ListNode* post_b=dummy;

    //同时找到a-1 和 b+1的位置
    for(int i=0;i<a;i++)
    {
        prev_a=prev_a->next;
    }
    for(int i=0;i<=b+1;i++)
    {
        post_b=post_b->next;
    }

    //把list2插入到prev_a和post_b之间
    ListNode* node=list2;
    while(node->next)
    {
        node=node->next;
    }
    prev_a->next=list2;
    node->next=post_b;
    
    return dummy->next;
}

