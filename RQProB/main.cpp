/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1000+10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
int getint(){
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    return !m ? n : GCD(n%m, m);
}
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
int dp[maxn][maxn], n, t, m;
const int MOD=100007;
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    iOS;
    cin>>t;string str;
    for(int ti=1;ti<=t;ti++)
    {
        memset(dp, 0 ,sizeof dp);
        cin>>str;int n=str.size();
        int ans=0;
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=0;i<n-1;i++)
        {
            if(str[i]==str[i+1])
                dp[i][i+1]=3;
            else dp[i][i+1]=2;
        }
        for(int l=3;l<=n;l++)
        {
            for(int i=0;i<n;i++)
            {
                int j=i+l-1;
                if(j>=n) continue;
                if(str[i]!=str[j]) dp[i][j]=(dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1])%MOD;
                else dp[i][j]=(dp[i+1][j]+dp[i][j-1]+1)%MOD;
            }
        }
        printf("Case #%d: %d\n", ti, dp[0][n-1]);
    }
	return 0;
}
