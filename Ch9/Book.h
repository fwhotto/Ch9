#pragma once
#include <iostream>
using namespace std;

class Book
{
public:
	// For throwing errors
	class Invalid_ISBN {}; 
	class Invalid_checkin {};
	// Contructor declaration
	Book(string ISBN_in, string title_in, string author_in, string copyright_in);
	// Getters for the membervars
	string get_ISBN() { return ISBN; }
	string get_title() { return title; }
	string get_author() { return author; }
	string get_copyright() { return copyright_date; }
	bool ischecked_out() { return checked_out; }
	// Check in and check out functions
	void check_in();
	void check_out();
	// Operater overloading
	bool operator==(Book const& book2) { return (ISBN == book2.ISBN); }
	bool operator!=(Book const& book2) { return (ISBN != book2.ISBN); }
private:
	string ISBN;
	string title;
	string author;
	string copyright_date;
	bool checked_out = false;
	// A function declaration for increasing constructor readability.
	void validate_ISBN(string ISBN_in);
};

