#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
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

//1019链表中的下一个更大节点
//链表+单调栈
vector<int> nextLargerNodes(ListNode* head)
{
    //1.求链表长度len
    int len=0;
    for(auto p = head; p; p = p->next) len++;
    

    //2.
    stack<pair<int,int>> st;
    vector<int> ans(len,0);

    int index=0;
    while (head) 
    {
        while (!st.empty() && st.top().second < head->val) 
        {
            ans[st.top().first] = head->val;
            st.pop();
        }
        st.push({index, head->val});
        head = head->next;
        index++;
    }
    return ans;
}

