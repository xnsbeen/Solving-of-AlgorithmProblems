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
int arr[26][26];
int cnt=0;
int total=0;
int n;
int dy[4] = {0,0,-1,1};
int dx[4] ={1,-1,0,0};
vector<int> res;
void dfs(int y,int x,int num){
	arr[y][x]=0;
	for(int i=0;i<4;++i)
		if(arr[y+dy[i]][x+dx[i]]==1){
			cnt++;
			dfs(y+dy[i],x+dx[i],num);
		}
}
int main(int argc, char* argv[]) {
	string str;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>str;
		for(int j=1;j<=n;++j)
			arr[i][j]=str[j-1]-'0';
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(arr[i][j]!=0){
				dfs(i,j,arr[i][j]);
				res.push_back(cnt);
				cnt=0;
				total++;
			}
	sort(res.begin(),res.end());
	cout<<total<<endl;
	for(int i=0;i<total;++i)
		cout<<res[i]+1<<endl;
	return 0;
}