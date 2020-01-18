#ifndef LIST_H
#define LIST_H

#include"Node.h"

class List
{
public:
	List();
	~List();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Node* pNode);
	int LocatedElem(Node* pNode);
	bool PriorElem(Node* pCurrentNode, Node* pPreNode);
	bool NextElem(Node* pCurrentNode, Node* pNextNode);
	void ListTraverse();
	bool ListInsert(int i, Node* pNode);
	bool ListDelete(int i, Node* pNode);
	bool ListInsertHead(Node* pNode); //insert a node behind the headnode
	bool ListInsertTail(Node* pNode); //insert a node at the tail of the chain


private:
	Node* m_pList;
	int m_iLength;

};

#endif