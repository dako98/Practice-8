#include <iostream>
#include <fstream>




struct Node
{
	Node(int value)
		:value(value)
		, left(nullptr)
		, right(nullptr)
	{}

	int value;
	Node* left;
	Node* right;
};

void Insert(Node* &root, int num)
{
	if (root == nullptr)
		root = new Node(num);

	if (num < root->value)
		Insert(root->left, num);

	if(num>root->value)
		Insert(root->right, num);
}


Node*& MostRight(Node* &root)
{
	if (root->right==nullptr)
		return root;
	else
		return MostRight(root->right);
}

void Remove(Node* &root, int num)
{
	//Implement the other cases - for last element (leaf) and for element with one child.
	if (root == nullptr) return;

	if (root->value == num)
	{
		if (root->left==nullptr && root->right==nullptr)
		{
			delete root;

		}
		root->value = MostRight(root->left)->value;

		if (MostRight(root->left)->left != nullptr)
		{ }
		else
		{
			Node** tmp = &MostRight(root->left);
			
			delete *tmp;
			*tmp = nullptr;
			return;
		}
	}
	if (num<root->value)
	{
		Remove(root->left, num);
	}
	if (num > root->value)
	{
		Remove(root->right, num);
	}
}


void PrintAsc(Node* root)
{
	if (root->left)
		PrintAsc(root->left);

	std::cout << root->value << ' ';

	if (root->right)
		PrintAsc(root->right);
}

void PrintDesc(Node* root)
{
	if (root->right)
		PrintDesc(root->right);

	std::cout << root->value << ' ';

	if (root->left)
		PrintDesc(root->left);
}

int main()
{
	Node* root = new Node(10);

//	Insert(root, 10);
	Insert(root, 5);
	Insert(root, 3);
	Insert(root, 7);
	Insert(root, 4);

	PrintAsc(root);
	std::cout << "\n\n\n";
	PrintDesc(root);

	Remove(root, 5);

	PrintAsc(root);

	return 0;
}