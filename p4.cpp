#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int numOfSwaps(vector<int> places) {
	 	int count=0;
        int size=places.size();
        int i=0;
        while(i<size-1) {
            int j=i+1;
            if(places[i]!=places[j]) {
            	 while(j<size) {
                    if(places[i]==places[j]){
                        swap(places[i+1], places[j]);
                        break;
                    }
                    j++;
                }
                count++;	
            }
            i+=2;
        }
        return count;
}

int main() {
	int n;
	cout<<"Enter number of couples "<<endl;
	cin>>n;
	vector<int> places(2*n);
	for(int i=0; i<2*n; i++) {
		cin >> places[i];
	}
	int res=numOfSwaps(places);

	cout<<res<<endl;

	return 0;
}