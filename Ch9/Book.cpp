// C++ file for all functions related to the Book class
#include "Book.h"


Book::Book(string ISBN_in, string title_in, string author_in, string copyright_in)
{
	// First validate ISBN_in
	validate_ISBN(ISBN_in);
	ISBN = ISBN_in;
	title = title_in;
	author = author_in;
	copyright_date = copyright_in;
}

void Book::check_in()
{
	if (!checked_out) {
		throw Invalid_checkin{};
	}
	else
		checked_out = false; 
}

void Book::check_out()
{
	if (checked_out) cout << "Sorry this book has already been checked out by another customer.\n\n";
	else checked_out = true;
}

void Book::validate_ISBN(string ISBN_in)
{
	// Check if ISBN is the right length.
	if (ISBN_in.size() != 7) throw Invalid_ISBN{};

	// Check if digits are used on the right places
	for (int i : {0, 2, 4})
		if (!(isdigit(ISBN_in[i]))) throw Invalid_ISBN{};

	// Check if - is used on the right places
	for (int i : {1, 3, 5})
		if (ISBN_in[i] != '-') throw Invalid_ISBN{};

	// Check if last entry is indeed a digit or a character.
	if (!(isdigit(ISBN_in[6]) || isalpha(ISBN_in[6]))) throw Invalid_ISBN{};
}