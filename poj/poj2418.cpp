#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

map<string, int> tree_map;


int main(){
	string name;
	int total = 0;
	while(getline(cin, name)){
		tree_map[name] ++;
		total ++;
	}
	map<string, int>::iterator iter;
	for(iter = tree_map.begin(); iter != tree_map.end(); iter++){
		cout << iter->first;
		printf(" %.4f\n", 100*((float)iter->second/total));
	}
	return 0;

}
