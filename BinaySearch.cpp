#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<climits>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define pb push_back
#define CLR(a,x) memset(a,x,sizeof(a))
/*
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {

    }
};
*/

//find any index that == v
int bs_findv(int a[], int n, int v)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>v)
            high=mid-1;
        else if(a[mid] < v)
            low=mid+1;
        else return mid;
    }
    return -1;
}
//find min i that == v
int bs_find_miniev(int a[], int n, int v)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        if(low == high) return a[low] == v ? low : -1;
        int mid=(low+high)/2;
        if(a[mid]>v)
            high=mid-1;
        else if(a[mid] < v)
            low=mid+1;
        else
            high=mid;
    }
    return -1;
}
//find maxi that == v
int bs_find_maxiev(int a[], int n, int v)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        if(low == high) return low;
        if(low + 1 == high) return a[high]==v ? high : (a[low] == v ? low : -1);
        int mid=(low+high)/2;
        if(a[mid]>v)
            high=mid-1;
        else if(a[mid] < v)
            low=mid+1;
        else
            low=mid;
    }
    return -1;
}
//find maxi that < v
int bs_find_maxilessv(int a[], int n, int v)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        if(low == high) return a[low] < v ? low : -1;
        if(low + 1 == high) return a[high] < v ? high : (a[low] < v ? low : -1);
        int mid=(low+high)/2;
        if(a[mid]>v)
            high=mid-1;
        else if(a[mid] < v)
            low=mid;
        else
            high=mid-1;
    }
    return -1;
}
//find mini that > v
int bs_find_minigreaterv(int a[], int n, int v)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        if(low == high) return a[low] > v ? low : -1;
        int mid=(low+high)/2;
        if(a[mid]>v)
            high=mid;
        else if(a[mid] < v)
            low=mid+1;
        else
            low=mid+1;
    }
    return -1;
}


int a[]={1,2,3,3,3,3,3,4,6,6,6,6};
int n;

int main()
{
    n=sizeof(a)/sizeof(int);
    int v=3;
    cout<<bs_findv(a,n,v)<<" "<<bs_find_miniev(a,n,v)<<" "<<bs_find_maxiev(a,n,v)<<" "<<bs_find_maxilessv(a,n,v)<<" "<<bs_find_minigreaterv(a,n,v)<<endl;
	return 0;
}
