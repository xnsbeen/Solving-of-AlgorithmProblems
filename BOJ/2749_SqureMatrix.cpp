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

vector<vector<long long int>> res(5,vector<long long int>(5));
vector<vector<long long int>> arr(5,vector<long long int>(5));
vector<vector<long long int>> multy(long long int n){
	vector<vector<long long int>> temp(5,vector<long long int>(5));
	vector<vector<long long int>> temp2(5,vector<long long int>(5));

	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j){
			temp2[i][j]=0;
		}
	
	if(n==1) return arr;
	if(n%2==1){
		temp = multy(n-1);
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k){
					temp2[i][j] = (temp2[i][j]+((arr[i][k]%1000000)*(temp[k][j]%1000000))%1000000)%1000000;
				}
	}
	else{
		temp =multy(n/2);
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				for(int k=0;k<2;++k){
					temp2[i][j] = (temp2[i][j]+((temp[i][k]%1000000)*(temp[k][j]%1000000))%1000000)%1000000;
			}
	}
	return temp2;
}



int main(int argc, char* argv[]) {
	long long int n;
	cin>>n;
	arr[0][0]=res[0][0]=1;
	arr[0][1]=res[0][1]=1;
	arr[1][0]=res[1][0]=1;
	arr[1][1]=res[1][1]=0;
	
	res = multy(n);
	
	printf("%lld\n",res[0][1]);
	
	return 0;
}