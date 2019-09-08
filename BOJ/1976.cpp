#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <math.h>
#include <sstream>
#include <set>
#include <limits.h>
#include <string.h>
using namespace std;
int parents[201];
int arr[201][201];

int findParent(int a){
	if(parents[a]==a) return a;
	parents[a]= findParent(parents[a]);
	return parents[a];
}
void Union(int a, int b){
	int pa = findParent(a);
	int pb = findParent(b);
	parents[pb]=pa;
}


int main(int argc, char* argv[]){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i) parents[i] = i;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&arr[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			if(arr[i][j]) Union(i,j);
	
	int chk;
	for(int i=1;i<=m;++i){
		int a;
		scanf("%d",&a);
		if(i==1)chk=findParent(a);
		else if(chk != findParent(a)){
			chk =-1;
			break;
		}
	}
	
	if(chk==-1) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	
	return 0;
}