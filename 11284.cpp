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
#define trace_mat(a,i,n,j,m) cerr << #a <<" :\n" ; forr(_i,i,n) { forr(_j,j,m) cerr << setw(6) << a[_i][_j] << " "; cerr << endl; } cerr << endl;
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


#define inf 1e9

int n,m,p;
int dis[55][55];
int store[15];
int price[15];

int memo[55][(1<<13)+100];

int solve(int pos,int mask)
{
    if( mask == (1<<p)-1 )  return -dis[pos][0]; 

    int &ret = memo[pos][mask];
    if( ret != inf )        return ret;
    ret = -dis[pos][0];
    forr(i,0,p-1)
        if( (mask & (1<<i) ) == 0 )
            ret = max( ret , price[i] - dis[pos][store[i]] + solve( store[i],mask|(1<<i) ) );

    return ret;
}

int main()
{   
    test_case
    {
        cin >> n >> m;
        forr(i,0,n)     forr(j,0,n)     dis[i][j] = ( i==j ? 0 : inf );    
        forr(i,1,m)
        {
            int u,v;
            double pr;
            cin >> u >> v >> pr;
            dis[v][u] = dis[u][v] = min( dis[u][v] , (int)round(pr*100) );
        }
        n++;

        // all pair shortest path problem
        // floyd warshall
        forr(c,0,n-1)
            forr(i,0,n-1)   
                forr(j,0,n-1)
                    dis[i][j] = min( dis[i][j] , dis[i][c] + dis[c][j] );

        cin >> p;
        forr(i,0,p-1)
        {
            double temp;
            cin >> store[i] >> temp;
            price[i] = round(100*temp);
        }   

        forr(i,0,n-1)   forr(j,0,(1<<p)-1)  memo[i][j] = inf;
        int ans = solve(0,0);
        if( ans == 0 )     cout << "Don't leave the house\n";
        else
        {
            cout << "Daniel can save $";   
            printf("%.2lf\n",ans/100.0 );
        }
    }
    return 0;
}