
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    int low=1,high=100;
    while(low!=high){
        int mid=low+high;
        mid/=2;
        printf("%d\n",mid);
        fflush(stdout);
        char s[3];
        scanf("%s",s);
        if(mid==low || mid==high){
            printf("! %d\n",low);
            fflush(stdout);
            break;
        }
        if(strcmp(s,"<")==0){
            high=mid-1;
        }
        else{
            low=mid;
        }
    }
    // printf("! %d\n",low);
    // fflush(stdout);
    return 0;
}