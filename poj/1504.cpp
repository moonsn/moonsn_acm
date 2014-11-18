#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

void re(char *a){
    int len = strlen(a);
    for(int i = 0; i < len/2; i++){
	char tmp = a[i];
	a[i] = a[len-i-1];
	a[len-i-1] = tmp;
    }
}

    

int main(){
    int n;
    scanf("%d", &n);
    char a[15], b[15];
    while(n--){
	scanf("%s %s", a, b);
	int lena = strlen(a);
	int lenb = strlen(b);
	int aa[15], bb[15];
	int cc[16];
	for(int i = 0; i < max(lena, lenb); i++){
	    if(i>=lena) aa[i] = 0;
	    else aa[i] = a[i] - '0';
	    if(i>=lenb) bb[i] = 0;
	    else bb[i] = b[i] - '0';
	    cc[i] = aa[i] + bb[i];
	}
	int jinwei = 0;
	for(int i = 0;  i < max(lena,lenb); i++){
		int xx = cc[i];
		cc[i] = (cc[i] + jinwei) % 10;
		jinwei = (xx+jinwei) / 10;
	}
	int f = 0;
       	for(int i = 0; i < max(lena, lenb); i++){
	    if(cc[i]==0&&f==0) continue;
	    else {
	    	f = 1;
	    }
	    printf("%d", cc[i]);
	}
	if(jinwei!=0) printf("%d", jinwei);
	printf("\n");
    }
}
