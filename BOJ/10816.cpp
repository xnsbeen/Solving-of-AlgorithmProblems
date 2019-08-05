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
using namespace std;

int main(int argc, char* argv[]) {
	int n,m,k;
	cin>>n;
	vector<int>numbers(n);
	for(int i=0;i<n;++i)
		scanf("%d",&numbers[i]);
	sort(numbers.begin(),numbers.end());
	cin>>m;
	vector<int>chk(m);
	for(int i=0;i<m;++i){
		scanf("%d",&k);
		if(binary_search(numbers.begin(),numbers.end(),k)){
			int lo = lower_bound(numbers.begin(),numbers.end(),k)-numbers.begin();
			int up = upper_bound(numbers.begin(),numbers.end(),k)-numbers.begin();
			chk[i]=up-lo;
		}
	}	
	
	for(int i=0;i<m;++i)
		printf("%d ",chk[i]);
	cout<<endl;
	return 0;
}