#pragma once

class Person
{
public:
	Person(const char* name, const char* address) : name(name), address(address) 
	{}; 
	virtual ~Person() { };
private:
	std::string name;
	std::string address;
};


class Student : public Person
{
public:
	Student(const char* name, const char* address, const char* schoolName, const char* schoolAddress) : Person(name, address),
		schoolName(schoolName), schoolAddress(schoolAddress)
	{};
	virtual ~Student() {};
private:
	std::string schoolName;
	std::string schoolAddress;
};

class Window
{
public:
	Window(const char* name) : wName(name)
	{}
	std::string name() const { return wName; };	// return name of window
	virtual void display() const; // draw window and contents
private:
	std::string wName;
};


class WindowWithScrollBars : public Window
{
public:
	WindowWithScrollBars(const char* name) : Window(name) {}
	virtual void display() const; // draw window and contents
};
