/************************\

	这是所谓的`种类幷查集`,前几天做了`带权幷查集`,
	今天见到这题并没有发现他们的关系,在看了某大师的题解后发现
	>>
	这种种类幷查集就是带权幷查集的偏移过程中进行取余操作,
	余数就是种类之间的区别.这里是 0 1
	差值是1 那么按照带权幷查集的方法加1,然后取余2即可.
	今天才知道 %2 可以用 &1 代替666666	

\************************/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn   100000 + 10
int fa[maxn], gang[maxn];

int find(int x){
	if(fa[x]==x) return x;
	int temp = find(fa[x]);
	gang[x] = (gang[x] + gang[fa[x]])&1;
	return fa[x] = temp;
}

void sp(int a, int b){
	int u = find(a);
	int v = find(b);
	fa[v] = u;
	gang[v] = (gang[a]-gang[b]+1)&1;
}

void print(){
	for(int i = 1; i <= 5; i++){
		cout << gang[i] << " ";
	}
	cout << endl;
}

int main(){
	int n, m, t, a, b;
	char cmd;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		//init
		for(int i = 0;i <= n; i++){
			fa[i] = i;
			gang[i] = 0;
		}
		for(int i = 1; i <= m; i++){
			getchar();
			scanf("%c %d %d", &cmd, &a, &b);
			if(cmd == 'D') {
				sp(a, b);
			}else{
				if(n==2) printf("In different gangs.\n");
				int uu = find(a);
				int vv = find(b);
				if(uu!=vv) printf("Not sure yet.\n");
				else if(gang[a] == gang[b] ){
					printf("In the same gang.\n");
				}else{
					printf("In different gangs.\n");
				}
			}
		}
	}
}
