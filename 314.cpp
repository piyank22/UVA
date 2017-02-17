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
vector<vi> input_grid , grid;

int dis[55][55][5];

int b1,b2,e1,e2;
string orientation;

int x[4] = { -1,0,1,0};
int y[4] = { 0,1,0,-1};

bool check( int u , int v )
{
    if( u>0 && u<n-1 && v>0 && v<m-1 )    return true;
    return false;
}

bool check_obstacle( int u , int v )
{
    return ( check(u,v) && (grid[u][v]==0) );
}

class node
{
public:
    int x,y,dir;
    node( int _x=0 ,int _y=0 ,int _dir=0) : x(_x) , y(_y) , dir(_dir) { }
};

int main()
{   
    boost
    while( cin >> n >> m , n|m )
    {
        grid.assign( n+1 , vi(m+1,0) );
        forr(i,0,n-1)
            forr(j,0,m-1)
            {
                int v;
                cin >> v;
                grid[i][j] = v || grid[i][j];
                grid[i+1][j] = v || grid[i+1][j];
                grid[i][j+1] = v || grid[i][j+1];
                grid[i+1][j+1] = v || grid[i+1][j+1];

            }
        // trace_mat(grid,0,n,0,m);
        n++ , m++;
        cin >> b1 >> b2 >> e1 >> e2 >> orientation;
        int dir;
        if( orientation == "north" )       dir = 0;
        else if(orientation == "east" )    dir = 1;
        else if(orientation == "south" )   dir = 2;
        else                               dir = 3;

        queue<node> q;
        minus(dis);
        dis[b1][b2][dir] = 0;
        q.push( node(b1,b2,dir) );
        int ans = -1;
        while( !q.empty() )
        {
            node u = q.front(); q.pop();
            // trace3(u.x,u.y,u.dir);
            if( u.x == e1 && u.y == e2 )
            {
                ans = dis[u.x][u.y][u.dir];
                break;
            }
            if( dis[u.x][u.y][(u.dir+1)%4] == -1 )      q.push( node(u.x,u.y,(u.dir+1)%4) ) , dis[u.x][u.y][(u.dir+1)%4] = 1+dis[u.x][u.y][u.dir];
            if( dis[u.x][u.y][(u.dir+3)%4] == -1 )      q.push( node(u.x,u.y,(u.dir+3)%4) ) , dis[u.x][u.y][(u.dir+3)%4] = 1+dis[u.x][u.y][u.dir];
            forr(k,1,3)
            {
                int nx = u.x + k*x[u.dir] , ny = u.y + k*y[u.dir];
                if( !check_obstacle( nx,ny ) )     break;
                if( dis[nx][ny][u.dir] == -1 )
                {
                    q.push( node( nx,ny , u.dir ) );
                    dis[nx][ny][u.dir] = dis[u.x][u.y][u.dir] + 1;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
