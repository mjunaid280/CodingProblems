#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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

	bool flag=false;

	unordered_map <long , long> map;

	for(int i=0; i<size; i++) {

		if(map.find(target-v[i])!=map.end()) {
			flag=true;
			break;
		}
		else {
			map[v[i]]=i;
		}
	}

	cout<<flag<<endl;

	return 0;
}