/*******************
AUTHOR: HUMBLE_LOSER
*******************/

#include <iostream>
#include <cstdio>
#include <math.h>
#include <ctime>
#include <bitset>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define PI acos(-1)
#define EXP 2.7182818284590452353602874713527
#define endl '\n'
#define ll long long
#define llu long long unsigned
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define sz(v) int(v.size())
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
#define rep(i,n) for(int i=0 ; i<int(n) ; i++ )
#define all(v) (v).begin(),(v).end()
#define INF 0x3fffffff
#define ten9 1000000000
#define mod 1000000007
#define zero(x) memset(&x,0,sizeof(x))
#define minus(x) memset(&x,0xff,sizeof(x))
#define boost cin.tie(0); ios_base::sync_with_stdio(0) ; 
#define trace1(x) cerr << #x <<" = "<< x <<endl;
#define trace2(x,y) cerr << #x <<" = "<< x <<" , "<< #y <<" = "<< y <<endl;
#define trace3(x,y,z) cerr << #x <<" = "<< x <<" , "<< #y <<" = "<< y <<" , "<< #z <<" = "<< z <<endl;
#define trace_arr(a,i,n) cerr << #a <<" : " ; forr(_i,i,n) cerr << a[_i] << " "; cerr << endl;
#define trace_mat(a,i,n,j,m) cerr << #a <<" :\n" ; forr(_i,i,n) { forr(_j,j,m) cerr << a[_i][_j] << " "; cerr << endl; } cerr << endl;
#define test_case int __T;cin >> __T; forr(tc, 1 , __T)		

template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

pii arr[45];
int dp[310][310];

int main()
{   
    int m,s;
    test_case
    {
        cin >> m >> s;
        forr(i,0,m-1)
        {
            int u,v;
            cin >> u >> v;
            arr[i] = {u,v};
        }

        forr(i,0,s)     forr(j,0,s)     dp[i][j] = 1e9;
        
        dp[0][0]=0;
        forr(i,0,m-1)
        {
            int u,v;
            u = arr[i].xx;
            v = arr[i].yy;
            forr(x,u,s)
                forr(y,v,s)
                    dp[x][y] = min( dp[x][y] , 1+dp[x-u][y-v] );
        }

        int ans = 1e9;
        forr(i,0,s)     forr(j,0,s)     if( i*i + j*j == s*s )      ans = min( ans , dp[i][j] );
        if(ans==1e9)    cout<<"not possible\n";
        else            cout<<ans<<endl;
    }
    return 0;
}