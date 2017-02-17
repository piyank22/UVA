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

int h,w;
vector<vi> grid;
int holes[1010];

vi transform( string s )
{
    vi row = vi(4*w+2,0);

    forr(i,0,sz(s)-1)
    {
        int ch = ( s[i]<='9' ? s[i]-'0' : s[i]-'a'+10 );
        int p = 0;
        for( int k = 8 ; k>0 ; k >>= 1 )
        {
            row[1+(4*i)+p] = ( k&ch ? 1 : 0 );
            p++;
        }
    }
    return row;
}

void floodfill( int x, int y, int from, int to)
{
    if( x<0 || x>=h || y<0 || y>=w || grid[x][y]!=from )    return;
    grid[x][y] = to;
    floodfill(x+1,y,from,to);
    floodfill(x-1,y,from,to);
    floodfill(x,y+1,from,to);
    floodfill(x,y-1,from,to);
}

int main()
{   
    boost
    int tc=1;
    while( cin >> h >> w , h|w )
    {
        trace2(h,w);
        zero(holes);
        grid = vector<vi>( h+2 , vi( 4*w + 2 , 0 ) );
        forr(i,1,h)
        {
            string s;
            cin >> s;
            grid[i] = transform(s);
        }

        h += 2;
        w = 4*w + 2;
        trace2(h,w);
        floodfill(0,0,0,10000);

        int cnt = 2;
        forr(i,0,h-1)
        {
            forr(j,0,w-1)
            {
                if(grid[i][j]==1)
                    floodfill(i,j,1,cnt++);
                else if(grid[i][j]==0)
                {
                    int belong = grid[i][j-1];
                    holes[belong]++;
                    floodfill(i,j,0,belong);
                }            
            }
        }

        string ans;
        ans.clear();
        for( int i=2;i<cnt;i++)
        {
            if( holes[i] == 0 )     ans += 'W';
            if( holes[i] == 1 )     ans += 'A';
            if( holes[i] == 2 )     ans += 'K';
            if( holes[i] == 3 )     ans += 'J';
            if( holes[i] == 4 )     ans += 'S';
            if( holes[i] == 5 )     ans += 'D';
        }
        sort(all(ans));
        cout << "Case "<< tc++ << ": " << ans << endl;
    }
    return 0;
}
