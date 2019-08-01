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

using namespace std;

vector<vector<int>> res(6,vector<int>(6));
vector<vector<int>> arr(6,vector<int>(6));
int n;

vector<vector<int>> multy(long long int b){
	vector<vector<int>> temp(6,vector<int>(6));
	vector<vector<int>> temp2(6,vector<int>(6));

	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			temp2[i][j]=0;
		}
	
	if(b==1) return arr;
	if(b%2==1){
		temp = multy(b-1);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				for(int k=0;k<n;++k){
					temp2[i][j] += ((arr[i][k]%1000)*(temp[k][j]%1000))%1000;
					temp2[i][j]%=1000;
				}
	}
	else{
		temp =multy(b/2);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				for(int k=0;k<n;++k){
					temp2[i][j] += ((temp[i][k]%1000)*(temp[k][j]%1000))%1000;
					temp2[i][j]%=1000;
			}
	}
	return temp2;
}



int main(int argc, char* argv[]) {
	long long int b; // 문제 제대로 보자
	cin>>n>>b;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			scanf("%d",&arr[i][j]);
			res[i][j] = arr[i][j];
		}
	
	res = multy(b);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			printf("%d ",res[i][j]%1000);
		}
		printf("\n");
	}
	
	return 0;
}