#pragma once
#include<iostream>

template <class T>
struct TNode
{
	T val;
	TNode *pNext;
};
template <class T>
class TQueue
{
private:
	TNode<T> *pFirst, *pLast;
public:
	TQueue();
	~TQueue();
	TQueue(const TQueue<T>& q);
	TQueue<T>& operator=(const TQueue<T>& q);
	bool Empty()const;
	bool Full()const;
	void Push(T a);
	T Pop();
	T TFront();
	T TBack();
	int GetSize();
	int GetMaxSize();
	void Clear();
	int GetHead();
};



template <class T>///////////////
TQueue<T>::TQueue() {
	pFirst = pLast = NULL;
}

template <class T>/////////////////
TQueue<T>::~TQueue() {
	TNode<T> *tmp = pFirst;
	while (pFirst != NULL)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
	pLast = NULL;
}

template <class T>
int TQueue<T>::GetHead() {
	return 0;
}

template <class T>///////////////////
TQueue<T>::TQueue(const TQueue<T>& q) {
	TNode<T> *tmp = q.pFirst;
	if (tmp == NULL)
	{
		pFirst = pLast = tmp;
	}
	while (tmp != NULL)
	{
		Push(tmp->val);
		tmp = tmp->pNext;
	}
	delete tmp;
}

template <class T>/////////////////
int TQueue<T>::GetSize() {
	TNode<T> *p = pFirst;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->pNext;
	}
	return i;
}
template <class T>/////////////
int TQueue<T>::GetMaxSize() {
	return 1000;
}
template <class T>//////
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& q)
{
	if (this != &st)
	{
		if (!IsEmpty())
		{
			Clear();
		}
		else
		{
			TNode<T> *tmp = st.pFirst;
			if (tmp == NULL)
			{
				pFirst = tmp;
			}
			while (tmp != NULL)
			{
				Push(tmp->val);
				tmp = tmp->pNext;
			}
			delete tmp;
		}
	}
	return *this;
}

template <class T>//////////////
bool TQueue<T>::Empty()const {
	return (pFirst == NULL);
}

template <class T>/////////////////
bool TQueue<T>::Full()const {
	TNode<T> *tmp;
	tmp = new TNode<T>;
	if (tmp == NULL)
	{
		return 1;
	}
	else
	{
		delete tmp;
		return 0;
	}
}

template <class T>/////////////
void TQueue<T>::Push(T a) {
	if (Full())
	{
		char e[] = "Queue is Full";
		throw e;
	}
	else
	{
		TNode<T> *tmp = new TNode<T>;
		tmp->val = a;
		tmp->pNext = NULL;
		if (pLast != NULL)
		{
			pLast->pNext = tmp;
			pLast = tmp;
		}
		else
		{
			pFirst = pLast = tmp;
		}
	}
}

template <class T>///////////////
T TQueue<T>::Pop() {
	if (Empty())
	{
		char e[] = "Queue is Full";
		throw e;
	}
	else
	{
		T tmp = pFirst->val;
		TNode<T> *p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		return tmp;
	}
}

template <class T>/////////////////////
T TQueue<T>::TFront() {
	if (Empty())
	{
		char e[] = "Queue is Full";
		throw e;
	}
	else
	{
		return pFirst->val;
	}
}

template <class T>//////////////////////
T TQueue<T>::TBack() {
	if (Empty())
	{
		char e[] = "Stack is Full";
		throw e;
	}
	else
	{
		return pLast->val;
	}
}

template <class T>////////////////////////////
void TQueue<T>::Clear() {
	TNode<T> *tmp = pFirst;
	while (pFirst != NULL)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
	pLast = NULL;
}