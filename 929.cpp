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

int x_dir[4] = { -1,0,1,0}; // standard x-y axis NORTH - EAST - SOUTH - WEST
int y_dir[4] = { 0,1,0,-1};

int n,m;
int arr[1010][1010];
int dis[1010][1010];

class node
{
public:
    int x,y,d;
    node( int _x=0,int _y=0, int _d=0): x(_x) , y(_y) , d(_d) { }
};

bool operator<( const node& lhs, const node& rhs )  { return lhs.d > rhs.d;   }

int main()
{   
    boost
    test_case
    {
        cin >> n >> m;
        forr(i,0,n-1)   forr(j,0,m-1)   cin >> arr[i][j];

        priority_queue< node > pq;
        pq.push( node(0,0,arr[0][0]) );
        
        forr(i,0,n-1)   forr(j,0,m-1)   dis[i][j] = 1e9;
        dis[0][0] = arr[0][0];

        while( !pq.empty() )
        {
            node u = pq.top();    pq.pop();
            
            if( dis[u.x][u.y] < u.d )   continue;
            if( u.x == n-1 && u.y == m-1 )  break;

            forr(i,0,3)
            {
                int nu,nv;
                nu = u.x + x_dir[i];
                nv = u.y + y_dir[i];
                if( nu<0 || nu>=n || nv<0 || nv>=m ) continue;
                if( dis[nu][nv] > dis[u.x][u.y] + arr[nu][nv] )
                {
                    dis[nu][nv] = dis[u.x][u.y] + arr[nu][nv];
                    pq.push( node(nu,nv,dis[nu][nv]) );
                }
            }
        }

        cout << dis[n-1][m-1] << endl;
    }
    return 0;
}
