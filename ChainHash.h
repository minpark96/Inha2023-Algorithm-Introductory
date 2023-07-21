#pragma once

#include "linkedlist.h"

class ChainHash
{
private:
	int size;
	LinkedList* table;

public:
	void Initialize(int size);
	bool Empty();
	void Add(const Data da);
	void Remove(int x);
	void Search(int x);
	void RemoveAll();
	void Dump();

public:
	ChainHash();
	~ChainHash();

};

