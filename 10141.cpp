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
	int n,p;
	string isu,temp;
	int cas=1;
	while(true)
	{
		scanf("%d %d\n",&n,&p);
		if(n==0 && p==0)
			break;
		if(cas>1)
			printf("\n");
		string temp;
		for(int i=0;i<n;i++)
			getline(cin,temp);

		int s;
		double price;
		double best_price= 1e9;
		int P=p;
		int rm=-1;
		while(P--)
		{
			getline(cin,temp);
			scanf("%lf %d\n",&price,&s);
			if(s > rm)
			{
				rm=s;
				isu=temp;
				best_price = price;
			}
			else if( s==rm && price < best_price )
			{
				isu=temp;
				best_price = price;
			}

			while(s--)
			{
				getline(cin,temp);
			}
		}
		printf("RFP #%d\n",cas++ );
		cout<<isu<<"\n";
	}
	return 0;
}