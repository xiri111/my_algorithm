//5.指针问题
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

//1721.交换链表中的节点
//前后指针
ListNode* swapNodes(ListNode* head, int k) {
    if(!head || !head->next) return head;
    ListNode* dummy=new ListNode(0,head);
    //求出链表的长度
    int len=0;
    ListNode* p=head;
    while(p)
    {
        p=p->next;
        len++;
    }
    //找到第k个节点和第len-k+1个节点
    ListNode* p1=dummy,* p2=dummy;
    for(int i=0;i<k;i++)
    {
        p1=p1->next;
    }
    for(int i=0;i<len-k+1;i++)
    {
        p2=p2->next;
    }
    //交换节点的值
    swap(p1->val,p2->val);

    return dummy->next;
}

//876链表的中间节点
//快慢指针
ListNode* middleNode(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;

    //右中点判断条件
    //只要fast还能往后走一步或两步，slow就可以向后走一步
    //奇数情况下，fast->next=nullptr
    //偶数情况下，fast=nullptr
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    //如果是左中点的判断条件呢
    //奇数情况下,fast->next=nullptr
    //偶数情况下，fast->next->next=nullptr
    // while(fast->next && fast->next->next)
    // {
    //     slow=slow->next;
    //     fast=fast->next->next;
    // }
    return slow;
}

//2095删除链表的中间节点
ListNode* deleteMiddle(ListNode* head) {
    //删除右中点
    //如何删除一个节点：找到该节点的前一个节点
    ListNode* dummy=new ListNode(0,head);
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* pre_slow=dummy;
    while(fast && fast->next)
    {
        slow=slow->next;
        pre_slow=pre_slow->next;
        fast=fast->next->next;
    }
    pre_slow->next=pre_slow->next->next;
    return dummy->next;
}

//234回文链表
//关于反转链表，需处理好以下3个指针
//prev，curr，post
ListNode* reverse(ListNode* head)
{
    ListNode* prev=nullptr;//已经反转好的那一段的头
    ListNode* curr=head;//当前正在处理的节点

    while(curr)
    {
        ListNode* post=curr->next;//保存后继节点
        curr->next=prev;//反转指针
        prev=curr;//prev前进
        curr=post;//curr前进
    }
    return prev;
}
bool isPalindrome(ListNode* head)
{
    // //一般思路，将链表转化为数组
    // vector<int> arr;
    // while(head)
    // {
    //     arr.push_back(head->val);
    //     head=head->next;
    // }
    // int n=arr.size();
    // int left=0,right=n-1;
    // while(left<right)
    // {
    //     if(arr[left]==arr[right])
    //     {
    //         left++;
    //         right--;
    //     }
    //     else
    //         return false;
    // }
    // return true;

    //能否用o(n)时间复杂度和o(1)空间复杂度解题
    //链表只能从前往后遍历，如何对称比较？
    //反转链表
    if(!head || !head->next) return true;
    //1.用快慢指针找到中点
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    //2.反转后半部分链表
    ListNode* node = reverse(slow);
    //3.前半部分和后半部分逐个比较
    ListNode* p1=head;
    ListNode* p2=node;
    while(p1 && p2)
    {
        if(p1->val !=p2->val)   return false;
        p1=p1->next;
        p2=p2->next;
    }
    return true;
}

//2130链表最大孪生和
int pairSum(ListNode* head)
{
    //此题和234题类似,借用reverse函数
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    ListNode* node=reverse(slow);
    int ans=0;
    ListNode* p1=head;
    ListNode* p2=node;
    while(p1&&p2)
    {
        ans=max(ans,p1->val+p2->val);
        p1=p1->next;
        p2=p2->next;
    }
    return ans;
}

//143重排链表
void reorderList(ListNode* head) {
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast && fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }        
    ListNode* node=reverse(slow);
    ListNode* p1=head;
    ListNode* p2=node;
    while(p1 && p2)
    {
        
    }
}