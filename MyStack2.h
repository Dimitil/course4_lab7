#pragma once
#include <iostream>

template <typename T>
class Node {
	T m_Data;
	Node* m_pNext;


	Node() : m_Data(), m_pNext(nullptr) {}

	Node(const T& t) : m_Data(t), m_pNext(nullptr) {}

	Node(Node<T>* prev, const T& data) : m_Data(data)
	{
		m_pNext = prev->m_pNext;
		prev->m_pNext = this;
	}


	template <typename T> friend class MyStack2;
};

template <typename T>
class MyStack2 {

	Node<T> m_Head;
	size_t m_size = 0;
public:
	MyStack2() {}

	MyStack2(const MyStack2<T>& other) : m_size(other.m_size)//êîíñòðóêòîð êîïèðóþùèé
	{
		Node <T>* otherIt = other.m_Head.m_pNext;
		Node<T>* it = &m_Head;
		while (otherIt) {
			it = new Node<T>(it, otherIt->m_Data);
			otherIt = otherIt->m_pNext;
		}
	}

	MyStack2(MyStack2&& other) :m_size(other.m_size)//êîíñòðóêòîð ïåðåìåùàþùèé
	{
		m_Head.m_pNext = other.m_Head.m_pNext;
		other.m_Head.m_pNext = nullptr;
		other.m_size = 0;
	}

	void removeAll()
	{

		while (m_Head.m_pNext)
		{
			Node <T>* tmp = m_Head.m_pNext;
			m_Head.m_pNext = tmp->m_pNext;
			delete tmp;
            tmp = nullptr;
		}
		m_size = 0;
	}


	MyStack2& operator=(MyStack2&& other) //îïåðàòîð ïåðåìåùåíèÿ
	{
		if (this == &other) { return *this; }

		removeAll();

		m_Head.m_pNext = other.m_Head.m_pNext;
		other.m_Head.m_pNext = nullptr;
		m_size = other.m_size;
		other.m_size = 0;

	}

	MyStack2& operator=(const MyStack2& other) //îïåðàòîð ïðèñâàèâàíèÿ
	{
		if (this == &other) { return *this; }
		
		const Node<T>* otherIt = &(other.m_Head);
		Node<T>* thisIt = &m_Head;

		while (otherIt->m_pNext && thisIt->m_pNext)
		{
			thisIt->m_pNext->m_Data = otherIt->m_pNext->m_Data;
					
			otherIt = otherIt->m_pNext;
			thisIt = thisIt->m_pNext;
		}

		while (otherIt->m_pNext)
		{
			thisIt = new Node<T>(thisIt, otherIt->m_pNext->m_Data);
			otherIt = otherIt->m_pNext;
		}

		while (thisIt->m_pNext)
		{
			Node<T>* tmp = thisIt->m_pNext;
			thisIt->m_pNext = tmp->m_pNext;
			delete tmp;
			tmp = nullptr;
		}
	}

	~MyStack2() 
	{
		while (m_Head.m_pNext)
		{
			Node <T>* tmp = m_Head.m_pNext;
			m_Head.m_pNext = tmp->m_pNext;
			delete tmp;
			tmp = nullptr;
		}
	}



	void push(const T& t)
	{
		Node <T>* tmp = new Node<T>(t);
		tmp->m_pNext = m_Head.m_pNext;
		m_Head.m_pNext = tmp;
		++m_size;
	}

	T pop()
	{
		if (!m_size) { throw std::exception(); }

		T return_data(std::move(m_Head.m_pNext->m_Data));
		Node<T>* delete_Node = m_Head.m_pNext;
		m_Head.m_pNext = m_Head.m_pNext->m_pNext;
		delete delete_Node;
		--m_size;
		return return_data;
	}
	

	void printNode(Node<T>* it)
	{
		if (it) {
			printNode(it->m_pNext);
			std::cout << it->m_Data << '\n';
		}
		return;
	}

	void print()
	{
		printNode(m_Head.m_pNext);
	}


};
