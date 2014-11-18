/*
   hdu 3047 zjun stadium (带权并查集）
   题意： 一个圆形的体育场，给出m次，某两个人的相对位置，
   判断是否有冲突， 输出冲突次数。
   解法： 并和查的时候都需要注意相对父节点的路径。

*/



#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 50001

int father[maxn], dist[maxn]; // 相对父节点的位置


int find(int a){
    if(father[a] == a) return a;
    int tmp = find(father[a]);
    dist[a] += dist[father[a]];
    return father[a] = tmp;
}

void combine(int a, int b, int x) {
    int fa = find(a);
    int fb = find(b);
    
    father[fb] = fa;
    dist[fb] = dist[a] + x - dist[b]; 
}

int main(){
    int n, m;
    while(~scanf("%d%d", &n, &m)){
	int a, b, x;
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
	    father[i] = i;
	    dist[i] = 0;
	}

	for(int i = 1; i <= m; i++){
	   scanf("%d%d%d", &a, &b, &x);
	   if(find(a) != find(b)){
	       combine(a, b, x);
	   }else{
	       if(dist[a] + x != dist[b]) ans ++ ;
	   }
//	   cout << dist[a] << " " << dist[b] << " " << x << endl;
	}
	cout << ans << endl;
    }
    return 0;
}

	


