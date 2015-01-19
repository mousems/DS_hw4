#include <iostream>
using namespace std;

struct node{
	int data;
	int leftSize;
	node *left;
	node *right;
};

node newNode(int a){
	node tmp;
	tmp.data = a;
	tmp.leftSize = 1;
	return tmp;
}

// class BST
// {
// public:
// 	void insert(int data_in);
// private:
// 	node root;
// };

// void BST::insert(int data_in){

// 	while
// }

int main(){
	node a = newNode(5);
	node b = newNode(6);
	a.left = &b;

	cout << a.left->data;
    return 0;

}
