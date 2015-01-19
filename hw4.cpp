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
	int inorder_r(node *node_in);
	int sum,sum_count,sum_input;
public:
	double inorder_avg(int count);

	void insert(int data_in);

	BST();
};

BST::BST(){
	node* tmp = newNode(0);
	root = *tmp;
	sum=0;
	sum_count=0;
	sum_input=0;
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

int BST::inorder_r(node *node_in){
	if (node_in->data!=0){
		BST::inorder_r(node_in->right);
		if (sum_input > sum_count){
			sum_count++;
			sum += node_in->data;
			cout << node_in->data << ",";
		}else{
			return 0;
		}

		BST::inorder_r(node_in->left);
		return 0;
	}else{
		return 0;
	}
}

double BST::inorder_avg(int count){
	sum=0;
	sum_count=0;
	sum_input=count;
	BST::inorder_r(&root);

	double ans;
	if (sum_count!=sum_input){
		ans = -1;
	}else{
		ans = ((double)sum)/count;
	}
	return ans;
}

int main(){
	BST BST;
	BST.insert(58);
	BST.insert(30);
	BST.insert(75);
	BST.insert(2);
	BST.insert(80);
	BST.insert(90);
	BST.insert(65);
	BST.insert(68);
	BST.insert(99);
	BST.insert(60);
	BST.insert(78);
	BST.insert(40);
	BST.insert(35);
	cout << BST.inorder_avg(13) << "\n";
	cout << BST.inorder_avg(14)<< "\n";
	cout << BST.inorder_avg(15)<< "\n";
	
	
    return 0;

}