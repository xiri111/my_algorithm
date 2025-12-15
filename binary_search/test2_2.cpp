#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

int hIndex(vector<int>& citations) {
    int n=citations.size();
    int l=0,r=n;
    int ans=0;
    while(l<=r)
    {
        int mid = (r-l)/2+l;
        if(citations[mid]==mid+1)
        {
            return mid+1;
        }
        else if(citations[mid]<mid+1)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }        
    return -1;
}