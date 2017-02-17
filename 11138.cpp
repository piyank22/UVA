/*******************
AUTHOR: HUMBLE_LOSER
*******************/

#include <stdio.h>
#include <string.h>

#define MAX_BOLTS 501
#define MAX_NUTS 501

int nuts,bolts;

int fits[MAX_BOLTS][MAX_NUTS];
int match[510],visited[510];

void read_input_data(void){
    int n,b;
    scanf("%d%d",&bolts,&nuts);
    for(b=0;b<bolts;b++){
        for(n=0;n<nuts;n++){
            scanf("%d",&fits[b][n]);
        }
    }
}

int bestmatched;

bool aug(int l)
{
    if( visited[l] )    return false;
    visited[l] = true;

    for(int i=0;i<nuts;i++)
        if( fits[l][i] && ( match[i]==-1 || aug( match[i] ) ) )
            {
                match[i]=l;
                return true;
            }

    return false;
}

void match_bolt()
{
    memset(match,0xff,sizeof(match));
    for(int i=0;i<bolts;i++)
    {
        memset(visited,0,sizeof(visited));
        bestmatched += aug(i);
    }
}

int main(){
    int cases,caseno;
    scanf("%d",&cases);

    for(caseno=1;caseno<=cases;caseno++){
        read_input_data();
        bestmatched = 0;
        match_bolt();
        printf("Case %d: ",caseno);
        printf("a maximum of %d nuts and bolts ",bestmatched);
        printf("can be fitted together\n");
    }
    return 0;
}
