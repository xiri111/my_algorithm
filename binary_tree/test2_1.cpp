//遍历二叉树
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int val):val(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode* left,TreeNode* right):val(val),left(left),right(right){}
};

//144.二叉树的前序遍历
//时间复杂度为o(n),每一个节点恰好被遍历一次
//空间复杂度为o(n)，为递归中栈的开销
void preOrder(TreeNode* root,vector<int> &ans)
{
    if(root==nullptr) return ;
    ans.push_back(root->val);
    preOrder(root->left,ans);
    preOrder(root->right,ans);
}
vector<int> preOrderTravelsal(TreeNode* root)
{
    vector<int> ans;
    preOrder(root,ans);
    return ans;
}

//94.二叉树的中序遍历
void inOrder(TreeNode* root, vector<int>& ans)
{
	if (root == nullptr) return;
	inOrder(root->left, ans);
	ans.push_back(root->val);
	inOrder(root->right, ans);
}
vector<int> inorderTraversal(TreeNode* root) 
{
	vector<int> ans;
	inOrder(root, ans);
	return ans;
} 

//145二叉树的后序遍历
void postOrder(TreeNode* root, vector<int>& ans)
{
	if (root == nullptr) return;
	postOrder(root->left, ans);
	postOrder(root->right, ans);
	ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root)
{
	vector<int> ans;
	postOrder(root, ans);
	return ans;
}

//872叶子相似的树
//求二叉树的叶子节点
void getLeaves(TreeNode* head,vector<int>& ans)
{
    if(head==nullptr) return;
    if(head->left==nullptr && head->right==nullptr)
    {
        ans.push_back(head->val);
    }
    getLeaves(head->left,ans);
    getLeaves(head->right,ans);
}
bool leafSimilar(TreeNode* root1,TreeNode* root2)
{
    vector<int> ans1,ans2;
    getLeaves(root1,ans1);
    getLeaves(root2,ans2);
    return ans1==ans2;
}

//Lcp44开幕式焰火
void dfs(TreeNode* root,unordered_set<int>& seen)
{
    if(root==nullptr) return;
    seen.insert(root->val);
    dfs(root->left,seen);
    dfs(root->right,seen);
}
int numColor(TreeNode* root)
{
    unordered_set<int> seen;
    dfs(root,seen);
    return (int)seen.size();
}
