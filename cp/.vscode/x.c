#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int convert(int n){
	int arr[]={67,71,73,79,83,89,97,101,103,107,109,113};
	//above are the possible prime num for characters
	if(n<67){
		return 67;
	}
	else if(n>113){
		return 113;
	}
	else{
		int diff=abs(n-arr[0]);
		int ans=arr[0];
		for(int i=1;i<12;i++){
			if(diff>abs(n-arr[i])){
				ans=arr[i];
				diff=abs(n-arr[i]);
			}
		}
		return ans;
	}
}


int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		char s[500];
		scanf("%s",s);
		for(int i=0;i<strlen(s);i++){
			char newAscii=(char)(convert((int)s[i]));
			printf("%c",newAscii);
		}
		printf("\n");
	}
}
