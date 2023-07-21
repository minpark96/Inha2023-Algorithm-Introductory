#pragma once

#include <iostream>
#include <string>
using namespace std;

struct Data
{
	int no;
	string name;
};

struct Node
{
	Data data;
	Node* next;
	Node* prev;
};

class LinkedList
{
private:
	Node* head;
	Node* curr;
	int size;
public:
	LinkedList();
	~LinkedList();

	bool Empty();
	int Size();
	void InsertFront(const Data da);
	void InsertRear(const Data da);
	void Remove(int& no);
	void RemoveAll();
	void Search(int& no);
	void Print();
	void PrintReverse();
};

