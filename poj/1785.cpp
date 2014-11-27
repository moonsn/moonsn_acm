#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node{
	int value, pa, ls, rs;
	char str[120];
	node(){
		value = pa = ls = rs = 0;
		memset(str, 0, sizeof str);
	}
};

node treap[50005];
bool operator < (const node a, const node b){
	return strcmp(a.str, b.str) < 0;
}

void insert(int i){
	int j = i-1;
	while(treap[j].value < treap[i].value){
		j = treap[j].pa;
	}
	treap[i].ls = treap[j].rs;
	treap[j].rs = i;
	treap[i].pa = j;
}

void print(int i){
	if(i) {
		printf("(");
		print(treap[i].ls);
		printf("%s/%d", treap[i].str, treap[i].value);
		print(treap[i].rs);
		printf(")");
	}
}



int main(){
	int n;
	while(scanf("%d", &n), n){
		memset(treap, 0, sizeof(treap));
		for(int i = 1; i <= n; i++){
			scanf("%*[ ]%[^/]/%d",&treap[i].str, &treap[i].value);
		}
		sort(treap + 1, treap + 1 + n);
		treap[0].value = 100000000;
		for(int i = 1; i <= n; i++){
			insert(i);
		}
		print(treap[0].rs);
		printf("\n");
	}
	return 0;
}
