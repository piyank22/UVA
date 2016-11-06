	#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>

#define PI acos(-1)
#define ll long long
#define eps 1e-5

using namespace std;

int main() 
{
	int n;
	while(1)
	{
		scanf("%d\n",&n);
		if(n==0)
			break;
		string s;
		int v=0;
		for(int i=n-1;i>=1;i--)
		{
			cin>>s;
			if(s=="NO")
				continue;
			else if(s=="+z")
			{
				if(v==4)
					v=0;
				else if(v==0)
					v=5;
				else if(v==1)
					v=4;
				else if(v==5)
					v=1;
			}
			else if(s=="-z")
			{
				if(v==4)
					v=1;
				else if(v==0)
					v=4;
				else if(v==1)
					v=5;
				else if(v==5)
					v=0;
				// cout<<2<<"\n";
			}
			else if(s=="+y")
			{
				if(v==0)
					v=3;
				else if(v==1)
					v=2;
				else if(v==3)
					v=1;
				else if(v==2)
					v=0;
				// cout<<2<<"\n";
			}
			else if(s=="-y")
			{
				if(v==0)
					v=2;
				else if(v==1)
					v=3;
				else if(v==3)
					v=0;
				else if(v==2)
					v=1;
				// cout<<3<<"\n";
			}
		}
		if(v==0)
			printf("+x\n");
		else if(v==1)
			printf("-x\n");
		else if(v==3)
			printf("+y\n");
		else if(v==2)
			printf("-y\n");
		else if(v==4)
			printf("-z\n");
		else
			printf("+z\n");
	}
	return 0;
}