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

// геттеры-сеттеры
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

// метода SetLength не должно быть!

int String::GetCapacity() const
{
	return capacity;
}

void String::Clear()
{
	text[0] = '\0';
	length = 0;
}

// подгоняем capacity под length + 1
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



// отладочній метод, потом можно будет удалить
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
String& String::operator=(const String& another)
{
	if (this == &another) return *this;
	capacity = another.capacity;
	length = another.length;
	delete[] text;
	text = new char[capacity];

	for (int i = 0; i < length; i++)
		text[i] = another.text[i];
	text[length] = '\0';

	return *this;
}
char& String::operator[](int index)
{
	if (index >= 0 && index < length) return  text[index];
	else throw std::exception("out of memory!!!");
}
// return strcmp(a.text, b.text);
//void String::Concat(const char* another)
//{
//	char* text = this->text;
//	text + another.text;
//}


