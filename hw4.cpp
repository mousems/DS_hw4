#include <iostream>
using namespace std;

struct node{
	int data;
	int leftSize;
	node *left;
	node *right;
};

node* newNode(int a){
	node *tmp;
	tmp = (node *) malloc(sizeof(node));

	tmp->data = a;
	tmp->leftSize = 1;
	return tmp;
}

class BST
{
private:
	node root;
	void inorder_r(node *node_in);
	int sum;
public:
	void insert(int data_in);
	void inorder();

	BST();
};

BST::BST(){
	node* tmp = newNode(0);
	root = *tmp;
	sum=0;
}

void BST::insert(int data_in){

	if (root.data==0){
		root.data = data_in;
		node* tmp_new_l = newNode(0);
		node* tmp_new_r = newNode(0);
		root.left = tmp_new_l;
		root.right = tmp_new_r;
		cout << "\n";
	}else{

		node *tmp;
		tmp = &root;
		int quit = 1;
		while(quit){
			if (tmp->data==0){
				// got it		
				node *tmp_new_l = newNode(0);
				node *tmp_new_r = newNode(0);
				tmp->left = tmp_new_l;
				tmp->right = tmp_new_r;
				tmp->data = data_in;
				quit=0;
			}else{
				if (tmp->data > data_in){
					tmp->leftSize++;
					tmp = tmp->left;
				}else if(tmp->data < data_in){
					tmp = tmp->right;
				}
			}

		}

	}

}

void BST::inorder_r(node *node_in){
	if (node_in->data!=0){
		BST::inorder_r(node_in->right);
		cout << node_in->data << " ";
		BST::inorder_r(node_in->left);
	}
}

void BST::inorder(){
	BST::inorder_r(&root);
}

int main(){
	BST BST;
	BST.insert(5);
	BST.insert(4);
	BST.insert(6);
	BST.insert(7);
	BST.insert(3);
	BST.insert(2);
	BST.inorder();
	
	
    return 0;

}
