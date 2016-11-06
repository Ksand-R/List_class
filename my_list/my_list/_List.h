#pragma once
#include <iostream>
using namespace std;

template <class T>
struct _Node
{
	T data;
	_Node<T> *next;

	_Node<T>(T i, _Node *ptr1) { data = i; next = ptr1;}
	//Конструктор для создания нового элемента
};

template <class T>
class _List
{
private:
	int size; //счетчик числа элементов
	_Node<T> *head; 
	_Node<T> *tail;

public:
	_List() { size = 0; head = tail = NULL; }

	~_List();
	
	T viewData(_Node<T>* ptr) { return ptr->data;  }
	T* viewPtr(_Node<T>* ptr) { return ptr; }
	int GetSize() { return size; }
	void Print_list();

	bool is_list_empty(_Node<T>* head);

	void add_el_in_head(T data);
	void add_el_in_tail(T data);
	void add_node(_Node<T>* ptr, T data);

	void del_el_fr_head();
	void del_el_fr_tail();
	void del_node(_Node<T>* ptr);

	_Node<T>* find_ptr(T elem);


};


/////////////////////////////////////////////////////////////////////////////
template<class T> inline _List<T>::~_List()
{
	while (head)
	{
		_Node<T>* temp = head->next;
		delete head;
		head = temp;
	}
}

template <class T> void _List<T>::Print_list()
{
	_Node<T>* temp = head;
do
{
	cout << temp->data << endl;
	temp = temp->next;
} while (temp);

}

template <class T> bool _List<T>::is_list_empty(_Node<T>* head)
{
	if (size == 0)
	{
		return true;
	}
	else
		return false;
}

template <class T> void _List<T>::add_el_in_head(T data)
{
	_Node<T>* new_node = new _Node<T>(data, head);
	if (head == NULL)
	{
		tail = new_node;
	}
	head = new_node;
	size++;

}

template <class T> void _List<T>::add_el_in_tail(T data)
{
	_Node<T>* new_node = new _Node<T>(data, NULL);
	if (tail == NULL)
	{
		
		head = new_node;
	}
	else {
		tail->next = new_node;
	}
	tail = new_node;
	size++;
}

template <class T> void _List<T>::add_node(_Node<T>* ptr, T data)
{
	if (ptr)
	{
		_Node<T>* new_node = new _Node<T>(data, ptr->next);
		ptr->next = new_node;
		size++;
	}
	else
	{
		_Node<T>* new_node = new _Node<T>(data, NULL);
		head = new_node;
		tail = new_node;

		size++;
	}
}

template <class T> void _List<T>::del_el_fr_head()
{
	if (size)
	{
		_Node<T>* temp = head->next;
		delete head;
		head = temp;
		size--;
	}
	else
		throw 1;

}

template <class T> void _List<T>::del_el_fr_tail()
{
	if (size == 0)
	{
		throw 1;
	}
	else 
		if (size == 1)
		{
			head = tail = NULL;
			size--;
		}
		else
		{
			_Node<T>* temp = head;
			while (temp->next->next)
			{
				temp = temp->next;
			}
			temp->next = NULL;
			size--;
		}
}

template <class T> void _List<T>::del_node(_Node<T>* ptr)
{
	if (size == 0)
	{
		throw 1;
	}
	else 
		if (size == 1)
		{
			head = tail = NULL;
			size--;
		}
		else
		{
			_Node<T>* temp = ptr->next->next;
			delete ptr->next;
			ptr->next = temp;
			size--;
		}

}

template <class T> _Node<T>* _List<T> :: find_ptr(T elem)
{
	if (size == 0)
	{
		//cout << "Error" << endl;
		throw 1;
	}
		else
	{
		_Node<T>* temp = head;
		while (temp != NULL)
		{
			if (temp->data == elem)
			{
				break;	
			}
			else
			{
				temp = temp->next;
			}
		}
		if (temp == NULL)
		{
			throw 1;
		}
		return temp;
	 }
}