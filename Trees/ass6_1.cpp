#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

struct node_user_input {
	int data;
	int left;
	int right;
};

int getDepth(node* root) {
	if (root == 0) {
		return 0;
	}
	else {
		int depth_left = getDepth(root->left);
		int depth_right = getDepth(root->right);

		if (depth_left > depth_right) { return depth_left + 1;}
		else { return depth_right + 1;}
	}
}

node* newNode(int data) {
	node* temp = new node;
	
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

node* addNode(node* root, queue<node_user_input> &q) {
	node_user_input to_add = q.front();

	if (root == NULL) { root = newNode(to_add.data);}
	
	if (root->data == to_add.data) {
		if (to_add.left != 0) {
			root->left = newNode(to_add.left);
		}
		if (to_add.right != 0) {
			root->right = newNode(to_add.right);
		}			
	
		q.pop();
		
		if (root->left != NULL) {
			addNode(root->left, q);
		}
	
		if (root->right != NULL) {
			addNode(root->right, q);
		}		
	}
	
	if (root->left != NULL && !q.empty()) {
		addNode(root->left, q);
	}
	
	if (root->right != NULL && !q.empty()) {
		addNode(root->right, q);
	}
	
	return root;
}

node* constructTreeFromUserInput() {
	int nr_nodes;
	cin >> nr_nodes;
	
	node* root = NULL;
	queue<node_user_input> q;
	
	for(int i=0;i<nr_nodes;i++)
	{
		int data, left, right;
		cin >> data >> left >> right;
		node_user_input new_node;
		new_node.data = data;
		new_node.left = left;
		new_node.right = right;
		q.push(new_node);	
	}
	
	root = addNode(root, q);	
	return root;
}

void cleanTree(node* root) {	
	if (root == NULL) { return;}
	
	cleanTree(root->left);
	cleanTree(root->right);

	delete root;
}

int main()
{
	node* root = constructTreeFromUserInput();
	cout << "depth is " << getDepth(root) << endl;
	cleanTree(root);
	return 0;
}
