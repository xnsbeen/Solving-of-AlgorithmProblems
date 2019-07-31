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

int main(int argc, char* argv[]) {
	vector<int> res;
	int arr1[100][100],arr2[100][100];
	int n,m,k,temp;
	cin>>n>>m;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&arr1[i][j]);
	cin>>m>>k;
	for(int i=0;i<m;++i)
		for(int j=0;j<k;++j)
			scanf("%d",&arr2[i][j]);
	for(int i=0;i<n;++i){
		for(int j=0;j<k;++j){
			temp=0;
			for(int d=0;d<m;++d){
				temp+=arr1[i][d]*arr2[d][j];
			}
			res.push_back(temp);
		}
	}	
	
	for(int i=0;i<n;++i){
		for(int j=0;j<k;++j){
			printf("%d ",res[i*k+j]);
		}
		printf("\n");
	}
	return 0;
}