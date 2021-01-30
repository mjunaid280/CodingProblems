#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	

	int size;
	cout<<"Enter array size"<<endl;
	cin>>size;

	vector<int> v(size);
	int target;

	cout<<"Enter array elem"<<endl;
	for (int i=0; i<size; i++) cin >> v[i];

	cout<<"target"<<endl;
	cin>>target;

	sort(v.begin(), v.end());
	// for (int i=0; i<size; i++) cout << v[i]<<endl;
	bool flag =false;

	int start=0, end=size-1;

	while (start<end){
		if(v[start]+v[end] == target) {
			flag=true;
			break;
		}
		else if(v[start]+v[end]<target) start++;
		else end--;
	}
	cout<<flag<<endl;
	return 0;
}