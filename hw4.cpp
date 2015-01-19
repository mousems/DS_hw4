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
	int search_leftsize(int value);
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
	cout << "input:" << data_in << " ";
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
				cout << "\n";
			}else{
				if (tmp->data > data_in){
					tmp->leftSize++;
					tmp = tmp->left;
					cout << "left ";
				}else if(tmp->data < data_in){
					tmp = tmp->right;
					cout << "right ";
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

int BST::search_leftsize(int value){
	node *tmp;
	tmp = &root;
	int quit = 1;
	while(quit){
		if(tmp->data==0){
			return -1;
		}else{
			if (tmp->data > value){
				tmp = tmp->left;
			}else if(tmp->data < value){
				tmp = tmp->right;
			}else{
				return tmp->leftSize;
			}
		}

	}
	return -1;
}

class intQueue{
private:
	int list[100];
	int front;
	int rear;
public:
	void queue(int value);
	int dequeue();
	intQueue();

};

intQueue::intQueue(){
	front=0;
	rear=0;
}
void intQueue::queue(int value){
	if (front - 1 == rear){
		cout << "full\n";
	}else{
		list[rear] = value;
		rear++;

	}
}
int intQueue::dequeue(){
	if (front==rear){
		return -1;
	}else{
		int tmp = list[front % 100];
		front++;
		return tmp;
	}
}



int main(){
	BST BST;
	intQueue queue;
	queue.queue(1);
	queue.queue(2);
	cout << queue.dequeue() << "\n";
	queue.queue(3);
	queue.queue(4);
	cout << queue.dequeue() << "\n";
	cout << queue.dequeue() << "\n";
	queue.queue(5);
	cout << queue.dequeue() << "\n";
	cout << queue.dequeue() << "\n";
	cout << queue.dequeue() << "\n";
	queue.queue(6);
	

	cout << "Welcome , how many int you want to input? >> ";
	int times;
	cin >> times;

	int input_tmp;

	int input_array[100];

	for (int i = 1; i <= times; ++i){
		cout << "Please input No." << i << " int >>";
		cin >> input_tmp;
		BST.insert(input_tmp);
		input_array[i]=input_tmp;
	}

	for (int i = 1; i <= times; ++i){
		cout << BST.search_leftsize(input_array[i]) << ",";
	}
	

	int quit=1;
	while(quit){
		cout << "\n" << "Top n avg. you want to know? (0 for quit) >> ";
		cin >> input_tmp;
		if (input_tmp==0){
			quit=0;
		}else{
			cout << "Top " << input_tmp << "'s avg is: " << BST.inorder_avg(input_tmp) << "\n";
		}
	}
	
	
    return 0;

}