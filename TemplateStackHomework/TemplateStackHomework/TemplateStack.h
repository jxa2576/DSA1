#pragma once

#include <iostream>

using namespace std;

template <class T>
class TemplateStack
{
public:
	void Push(T);
	void Pop();
	void Print();
	int GetSize();
	bool IsEmpty();
	TemplateStack(int);
	TemplateStack(const TemplateStack &s);
	void SetTemplateStack(const TemplateStack &s);
	~TemplateStack();
private:
	T* stackData;
	T* tempStackData;
	int length;
	int dataPos;
};

//constructor
template <class T>
TemplateStack<T>::TemplateStack(int size)
{
	stackData = new T[size];
	length = size;
	dataPos = 0;
}

//Copy constructor
template <class T>
TemplateStack<T>::TemplateStack(const TemplateStack &s)
{
	stackData = new T;
	*stackData = *s;
	length = s.length;
	dataPos = s.dataPos;
}

//Copy assignement operator
template<class T>
void TemplateStack<T>::SetTemplateStack(const TemplateStack & s)
{
	stackData = new T;
	*stackData = *s;
	length = s.length;
	dataPos = s.dataPos;
}

//Pushes new data onto the stack
template <class T>
void TemplateStack<T>::Push(T newData)
{
	if (dataPos < length) {
		stackData[dataPos] = newData;
		dataPos++;
	}
	else {
		tempStackData = new T[length + 1];
		for (size_t i = 0; i < length; i++)
		{
			tempStackData[i] = stackData[i];
		}
		length++;

		tempStackData[dataPos] = newData;
		dataPos++;
		
		stackData = new T[length];
		for (size_t i = 0; i < length; i++)
		{
			stackData[i] = tempStackData[i];
		}
	}
}

//Removes data from the stack
template <class T>
void TemplateStack<T>::Pop()
{
	/*
	if (dataPos > 0) {
		stackData[dataPos - 1] = new T;
		dataPos--;
	}
	*/
	if (length > 0) {
		tempStackData = new T[length - 1];
		for (size_t i = 0; i < length - 1; i++)
		{
			tempStackData[i] = stackData[i];
		}
		length--;

		dataPos--;

		stackData = new T[length];
		for (size_t i = 0; i < length; i++)
		{
			stackData[i] = tempStackData[i];
		}
	}
}

//Prints the data of the stack
template <class T>
void TemplateStack<T>::Print()
{
	for (int i = length - 1; i > -1; i--)
	{
		T value = stackData[i];
		cout << i << ":" << value << endl;
	}
}

//Gets the size of the stack
template <class T>
int TemplateStack<T>::GetSize()
{
	return dataPos;
}

//Checks if the stack is empty
template <class T>
bool TemplateStack<T>::IsEmpty()
{
	if (dataPos == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Deconstructor
template <class T>
TemplateStack<T>::~TemplateStack()
{
	delete[] stackData;
}