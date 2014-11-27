#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 40010

int fa[maxn], xx[maxn], yy[maxn], ans[maxn];
struct edges{
    int u, v, l;
    char d;
}edge[maxn];

struct node {
    int u, v, t;
    int index;
}query[maxn];

bool cmp(node a, node b) { 
    return a.t < b.t;
}
    
int find(int x){
	if(fa[x] != x){
		int tmp = fa[x];
		fa[x] = find(tmp);
		xx[x] += xx[tmp];
		yy[x] += yy[tmp];
	}
	return fa[x];
}

void un(int x){
	int u = find(edge[x].u);
	int v = find(edge[x].v);
	
	if(u!=v){
		fa[u] = v;
		switch(edge[x].d){
			case 'E':
				xx[u] = -xx[edge[x].u] + edge[x].l + xx[edge[x].v];
				yy[u] = -yy[edge[x].u] + xx[edge[x].v];
				break;
			case 'W':
				xx[u] = -xx[edge[x].u] - edge[x].l + xx[edge[x].v];
				yy[u] = -yy[edge[x].u] + yy[edge[x].v];
				break;
			case 'N':
				xx[u] = -xx[edge[x].u] + xx[edge[x].v];
				yy[u] = -yy[edge[x].u] - edge[x].l + yy[edge[x].v];
				break;
			case 'S':
				xx[u] = -xx[edge[x].u] + xx[edge[x].v];
				yy[u] = -yy[edge[x].u] + edge[x].l + yy[edge[x].v];
				break;
		}
	}
}


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
	for(int i = 0; i <= n; i++){
		fa[i] = i;
		xx[i] = yy[i] = 0;
	}
    for(int i = 1; i <= m; i++){
		cin >> edge[i].u >> edge[i].v >> edge[i].l >> edge[i].d;
    }
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++){
		scanf("%d%d%d", &query[i].u, &query[i].v, &query[i].t);
		query[i].index = i;
    }
	sort(query + 1, query + 1 + q, cmp);
	int now = 1;
	for(int i = 1; i <= m; i++){
		un(i);
		while(query[now].t==i && now <= q){
			int u = find(query[now].u);
			int v = find(query[now].v);
			if(u==v){
				ans[query[now].index] = abs(xx[query[now].u] - xx[query[now].v]) + abs(yy[query[now].u] - yy[query[now].v]);
			}
			else
				ans[query[now].index] = -1;
			now ++;
		}
		if(now > q) break;
	}
	for(int i = 1; i <= q; i++){
		cout << ans[i] << endl;
	}
	return 0;
}

