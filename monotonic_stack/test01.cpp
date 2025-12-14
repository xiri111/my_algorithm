#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

//一维数组，要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置
//此时我们要想到可以用单调栈
//时间复杂度为O(n)

//单调栈的本质是时间换空间
//用一个栈来记录我们遍历过的元素

//注意：
//1.单调栈里存放的元素是什么
//单调栈里只需要存放元素的下标即可，可通过T[i]来访问对应的元素

//2.单调栈里的元素是递增的，还是递减的（从栈头到栈底的顺序）
//若要求一个元素右边第一个更大的元素，单调栈是递增的
//若要求一个元素右边第一个更小的元素，单调栈是递减的

//3.注意三个判断条件
//即当前遍历的元素T[i]与栈顶元素T[st.top()]的大小关系

//739每日温度
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n=temperatures.size();
    vector<int> ans(n,0);
    stack<int> st;//单调递增栈
    st.push(0);
    for(int i=1;i<n;i++)
    {
        if(temperatures[i] <= temperatures[st.top()])
        {
            st.push(i);
        }
        else
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
    }   
    return ans; 
}

//496下一个更大的元素
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	////1.暴力算法
	//vector<int> result(nums1.size(), -1);
	//for (int i = 0; i < nums1.size(); i++)
	//{
	//	auto it = find(nums2.begin(), nums2.end(), nums1[i]);
	//	int index = distance(nums2.begin(), it);
	//	if (index == nums2.size()) break;
	//	for (int j = index + 1; j < nums2.size(); j++)
	//	{
	//		if (nums2[j] > nums1[i])
	//		{
	//			result[i] = nums2[j];
	//			break;
	//		}
	//	}
	//}
	//return result;
	
	//2.单调栈+哈希表
	vector<int> result;

	stack<int> st;
	unordered_map<int, int> hashmap;

	for (int num2 : nums2)
	{
		while (!st.empty() && num2 > st.top())
		{
			hashmap[st.top()] = num2;
			st.pop();
		}
		st.push(num2);
	}

	for (int num1 : nums1)
	{
		if (hashmap.count(num1))
			result.push_back(hashmap[num1]);
		else
			result.push_back(-1);
	}
	return result;
}


//503下一个更大的元素II
vector<int> nextGreaterElements(vector<int>& nums) {
	vector<int> result(nums.size(), -1);
	stack<int> st;
	for (int i = 0; i < nums.size(); i++)
	{
		while (!st.empty() && nums[st.top()] < nums[i])
		{
			result[st.top()] = nums[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < nums.size(); i++)
	{
		while (!st.empty() && nums[st.top()] < nums[i])
		{
			result[st.top()] = nums[i];
			st.pop();
		}
		st.push(i);
	}
	return result;
}

//42接雨水
int trap(vector<int>& height) {
    // //法一：前缀和（求前i个中的最大数）
    // int ans=0;
    // if(height.size()<=2) return 0;
    // //按照每列求雨水
    // vector<int> prefix1(height.size(),0);
    // vector<int> prefix2(height.size(),0);
    // prefix1[0]=height[0];
    // prefix2[height.size()-1]=height.back();
    // for(int i=1;i<height.size();i++)
    // {
    //     prefix1[i]=max(prefix1[i-1],height[i]);
    // }
    // for(int j=height.size()-2;j>=0;j--)
    // {
    //     prefix2[j]=max(prefix2[j+1],height[j]);
    // }
    // for(int i=1;i<height.size()-1;i++)
    // {
    //     //对于第i行，我们需要求[0,i-1]中的最大值a ，以及[i+1,height.size()-1]的最大值b
    //     //第i列雨水为max(min(a,b)-height[i],0)
    //     //为了方便，我们可以提前准备两个前缀和数组
    //     int a=prefix1[i-1],b=prefix2[i+1];
    //     ans+=max(min(a,b)-height[i],0);
    // }    
    // return ans;

    //法二：单调栈
    //注意，在法一中我们使用两个数组来寻找一个元素左侧的最大数和右侧的最大数
    //则我们可以想到单调栈

    //1.单调栈按照行的方向来计算雨水

    //2.单调栈内元素的顺序
	//如果当前元素大于栈头元素，则出现凹槽
	//此时栈头第二个元素是凹槽左边的柱子，栈头元素是凹槽，当前元素是凹槽右边的柱子

	//3.遇到相同高度的柱子
	//将旧元素弹出，将新元素加入

	//4.栈里保存的数值
	//存放下标

	stack<int> st;
	int ans=0;
	st.push(0);
	for(int i=1;i<height.size();i++)
	{
		//1.如果当前元素大于栈头元素
		if(height[i]>height[st.top()])
		{
			//弹栈
			while(!st.empty() && height[i]>height[st.top()])
			{
				int mid=st.top();
				st.pop();
				if(!st.empty())
				{
					int h=min(height[st.top()],height[i])-height[mid];
					int w=i-st.top()-1;
					ans+=h*w;
				}
			}
			st.push(i);
		}
		else if(height[i]<height[st.top()])
		{
			//入栈
			st.push(i);
		}
		else if(height[i]==height[st.top()])
		{
			st.pop();
			st.push(i);
		}
	}
		return ans;
}

//84柱状图中最大的矩形
int largestRectangleArea(vector<int>& heights) {
	// //1.暴力解法
	// int ans=INT_MIN;
	// for(int i=0;i<heights.size();i++)
	// {
	// 	int cur=0;
	// 	int left=i,right=i;
	// 	//从0遍历到i，找i左边第一个比它小的数
	// 	for(left;left>=0;left--)
	// 	{	
	// 		if(heights[left]<heights[i]) break;
	// 	}
	// 	left++;
	// 	//从i遍历到heights.size()-1,找i右边第一个比它小的数
	// 	for(right;right<heights.size()-1;right++)
	// 	{
	// 		if(heights[right]<heights[i]) break;
	// 	}
	// 	right--;
	// 	cur=heights[i]*(right-left+1);
	// 	ans=max(ans,cur);
	// }
	// return ans;

	//2.单调栈
	//我们想要求元素i左边第一个小于i的，以及右边第一个小于i的
	int ans=0;
	stack<int> st;
	st.push(0);
	//我们保证单调栈（从栈头到栈底是从大到小的
	int n=heights.size();
	for(int i=1;i<n;i++)
	{
		if(heights[i]>=heights[st.top()])
		{
			st.push(i);
		}
		else
		{
			
		}
	}
}

int main()
{
	vector<int> heights={2,1,5,6,2,3};
	cout<<largestRectangleArea(heights)<<endl;
	return 0;
}

