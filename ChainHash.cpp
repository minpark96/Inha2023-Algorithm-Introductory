#include "ChainHash.h"

ChainHash::ChainHash()
	: size(0)
	, table(nullptr)
{
}

ChainHash::~ChainHash()
{
	delete[] table;
}

void ChainHash::Initialize(int size)
{
	this->size = size;
	table = new LinkedList[size]{};
}

bool ChainHash::Empty()
{
	for (int i = 0; i < size; i++)
	{
		if (!table[i].Empty())
		{
			return false;
		}
	}

	return true;
}

void ChainHash::Add(const Data da)
{
	int hash = da.no % size;
	table[hash].InsertFront(da);	
}

void ChainHash::Remove(int x)
{
	int hash = x % size;
	if(!table[hash].Empty())
		table[hash].Remove(x);
	else
		cout << x << "번은 존재하지 않습니다!\n";
}

void ChainHash::Search(int x)
{
	int hash = x % size;
	if (!table[hash].Empty())
		table[hash].Search(x);
	else
		cout << x << "번은 존재하지 않습니다!\n";
}

void ChainHash::RemoveAll()
{
	for (int i = 0; i < size; i++)
	{
		if (!table[i].Empty())
		{
			table[i].RemoveAll();
		}
	}
	cout << "모두 삭제 완료!\n";
}

void ChainHash::Dump()
{
	for (int i = 0; i < size; i++)
	{
		if (i < 10)
			cout << '0';

		cout << i << " : ";

		if (!table[i].Empty())
			table[i].Print();
		
		cout << "\n";
	}
}

