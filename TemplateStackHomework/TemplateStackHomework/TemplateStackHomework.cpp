// TemplateStackHomework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TemplateStack.h"
#include <iostream>
#include <string>

int main()
{
	//Testing with int
	cout << "Int Stack Start" << endl;
	TemplateStack<int> intS(3);
	intS.Print();
	bool isEmpty = intS.IsEmpty();
	cout << "Size: " << intS.GetSize() << " Empty: " << isEmpty << endl;
	intS.Push(0);
	intS.Push(1);
	intS.Push(2);
	intS.Push(3);
	intS.Push(4);
	intS.Push(5);
	intS.Print();
	isEmpty = intS.IsEmpty();
	cout << "Size: " << intS.GetSize() << " Empty: " << isEmpty << endl;
	cout << "Int Stack Finish" << endl;

	cout << " " << endl;

	//Testing with string
	cout << "String Stack Start" << endl;
	TemplateStack<string> stringS(3);
	stringS.Print();
	bool stringEmpty = stringS.IsEmpty();
	cout << "Size: " << stringS.GetSize() << " Empty: " << stringEmpty << endl;
	stringS.Push("one");
	stringS.Push("two");
	stringS.Push("three");
	stringS.Push("four");
	stringS.Push("five");
	stringS.Pop();
	stringS.Push("six");
	stringS.Print();
	stringEmpty = stringS.IsEmpty();
	cout << "Size: " << stringS.GetSize() << " Empty: " << stringEmpty << endl;
	cout << "String Stack Finish" << endl;

	cout << " " << endl;

	//Testing with char
	cout << "Char Stack Start" << endl;
	TemplateStack<char> charS(3);
	charS.Print();
	bool charEmpty = charS.IsEmpty();
	cout << "Size: " << charS.GetSize() << " Empty: " << charEmpty << endl;
	charS.Push('a');
	charS.Push('b');
	charS.Push('c');
	charS.Push('d');
	charS.Push('e');
	charS.Pop();
	charS.Pop();
	charS.Push('x');
	charS.Push('y');
	charS.Push('z');
	charS.Print();
	charEmpty = charS.IsEmpty();
	cout << "Size: " << charS.GetSize() << " Empty: " << charEmpty << endl;
	cout << "Char Stack Finish" << endl;

    return 0;
}

