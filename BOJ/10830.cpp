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

int res[6][6];
int arr[6][6];
int n;

void multy1(){
	int temp [6][6];
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			temp[i][j]=res[i][j];
	
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			for(int k=0;k<n;++k){
				temp[i][k] = res[i][k]+arr[k][j];
			}
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			res[i][j]=temp[i][j];
}


void multy2(){
	int temp [6][6];
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			temp[i][j]=0;
	
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			for(int k=0;k<n;++k){
				temp[i][k] += res[i][k]*res[k][j];
			}
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			res[i][j]=temp[i][j];
}

int main(int argc, char* argv[]) {
	int b;
	vector<int>vec;
	cin>>n>>b;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			scanf("%d",&arr[i][j]);
			res[i][j] = arr[i][j];
		}
	
	while(1){
		if(b==1) {
			break;
		}
		if(b%2==0) {
			b/=2;
			vec.push_back(2);
		}
		else{
			b--;
			vec.push_back(1);
		}
		
	}
	
	for(int i=vec.size()-1;i>=0;--i){
		cout<<vec[i]<<endl;
		if(vec[i]==1) multy1();
		else multy2();
	}
	
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}