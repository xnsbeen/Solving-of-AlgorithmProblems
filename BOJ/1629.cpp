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
int A,B,C;
long long int power(int a, int b)
{
	if(b==0) return 1;
	long long int temp = power(a,b/2);
	if(b%2==0) return temp*temp%C;
	else return ((temp*temp)%C*a)%C;

}

int main(int argc, char* argv[]) {
	cin>>A>>B>>C;
	cout<<power(A,B)<<endl;
	return 0;
}
