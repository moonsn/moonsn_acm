#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
using namespace std;

struct node{
    int a;
    int l, r;
};

node arr[10000];

stack<int> read(string &str){
    memset(arr, -1, sizeof(arr));
    cin >> str;
    stack<int> st;
    int len = str.length();
    for(int i = 0; i < len; i++){
	if(str[i] >= 'a' && str[i] <= 'z'){
	    st.push(i);
	}else{
	    int a = st.top(); st.pop();
	    int b = st.top(); st.pop();
	    arr[i].l = a;
	    arr[i].r = b;
	    st.push(i);
	}
    }
    return st;
}

void res(stack<int> st, string &str){
    string ans;
    queue<int> q;
    int tmp = st.top();
    st.pop();
    q.push(tmp);
    while(!q.empty()){
	int now = q.front(); q.pop();
	ans.push_back(str[now]);
	//push right element first, because of we will reverse the ans string.
	if(arr[now].l != -1) q.push(arr[now].r);
	if(arr[now].r != -1) q.push(arr[now].l);
    }
    reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
	string str;
	res(read(str), str);
    }
    return 0;
}
