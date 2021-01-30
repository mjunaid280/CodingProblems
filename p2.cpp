#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countuni=0;

struct node 
{
    int data;
    struct node* left;
    struct node* right;

    node(int val)
    {
        data = val;
 
        // Left and right child for node
        // will be initialized to null
        left = NULL;
        right = NULL;
    }
};

//Displays numbers of Unival trees 
void display() {
	cout<<countuni<<endl;
}

//Prints the value of node in level order fashion
void traverse(node*root) {
	if(root==NULL){
		return;
	}
	else {
		traverse(root->left);
		cout<<root->data<<endl;
		traverse(root->right);
	}
}


//To insert into Binary Tree from an Array
node* insert(vector<int> v, int i, node*root) {
	int size = v.size();
	
	if(i<size) {
		node* t = new node(v[i]);
		root =t;

		root->left = insert(v, 2*i+1, root->left);
		root->right = insert(v, 2*i+2, root->right);
	}
	return root;
}

//counts number of UniVal trees
bool countuniUniValTree(node*root) {
	bool left_flag=false, right_flag=false;

	if(root->left==NULL && root->right == NULL) {
		countuni++;
		return true;
	}
	
	else {
		if(root->left == NULL) left_flag=true;
		else left_flag=countuniUniValTree(root->left);

		if(root->right == NULL) right_flag=true;
		else right_flag = countuniUniValTree(root->right);

		if((left_flag == true && right_flag ==true) && (root->data == root->left->data && root->data==root->right->data)){
			countuni++;
			return true;
		}
		else return false;
	}

}

int main(){

	// int size;
	// cout<<"Enter Size" <<endl;
	// cin >>size;

	// vector<int> v(size);

	// cout<<"Enter elem" <<endl;
	// for(int i=0; i<size; i++) {
	// 	cin>>v[i];
	// }

	node*root=new node(1);
	node*t1 = new node(1);
	node*t2 = new node(0);
	root->left = t1;
	root->right = t2;

	t2->left = new node(1);
	t2->right = new node(0);

	t1=t2->left;

	t1->left=new node(1);
	t1 ->right=new node(1);
/*	       1
	       /\
	      1  0
	     	 /\
	     	1  0
	     	/\
	       1  1
*/
	// insert(v, 0, root);
	// cout<<root->data<<endl;
	// traverse(root);
	countuni=0;
	bool flag = countuniUniValTree(root);
	cout<<"Number of UniVal trees are "<<endl;
	display();
	return 0;
}