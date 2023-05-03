#include <iostream>
#include<queue>
using namespace std;

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

tree* newTree(int key)
{
	tree* temp = new tree;
	temp->data = key;
	temp->left = temp->right = NULL;
	return (temp);
}

void print(tree* tr){
	if (!tr)
		return;

	queue<tree*> q;
	q.push(tr);
	while (!q.empty()) {
		tree* temp = q.front();
		cout << temp->data << " ";
		q.pop();

		if (temp->left != NULL) {
			q.push(temp->left);
		}

		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}
}

tree* deleteEven(tree* tree){
	if (!tree) {
		return NULL;
	}

	tree->left = deleteEven(tree->left);
	tree->right = deleteEven(tree->right);

	if ((tree->data % 2 != 0) && !tree->right && !tree->left)
		return NULL;

	return tree;
}

int main()
{
	struct tree* tr = newTree(1);
	tr->left = newTree(2);
	tr->left->left = newTree(8);
	tr->left->right = newTree(10);
	tr->right = newTree(7);
	tr->right->left = newTree(12);
	tr->right->right = newTree(5);
	tr->right->right->right = newTree(4);

    print(tr);
    cout<<endl;

	tree *tr1 = deleteEven(tr);

	print(tr1);
}
