/*
 并查集 路径压缩 
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 30010

int f[maxn],pos[maxn], st[maxn];

void init(int n){
	for(int i = 0;i <= n; i++){
		f[i] = i;
		pos[i] = 0;
		st[i] = 1;
	}
}

int find(int x){
	if(f[x] == x) return x;
	
	int tmp = find(f[x]);
	pos[x] += pos[f[x]];
	return f[x] = tmp;
}

void move(int a, int b){
	int fa = find(a);
	int fb = find(b);
	f[fa] = fb;
	pos[fa] += st[fb];
	st[fb] += st[fa];
	st[fa] = 0;
}

void print(){
for(int i = 1; i <= 5; i++) {
	cout << f[i] << " ";
}
cout << endl;
for(int i = 1; i <= 5; i++){
	cout << pos[i] << " ";
}
cout << endl;
for(int i = 1; i <= 5; i++){
	cout << st[i] << " ";
}
cout << endl << endl;
}
void ans(int x){
	find(x);//WA点就在这里!
	printf("%d\n", pos[x]);
}

int main(){
	int n;
	char cmd;
	scanf("%d", &n);
	init(maxn-1);
	for(int i = 0; i < n; i++){
		scanf(" %c ", &cmd);
		int a, b;
		if(cmd == 'M') {
			scanf("%d%d", &a, &b);
			if(find(a) != find(b))
				move(a, b);
		}else{
			scanf("%d", &a);
			ans(a);
		}
		//print();
	}
	return 0;
}


