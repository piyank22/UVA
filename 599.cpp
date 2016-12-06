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

class uf
{
public:
	int parent[26] , siz[26];
	uf( )
	{
		forr(i,0,25)	parent[i]=i , siz[i]=1;
	}
	int find_uf(int i)
	{
		if( parent[i]==i )	return i;
		return parent[i] = find_uf(parent[i]);
	}
	void merge_uf(int x,int y)
	{
		x = find_uf(x);
		y = find_uf(y);
		if(x==y)	return;
		if(siz[x]>siz[y])	parent[y] = x , siz[x] += siz[y];
		else				parent[x] = y , siz[y] += siz[x];
	}
};

int main()
{
	test_case
	{
		string a;
		int acorns = 0 ;
		set<int> trees;
		trees.clear() ;

		uf uf_var = uf() ;
		bool vertices[26] = {0};
		while( cin >> a , a[0]!='*' )
		{
			int u = a[1]-65;
			int v = a[3]-65;
			uf_var.merge_uf(u,v);
		}
		cin >> a;
		for(int i = 0 ; i < a.size() ; i+=2 )
			vertices[ a[i]-65 ] = true;

		forr(i,0,25)
			if(vertices[i])
			{
				int ii = uf_var.find_uf(i);
				if(uf_var.siz[ii]==1)
					acorns++;
				else 
					trees.insert(ii);
			}

		printf("There are %d tree(s) and %d acorn(s).\n", sz(trees) , acorns );
	}
	return 0;
}