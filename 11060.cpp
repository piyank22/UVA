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
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
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

int n,m;
string str , trs;
vector<vi> adj;
int in_degree[110];
priority_queue< int,vi,greater<int> > pq;
vi ans;

map<string,int> for_m;
map<int,string> rev_m;

int main()
{   
    boost 
    int tc = 1;
    while( cin >> n)
    {
        adj = vector<vi>( n, vi() );
        for_m.clear();
        rev_m.clear();

        forr(i,0,n-1)
        {
            cin >> str;
            for_m[str] = i;
            rev_m[i] = str;
        }
        cin >> m;
        forr(i,0,m-1)
        {
            cin >> str >> trs;
            adj[ for_m[str] ].pb( for_m[trs] );
        }

        zero(in_degree);
        forr(i,0,n-1)
            for( auto v: adj[i] )
                in_degree[v] ++ ;

        pq = priority_queue < int , vi , greater<int> >();
        forr(i,0,n-1)
            if( in_degree[i] == 0 )
                pq.push(i);

        ans.clear();
        while( !pq.empty() )
        {
            int u = pq.top();
            pq.pop();
            ans.pb(u);
            for( auto v: adj[u] )
            {
                in_degree[v]--;
                if( in_degree[v] == 0 )
                    pq.push(v);
            }
        }

        cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order:"; 
        forr(i,0,sz(ans)-1)
            cout << " " << rev_m[ans[i]] ;
        cout << ".\n\n";
    }
    
    return 0;
}
