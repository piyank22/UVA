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

int main()
{
	test_case
	{
		queue<int> q[2];
		q[0]=queue<int>();
		q[1]=queue<int>();

		int arrivaltime[10010] = {0} ;
		int reachtime[10010] = {0} ;
		int n,t,m;
		cin >> n >> t >> m;
		
		forr(i,0,m-1)
		{
			string s;
			cin >> arrivaltime[i] >> s;
			if(s=="left")		q[0].push(i);
			else				q[1].push(i);
		}

		int curr_time=0;
		int curr_side=0; // 0 for left and 1 for right

		int next;
		while( !q[0].empty() || !q[1].empty() )
		{
			if(q[0].empty())		next=arrivaltime[q[1].front()];
			else if(q[1].empty())	next=arrivaltime[q[0].front()];
			else					next=min( arrivaltime[q[1].front()] , arrivaltime[q[0].front()] );
			curr_time = max(curr_time,next);

			int cnt=0;
			while( !q[curr_side].empty() && arrivaltime[ q[curr_side].front() ]<=curr_time && cnt<n )
			{
				reachtime[ q[curr_side].front() ] = curr_time+t;
				q[curr_side].pop();
				cnt++;
			}

			curr_side = curr_side^1;
			curr_time += t;
		}
		forr(i,0,m-1)		cout << reachtime[i] << endl;
		if(tc<__T)		cout << endl;	
	}
	return 0;
}