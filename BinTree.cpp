#include "BinTree.h"

BinTree::BinTree()
	: root(nullptr)
	, curr(nullptr)
{
}

BinTree::~BinTree()
{
	if (root != nullptr)
	{
		Free(root);
	}
}

bool BinTree::Empty() const
{
	if (root == nullptr)
		return true;
	else
		return false;
}

void BinTree::Insert(const Data& da)
{
	Node* tmp = new Node{ da };
	if (root == nullptr)
	{
		// Ʈ���� �������! -> ��Ʈ�� �߰���
		root = tmp;
	}
	else
	{
		curr = root;
		while (true)
		{
			if (curr->data.no > tmp->data.no)
			{
				if (curr->leftChild == nullptr)
				{
					curr->leftChild = tmp;
					return;
				}
				else
					curr = curr->leftChild;
			}
			else if (curr->data.no < tmp->data.no)
			{
				if (curr->rightChild == nullptr)
				{
					curr->rightChild = tmp;
					return;
				}
				else
					curr = curr->rightChild;
			}
			else
			{
				// �ߺ������� ���� �Ұ���!
				cout << "�ߺ��� ��ȣ�Դϴ�!\n";
				return;
			}
		}
	}
}

bool BinTree::Remove(int x)
{
	Node* parent = nullptr;
	curr = Search(x);
	if (curr == nullptr) return false;

	parent = PickParent(curr);

	// ã�Ҵ�!
	if (curr->leftChild != nullptr && curr->rightChild != nullptr)
	{
		// �ڽ� �ΰ�
		Node* max = PickLargest(curr->leftChild);
		if (max != curr->leftChild)
			max->leftChild = curr->leftChild;
		max->rightChild = curr->rightChild;

		if (parent != nullptr)
		{
			if (parent->leftChild == curr)
				parent->leftChild = max;
			else
				parent->rightChild = max;
		}
		else
		{
			root = max;
		}
	}
	else if (curr->leftChild != nullptr)
	{
		// ���� �ڽ� �Ѱ�
		if (parent != nullptr)
		{
			if (parent->leftChild == curr)
				parent->leftChild = curr->leftChild;
			else
				parent->rightChild = curr->leftChild;
		}
		else
		{
			root = curr->leftChild;
		}
	}
	else if (curr->rightChild != nullptr)
	{
		// ������ �ڽ� �Ѱ�
		if (parent != nullptr)
		{
			if (parent->leftChild == curr)
				parent->leftChild = curr->rightChild;
			else
				parent->rightChild = curr->rightChild;
		}
		else
		{
			root = curr->rightChild;
		}
	}
	else
	{
		// �ڽ� ����
		if (parent != nullptr)
		{
			if (parent->leftChild == curr)
				parent->leftChild = nullptr;
			else
				parent->rightChild = nullptr;
		}
		else
		{
			root = nullptr;
		}
	}
	
	delete curr;
	return true;
}

Node* BinTree::Search(int x)
{
	curr = root;
	while (curr != nullptr)
	{
		if (curr->data.no > x)
		{
			curr = curr->leftChild;
		}
		else if (curr->data.no < x)
		{
			curr = curr->rightChild;
		}
		else
		{
			return curr;
		}
	}

	return nullptr;
}

void BinTree::Print(Node* node)
{
	if (node->leftChild != nullptr)
	{
		Print(node->leftChild);
	}

	cout << node->data.no << ' ' << node->data.name << "\n";

	if (node->rightChild != nullptr)
	{
		Print(node->rightChild);
	}
}

void BinTree::Free(Node* node)
{
	if (node->leftChild != nullptr)
	{
		Free(node->leftChild);
	}

	if (node->rightChild != nullptr)
	{
		Free(node->rightChild);
	}

	delete node;
}

Node* BinTree::PickLargest(Node* node)
{
	Node* parent = nullptr;
	while (node->rightChild != nullptr)
	{
		parent = node;
		node = node->rightChild;
	}
	if (parent != nullptr)
	{
		if (node->leftChild != nullptr)
		{
			parent->rightChild = node->leftChild;
		}
		else
		{
			parent->rightChild = nullptr;
		}
	}
	return node;
}

Node* BinTree::PickParent(Node* node)
{
	if (root == node)
	{
		return nullptr;
	}
	else
	{
		Node* curr = root;
		while (true)
		{
			if (curr->leftChild == node || curr->rightChild == node)
			{
				// �θ� ã��
				return curr;
			}
			else
			{
				if (node->data.no > curr->data.no)
				{
					curr = curr->rightChild;
				}
				else
				{
					curr = curr->leftChild;
				}
			}
		}
	}
}
