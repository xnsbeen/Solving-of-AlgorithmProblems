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
int arr[52][52];
int m,n;
int cnt=0;

int dy[4] = {0,0,-1,1};
int dx[4] ={1,-1,0,0};

void init(){
	for(int i=0;i<=n+1;++i)
		for(int j=0;j<=m+1;++j)
			arr[i][j]=0;
}
void dfs(int y,int x){
	arr[y][x]=0;
	for(int i=0;i<4;++i){
		int yy = y+dy[i];
		int xx =x+dx[i];
		if(arr[yy][xx]==1&&xx<m&&yy<n){
			dfs(yy,xx);
		}
	}
}
int main(int argc, char* argv[]) {
	int test,k;
	cin>>test;
	while(test--){
		scanf("%d %d %d",&m,&n,&k);
		init();
		for(int i=0;i<k;++i){
			int a,b;
			scanf("%d %d",&a,&b);
			arr[b][a]=1;
		}
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				if(arr[i][j]==1){
					dfs(i,j);
					cnt++;
				}
			}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}