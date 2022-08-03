#include <iostream>
#include <string>
using namespace std; 
#pragma once

class String
{
	char* text = nullptr;
	unsigned int length = 0;
	unsigned int capacity = 80;

public:
	String() : String("", 80) {};

	String(const char* text) : String(text, 80) {};

	String(unsigned int capacity) : String("", capacity) {};

	// copy c-tor
	String(const String& original) : String(original.text, original.capacity) {};

	// main c-tor
	String(const char* text, unsigned int capacity) {};

	~String();

	string GetString() const;
	void SetString(const char* text, unsigned int capacity = 80);
	int GetLength() const;
	int GetCapacity() const;
	void Clear();
	void ShrinkToFit();
	void ShowInfo() const;
	void Print() const;
	void PrintLn() const;
	void GetLine();
	const char*  GetCharArray(unsigned int index) const;
	// return strcmp(a.text, b.text);
	void Concat(const char* another);
	void Concat(int number);
	void Concat(double number);
	bool Contains(string another) const;
	String& operator=(const String& another);
	String& operator=(const char* text);
	char& operator[](int index);

};

