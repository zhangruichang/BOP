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
const int maxn = 1e6 + 10;
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
int a[maxn], n, t, m;
bool isLeap(int year)
{
    return (year%4==0 && year%100) || year%400==0;
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    iOS;
    unordered_map<string, int> hash={{"January", 1},{"February", 2},{"March", 3},{"April", 4},{"May", 5},
    {"June", 6},{"July", 7},{"August", 8},{"September", 9},{"October", 10},{"November", 11},{"December", 12}};
    cin>>t;
    string mon_s1, mon_s2, dou;
    int day1, year1, day2, year2;
    for(int ti=1;ti<=t;ti++)
    {
        cin>>mon_s1>>day1;
        cin>>dou;
        cin>>year1;
        //cout<<mon_s1<<" "<<day1<<" "<<year1<<endl;
        int mon_t1=hash[mon_s1];
        cin>>mon_s2>>day2;
        cin>>dou;
        cin>>year2;
        int mon_t2=hash[mon_s2];
        int ans=0;
        if(year2-1>=year1+1)
            ans=((year2-1)/4-year1/4)-((year2-1)/100-year1/100)+((year2-1)/400-year1/400);
        if(year1<year2)
        {
            if(isLeap(year1) && (mon_t1<2 || mon_t1==2 && day1<=29)) ans++;
            if(isLeap(year2) && (mon_t2>2 || mon_t2==2 && day2>=29)) ans++;
        }
        else if(year1==year2 && isLeap(year1))
        {
            if( (mon_t1<2 || mon_t1==2 && day1<=29)
               && (mon_t2>2 || mon_t2==2 && day2>=29)) ans++;
        }
        printf("Case #%d: %d\n", ti, ans);
    }
	return 0;
}
