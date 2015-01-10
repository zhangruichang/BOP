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
#include<list>
#include<ctime>
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

int BS(int A[], int n, int x)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(A[mid] < x) low=mid+1;
        else if(A[mid] > x) high=mid-1;
        else
            return mid;
    }
    return -1;
}

int BS_MaxIEqualX(int A[], int n, int x)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        if(low==high) return A[low]==x ? low : -1;
        if(low+1==high) return A[high]==x ? high : (A[low]==x ? low : -1);//two ele not process, may nonterminal loop
        int mid=(low+high)/2;
        if(A[mid] < x) low=mid+1;
        else if(A[mid] > x) high=mid-1;
        else
            low=mid;
    }
    return -1;
}

int BS_MinIEqualX(int A[], int n, int x)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        if(low==high) return A[low]==x ? low : -1;
        int mid=(low+high)/2;
        if(A[mid] < x) low=mid+1;
        else if(A[mid] > x) high=mid-1;
        else high=mid;
    }
    return -1;
}

int BS_MaxILowerX(int A[], int n, int x)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        if(low==high) return A[low]<x ? low : -1;
        if(low+1==high) return A[high] < x ? high : (A[low] < x ? low : -1);
        int mid=(low+high)/2;
        if(A[mid] < x) low=mid;
        else high=mid-1;
    }//do not exit loop
}

int BS_MinIHigherX(int A[], int n, int x)
{
    int low=0, high=n-1;
    while(low<=high)
    {
        if(low==high) return A[low]>x ? low : -1;
        //if(low+1==high) return A[high] < x ? high : (A[low] < x ? low : -1);
        int mid=(low+high)/2;
        if(A[mid] <= x) low=mid+1;
        else high=mid;
    }//do not exit loop
}

int main()
{
    int A[]={1,2,3,4,4,4,4,5,5,5,5,6,6,7,8,9,9};
    int n=sizeof(A)/sizeof(int);cout<<n<<endl;
    int x=-100;
    cout<<BS(A, n, x)<<endl<<BS_MaxIEqualX(A,n,x)<<endl<<BS_MinIEqualX(A,n,x)<<endl<<BS_MaxILowerX(A,n,x)
    <<endl<<BS_MinIHigherX(A,n,x)<<endl;
	return 0;
}
