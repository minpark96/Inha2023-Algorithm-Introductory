#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int no;
	string name;
	Node* next;
};

class LinkedList
{
private:
	Node* head;
	Node* curr;
	Node* tail;
	int size;
public:
	LinkedList();
	~LinkedList();

	bool Empty();
	int Size();
	void InsertRear(int& no, string& name);
	void Remove(int& no);
	void Print();
};

