#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> printNsmallerprime(int n) {
	vector<bool> isPrime(n, true);
	isPrime[0]=false;
	isPrime[1]=false;
	int i=2;
	while(i<sqrt(n)) {
		if(isPrime[i]==true) {
			int j=i;
			while(i*j<n) {
				isPrime[i*j] =false;
				j++;
			}
		}
		i++;
	}
	vector<int> sol;
	for(int i=0; i<n; i++){
		if(isPrime[i]==true) sol.push_back(i);
	}
	return sol;
}

int main() {
	int n;
	cin>>n;

	vector<int> count = printNsmallerprime(n);
	for(int i=0; i<count.size(); i++) {
		cout<<count[i]<<endl;
	}
	return 0;
}