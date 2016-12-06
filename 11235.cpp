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

const int max_n = 1e5+100;
int n,q;
int arr[max_n];
int rt[max_n];
int lf[max_n];
int cnt[max_n];
int seg[ max_n<<2 ];

#define left_c(x) (x<<1)+1
#define right_c(x) (x<<1)+2
#define parent_c(x) (x>>1)
void build_st(int pos , int s , int e )
{
	if(s==e)		seg[pos] = cnt[s];
	else
	{
		int mid = (s+e) >> 1;
		build_st(left_c(pos),s,mid);
		build_st(right_c(pos),mid+1,e);
		seg[pos] = max( seg[left_c(pos)] , seg[right_c(pos)] );
	}	
}

int rmq(int pos , int x , int y , int s , int e )
{
	if(y<s || e<x || x>y)	return -1;
	if( x<=s && e<=y )		return seg[pos];
	int mid = (s+e)>>1;
	return max( rmq(left_c(pos),x,y,s,mid) , rmq(right_c(pos),x,y,mid+1,e) );
}

int main()
{
	boost
	arr[0] = -1e7;
	while( cin >> n , n )
	{
		cin >> q;
		forr(i,1,n)
		{
			cin >> arr[i];
			if(arr[i]!=arr[i-1])	lf[i] = i;
			else					lf[i] = lf[i-1];
		}

		rt[n] = n;
		rof(i,n-1,1)
			if(arr[i]==arr[i+1])	rt[i] = rt[i+1];
			else					rt[i] = i;
		
		forr(i,1,n)
			cnt[i] = rt[i]-lf[i]+1;

		build_st(0,1,n);
		while(q--)
		{
			int u,v;
			cin >> u >> v;
			int ans;
			if(arr[u]==arr[v])		ans = v-u+1;
			else					ans = max( rt[u]-u+1 , max( v-lf[v]+1 , rmq(0,rt[u]+1,lf[v]-1,1,n) ) );
			cout << ans << endl;
		}
	}
	return 0;
}