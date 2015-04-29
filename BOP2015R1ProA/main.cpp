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
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef vector<int> vi;
typedef pair<int, vi> pii;
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
int a[maxn], n, t, m, cnt;
bool v[maxn];
pii E[maxn];
void dfs(int i, int c)
{
    if(v[i]) return;
    v[i]=1;
    for(auto e: E[i].se)
    {
        if(v[e]) continue;
        if(E[e].fi!=c) dfs(e, E[e].fi),cnt++;
        else dfs(e, c);
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    //freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif

    cin>>t;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>n;
        //for(int i=0;i<=n;i++) E[i].clear();
        for(int i=0;i<=n;i++) E[i].fi=0, E[i].se.clear();
        for(int i=1;i<n;i++)
        {
            int x, y;
            scanf("%d%d", &x,&y);
            E[x].se.push_back(y);
            E[y].se.push_back(x);
        }
        memset(v, 0, sizeof(v));
        cnt=1;
        dfs(1, E[1].fi);int q;
        cin>>q;
        printf("Case #%d:\n", ti);
        for(int i=0;i<q;i++)
        {
            int type;
            cin>>type;
            if(type==1) cout<<cnt<<endl;
            else
            {
                int v, c;
                cin>>v>>c;
                if(c==E[v].fi) continue;
                int pre=0, cur=0;
                for(auto e: E[v].se)
                {
                    if(E[e].fi==E[v].fi) pre++;
                    else if(E[e].fi==c) cur++;
                }
                E[v].fi=c;
                cnt+=(pre-cur);
            }
        }
    }
	return 0;
}
