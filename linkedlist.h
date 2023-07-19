#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int no;
	string name;
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
	void InsertFront(int& no, string& name);
	void InsertRear(int& no, string& name);
	void Remove(int& no);
	void Print();
	void PrintReverse();
};

