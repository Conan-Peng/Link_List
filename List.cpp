#include <iostream>
using namespace std;

#include "List.h"

List::List()
{
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

bool List::ListEmpty()
{
	if (m_iLength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int List::ListLength()
{
	return m_iLength;
}

void List::ClearList()
{
	Node *currentNode = m_pList->next;
	while (currentNode != NULL)
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;
}

List::~List()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

bool List::ListInsertHead(Node* pNode)  //insert a node behind the headnode
{
	Node* temp = m_pList->next;
	Node* newNode = new Node;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}

bool List::ListInsertTail(Node* pNode) //insert a node at the tail of the chain
{
	Node* currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;//遍历所有节点

	}
	Node* newNode = new Node; //从堆中分配内存
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;

}

bool List::ListInsert(int i, Node* pNode)
{
	if (i < 0 || i > m_iLength)
	{
		return false;
	}
	Node* currentNode = m_pList;
	for (int k = 0; k < i; k++)
	{
		currentNode = currentNode->next;
	}
	Node* newNode = new Node;
	if (newNode == NULL)
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

bool List::ListDelete(int i, Node* pNode)//delete ith node and return this node
{
	if (i < 0 || i >= m_iLength)
	{
		return false;
	}
	Node* currentNode = m_pList;
	Node* currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}

bool List::GetElem(int i, Node* pNode)
{
	if (i < 0 || i >= m_iLength)
	{
		return false;
	}
	Node* currentNode = m_pList;
	for (int k = 0; k <= i; k++)
	{
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;

}

int List::LocatedElem(Node* pNode)
{
	Node* currentNode = m_pList;
	int count = 0;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data)
		{
			return count;
		}
		count++;

	}
	return -1;
}

bool List::PriorElem(Node* pCurrentNode, Node* pPreNode)//快速过一遍，入门就可以，这不是现阶段的重点
{
	Node* currentNode = m_pList;
	Node* tempNode = NULL;
	while (currentNode->next != NULL)
	{
		tempNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data)
		{
			if (tempNode == m_pList)
			{
				return false;
			}
			pPreNode->data = tempNode->data;
			return true;
		}

	}
}

bool List::NextElem(Node* pCurrentNode, Node* pNextNode)
{
	Node* currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		
		if (currentNode->data == pCurrentNode->data)
		{
			if (currentNode->next == NULL)
			{
				return false;
			}
			pNextNode->data = currentNode->next->data;
			return true;
		}
		currentNode = currentNode->next;
	}
	return false;
}

void List::ListTraverse()
{
	Node* currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}