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

const int max_n = 1030000;
int seg[ max_n<<2 ];
int lazy[ max_n<<2 ];
int n;

string pirates , str;

#define left_c(x) (x<<1)+1
#define right_c(x) (x<<1)+2
#define parent_c(x) (x>>1)

void adjust_children(int pos, int s, int e,int x)
{
	lazy[pos]=-1;
	if(s==e)	return;

	if(x==2)
	{
		int &ref = lazy[left_c(pos)];
		if(ref==0)			ref=1;
		else if(ref==1)		ref=0;
		else if(ref==2)		ref=-1;
		else 				ref=2;

		int &reff = lazy[right_c(pos)];
		if(reff==0)			reff=1;
		else if(reff==1)	reff=0;
		else if(reff==2)	reff=-1;
		else 				reff=2;
	}
	else
	{
		lazy[left_c(pos)]	= x;
		lazy[right_c(pos)]	= x;
	}
}

void propagate(int pos, int s, int e)
{
	if(lazy[pos]==-1)	return;
	else if(lazy[pos]==0)	
		seg[pos]=0;
	else if(lazy[pos]==1)
		seg[pos] = e-s+1;
	else
		seg[pos] = (e-s+1)-seg[pos];
	adjust_children(pos,s,e,lazy[pos]);
}

void build_st(int pos , int s , int e )
{
	if(s==e)		seg[pos] = pirates[s]-48;
	else
	{
		int mid = (s+e) >> 1;
		build_st(left_c(pos),s,mid);
		build_st(right_c(pos),mid+1,e);
		seg[pos] = seg[left_c(pos)] + seg[right_c(pos)] ;
	}	
}

void update_st(int pos,int x,int y,int s, int e, int change)
{
	propagate(pos,s,e);
	if(y<s || e<x || x>y)	return;
	if( x<=s && e<=y )	
	{
		if(change==2)		seg[pos] = (e-s+1)-seg[pos];
		else 				seg[pos] = (e-s+1)*change;
		
		adjust_children(pos,s,e,change);
		return;	
	}
	int mid = (s+e)>>1;
	update_st(left_c(pos),x,y,s,mid,change);
	update_st(right_c(pos),x,y,mid+1,e,change);
	seg[pos] = seg[left_c(pos)] + seg[right_c(pos)] ;
}

int query(int pos , int x , int y , int s , int e )
{
	if(y<s || e<x || x>y)	return 0;
	propagate(pos,s,e);
	if( x<=s && e<=y )		return seg[pos];
	int mid = (s+e)>>1;
	return query(left_c(pos),x,y,s,mid) + query(right_c(pos),x,y,mid+1,e);
}

int main()
{
	boost
	test_case
	{
		minus(lazy);
		cout << "Case "<<tc<<":\n";
		pirates = " ";
		int m;
		cin >> m;
		while(m--)
		{
			int t;	cin>>t;
			cin >> str;
			while(t--)		pirates += str;
		}
		n = sz(pirates)-1;
		build_st(0,1,n);
		int q;
		cin >> q;
		int Q=0;
		while(q--)
		{
			char a ;
			int b,c;
			cin >> a >> b >> c;
			b++ , c++;
			if(a=='F')
				update_st(0,b,c,1,n,1);
			else if(a=='E')
				update_st(0,b,c,1,n,0);
			else if(a=='I')
				update_st(0,b,c,1,n,2);
			else
				cout<<"Q"<<++Q<<": "<<query(0,b,c,1,n)<<endl;
		}
	}
	return 0;
}