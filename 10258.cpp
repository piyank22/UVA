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

struct score
{
	int id;
	int penalty;
	int solved;
	score(int _id=0,int _p=0,int _s=-1) : id(_id) , penalty(_p) , solved(_s) { }
	bool operator<( const score& play2)
	{
		return (solved > play2.solved || ( solved == play2.solved && penalty < play2.penalty ) || (solved == play2.solved && penalty == play2.penalty && id < play2.id ) );
	}
};

int main()
{
	int n;
	string s;
	cin >> n;
	getline(cin,s);
	getline(cin,s);
	while(n--)
	{
		int incorrect[101][11];
		bool solve[101][11] = {0} ;

		vector<score> vec(101,score());
		forr(i,0,100)	vec[i].id=i;

		zero(incorrect);
		while( getline(cin,s) , s!="" )
		{
			stringstream ss(s);
			int player , problem , tim;
			char cas;
			ss >> player >> problem >> tim >> cas;
			vec[player].solved = max(0,vec[player].solved);
			if(cas == 'R' || cas == 'U' || cas == 'E' || solve[player][problem] ) 	continue;
			else
			{
				if(cas == 'I')
					incorrect[player][problem]++;
				else
				{
					vec[player].solved++;

					vec[player].penalty += tim + 20*(incorrect[player][problem]);
					solve[player][problem]=true;
				}
			}
		}
		sort(vec.begin(),vec.end());
		forr(i,0,100)
		{
			if(vec[i].solved==-1)	break;
			printf("%d %d %d\n",vec[i].id,vec[i].solved,vec[i].penalty );
		}
		if(n)
			cout<<endl;
	}
	return 0;
}