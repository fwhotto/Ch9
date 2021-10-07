/*Exercises chapter 9.*/

#include <iostream>
//#include "Date.h"
#include "Book.h"
using namespace std;


// Working trough some concepts with Jason
//int main()
//{
//    using Chrono::Date;
//    using Chrono::Month;
//    try {
//        Date date{ 110,Month::feb, 6 };
//    }
//    catch(Chrono::Ivalid_date){
//        cerr << "You egghead!!\n";
//    }
//}

// Operator overloading, would you put this in one namespace with book?
ostream& operator<<(ostream& os,Book book)
{
	string title_line = "Title: " + book.get_title() + "\n";
	string author_line = "Author: " + book.get_author() + "\n";
	string ISBN_line = "ISBN: " + book.get_ISBN() + "\n";
	string checked_line;
	if (book.ischecked_out())
		checked_line = "Checked out: True\n";
	else
		checked_line = "Checked out: False\n";

	return os << title_line + author_line + ISBN_line + checked_line + "\n";
}

// Demonstrates checkin and checkout.
void demo_ex5_1()
{
	string ISBN = "7-8-3-L";
	string title = "Dune";
	string author = "Frank Herbert";
	string copyright_date = "1980";
	Book myfav_book = Book(ISBN, title, author, copyright_date);

	cout << myfav_book;
	myfav_book.check_out();
	cout << myfav_book;
	myfav_book.check_out();
	myfav_book.check_in();
	cout << myfav_book;
	myfav_book.check_in();
	
}

// Demonstrates simple input data validation.
void demo_ex5_2()
{
	string ISBN = "7-K-3-L";
	string title = "Dune";
	string author = "Frank Herbert";
	string copyright_date = "1980";
	Book myfav_book = Book(ISBN, title, author, copyright_date);
}

// Demonstrates comparison operators.
void demo_ex6()
{
	string ISBN = "7-8-3-L";
	string title = "Dune";
	string author = "Frank Herbert";
	string copyright_date = "1980";
	Book myfav_book = Book(ISBN, title, author, copyright_date);

	string ISBN2 = "1-2-3-A";
	string title2 = "The most boring text ever";
	string author2 = "Qeirdo";
	string copyright_date2 = "2012";
	Book badbook = Book(ISBN2, title2, author2, copyright_date2);

	cout << "Is my favorite book the same as bad book: " << (myfav_book == badbook) << "\n";
	cout << "Is my favorite book not the same as bad book: " << (myfav_book != badbook) << "'\n";
}

int main()
{
	try {
		demo_ex5_1();
	}
	catch (Book::Invalid_ISBN) {
		cout << "Sorry invalid ISBN, please use n-n-n-x";
	}
	catch (Book::Invalid_checkin) {
		cout << "This book is already checked in? How did you acquire this manuscript?\n";
	}
	return 0;
}

