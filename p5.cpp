#include <iostream>
#include <queue>

using namespace std;

//Pair to insert into priority queue
struct Pair {
	char character;
	int freq;

	bool operator<(const Pair &p2) const
	{
		return freq<p2.freq;
	}
};


//To check if string can be rearranged in such way
string rearrange(string s) {
	int len = s.length();

	priority_queue<Pair> pq;

	//To count the occurence of characters
	int countChar[26]={0};

	for(int i=0; i<len; i++) {
		countChar[s[i]-97]++;
	}

	for(int i=97; i<='z'; i++){
		if(countChar[i-97]>0){
			pq.push(Pair {char(i), countChar[i-97]});
		}
	}

	Pair prev {'#', -1}; 
	string res = "";

//Iterates over pq to form resultant string
	while(!pq.empty()){
		Pair k = pq.top();
		pq.pop();

		res +=k.character;

		if(prev.freq>0){
			pq.push(prev);
		}
		(k.freq)--;
		prev=k;
	}

	if(res.length()!=len) return "NONE";
	return res;
}

int main() {
	string s;
	cout<<"Enter String"<<endl;
	cin>>s;

	string res = rearrange(s);
	cout<<res<<endl;
	return 0;
}