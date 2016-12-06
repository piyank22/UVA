#include <iostream>
#include <cstdio>
#include <math.h>
#include <ctime>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>

#define PI acos(-1)
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

using namespace std;

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

vector< vi > solution;
vi t(8,0);

bool is_safe(int r,int c)
{
    int cc = c+1;
    forr(i,0,c-1)
    {
        int x = t[i], y = i+1;
        if(r==x || cc==y || r-cc==x-y || r+cc==x+y)    return false;
    }
    return true;
}

int cnt=0;
void solve(int pos)
{
    if( pos==8)
    {
        solution.eb(t);
        return;
    }
    forr(place,1,8)
    { 
        if( is_safe(place,pos) )
        {
            t[pos]=place;
            solve(pos+1);
        }
    }   
}

void pre()
{
    forr(i,1,8)
    {
        t[0]=i;
        solve(1);
    }
}

int main()
{
    boost
    pre();
    vi arr(8,0);
    int tc=1;
    while(1)
    {
        if(!(cin>>arr[0]))  break;
        forr(i,1,7) cin>>arr[i];
        int mi = 1e9;
        for( auto a : solution )
        {
            int temp=0;
            forr(i,0,7)     temp += (a[i]==arr[i] ? 0: 1);
            if(temp<mi)     mi = temp; 
        }
        cout<<"Case "<<tc++<<": "<<mi<<endl;
    }
	return 0;
}