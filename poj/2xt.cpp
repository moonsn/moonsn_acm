#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1000];

int d = 0;
int md = 0;
void deep(int x, int dp){
    
	md = max(dp, md);
	if(a[x] == 0) return;
	deep(2*x,dp++);
	deep(2*x+1,dp++);
}

void xian(int x){
	if(a[x] == 0) return;
	cout << a[x] << " ";
	xian(2*x);
	xian(2*x+1);
}

void zhong(int x){
	if(a[x] == 0) return;
	zhong(2*x);
	cout << a[x] << " ";
	zhong(2*x+1);
}

void hou(int x){
	if(a[x] == 0) return;
	hou(2*x);
	hou(2*x+1);
	cout << a[x]  << " ";
}

int main(){
	int n;
	while(~scanf("%d", &n)){
	    	memset(a, 0, sizeof(a));
		for(int i = 1;i <= n; i++){
			scanf("%d", &a[i]);
		}

		xian(1);
		cout << endl;
		zhong(1);
		cout << endl;
		hou(1);
		cout << endl;
		deep(1,1);
		cout << md << endl;
	}
	return 0;
}





