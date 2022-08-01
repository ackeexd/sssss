#include "String.h"

String::String() : String("", 80) {}
String::String(const char* text) : String(text, 80) {}
explicit String::String(unsigned int capacity) : String("", capacity) {}
// copy c-tor
String::String(const String& original) : String(original.text, original.capacity) {}
// main c-tor
String::String(const char* text, unsigned int capacity)
{
	SetString(text, capacity);
}

String::~String()
{
	if (text != nullptr)
	{
		delete[] text;
		text = nullptr;
	}
}

// �������-�������
string String::GetString() const
{
	return text;
}

void String::SetString(const char* text, unsigned int capacity = 80)
{
	length = strlen(text);

	if (capacity <= length)
		capacity = length + 1;

	this->capacity = capacity;

	delete[] this->text;

	this->text = new char[capacity];
	strcpy_s(this->text, length + 1, text);
}

int String::GetLength() const
{
	return length;
}

// ������ SetLength �� ������ ����!

int String::GetCapacity() const
{
	return capacity;
}

void String::Clear()
{
	text[0] = '\0';
	length = 0;
}

// ��������� capacity ��� length + 1
void String::ShrinkToFit()
{
	if (capacity == length + 1)
	{
		return;
	}

	capacity = length + 1;
	char* temp = new char[capacity];
	strcpy_s(temp, capacity, text);
	delete[] text;
	text = temp;
}

void String::Concat(const char* another)
{
	string one = another;
	string two = text;
	two + one;
}

void String::Concat(int number)
{
	int one = number;
	text + one;
}

void String::Concat(double number)
{
	int one = number;
	text + one;
}

bool String::Contains(string another) const
{
	string one = text;
    bool found = one.find(another) != std::string::npos;
    if (found) {
		cout << "String found\n";
	}
	else {
		cout << "String not found\n";
	}

	return 0;
}



// ��������� �����, ����� ����� ����� �������
void String::ShowInfo() const
{
	cout << "Text: " << GetString() << endl;
	cout << "Length: " << GetLength() << endl;
	cout << "Capacity: " << GetCapacity() << endl;
}
void String::Print() const
{
	cout << GetString();
}
void String::PrintLn() const
{
	cout << GetString() << "\n";
}
void String::GetLine()
{
	cout << "vvedite text\n";
	cin >> text;
}
const char* String::GetCharArray(unsigned int index) const
{
	
	if (index <= length) cout << text[index];
	else cout << "error\n";
	
}
// return strcmp(a.text, b.text);
//void String::Concat(const char* another)
//{
//	char* text = this->text;
//	text + another.text;
//}


