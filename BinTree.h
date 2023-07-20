#pragma once
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;

struct Data
{
	int no;
	string name;
};

struct Node
{
	Data data;
	Node* leftChild;
	Node* rightChild;
};

class BinTree
{
private:
	Node* root;
	Node* curr;

public:
	bool Empty() const;
	void Insert(const Data& da);
	bool Remove(int x);
	Node* Search(int x);
	void Print(Node* node);
	Node* GetRoot() const { return root; }
	void Free(Node* node);
	Node* PickLargest(Node* node);
	Node* PickParent(Node* node);

public:
	BinTree();
	~BinTree();
};

