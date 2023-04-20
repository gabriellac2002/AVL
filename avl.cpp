#include<bits/stdc++.h>
using namespace std;

class Node //construtor do no
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

int height(Node *N) //função pra ver o tamanho da arvore
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b) //pra ver qual é maior
{
	return (a > b)? a : b;
}

Node* newNode(int key) //cria um novo no
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
	return(node);
}

Node *rightRotate(Node *y) //rotação a direita
{
	Node *x = y->left;
	Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left),height(y->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;

	return x;
}

Node *leftRotate(Node *x) //rotação a esquerda
{
	Node *y = x->right;
	Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	return y;
}

int getBalance(Node *N) //faz o balanceamento
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key) //faz a inserção por recursividade
{
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;

	node->height = 1 + max(height(node->left),height(node->right));

	int balance = getBalance(node);

	// caso 1
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Rcaso 2
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// caso 3
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
    //caso 3
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void print(Node *root) //printa a arvore
{
	if(root != NULL)
	{
		cout << root->key << " ";
		print(root->left);
		print(root->right);
	}
}

//main pra teste
int main()
{
	Node *root = NULL;
	
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	
	cout << "Arvore AVL construida:" <<endl;
	print(root);
	
	return 0;
}

