#include<iostream>
#include<string>
#include <iomanip>
#include <cctype>
using namespace std;

class Book
{
    private:
        string book_name;
        int ISBN;
        string author_name;
        string link;
    public:
        Book():book_name("") , ISBN(),author_name(""),link("") {}
        Book(string book_name,int ISBN, string author_name, string link): book_name(book_name),ISBN(ISBN),author_name(author_name),link(link){}
        string get_book_name() {return book_name;}
        int get_ISBN() { return ISBN;}
        string get_author_name() { return author_name;}
        string get_link() { return link;}
        
};

class Library
{
    private:
        Book book[8];
        int number_books=0;
    public:
        void ADD(Book new_book)
        {
            if (number_books <8)
            {
                book[number_books]=new_book;
                number_books++;
            }
            else
            {
                for (int i=1;i<8;i++)
                {
                    book[i-1]=book[i];
                }
                book[number_books-1]=new_book;
            }
            
            return;
        }
        void SEARCH()
        {
            cout.width(10); cout << left << "index" << " | ";
            cout.width(10); cout << right << "book name" << " | ";
            cout.width(10); cout << right << "author name" << endl;
            for (int i=0 ; i<number_books ;i++)
            {
                string book_name=book[i].get_book_name();
                string author_name=book[i].get_author_name();
                cout.width(10); cout << left << i << " | ";
                cout.width(10); cout << right << string_modified(book_name) << " | ";
                cout.width(10); cout << right << string_modified(author_name) << endl;
            }
            return;
        }
        void search2(int k)
        {
            string book_name=book[k].get_book_name();
            string author_name=book[k].get_author_name();
            cout.width(10); cout << left << "index" << " | ";
            cout.width(10); cout << right << "book name" << " | ";
            cout.width(10); cout << right << "author name" << endl;
            cout.width(10); cout << left << k << " | ";
            cout.width(10); cout << right << string_modified(book_name) << " | ";
            cout.width(10); cout << right << string_modified(author_name) << endl;
            return;
        }
        int get_number_book(){return number_books;}

        string string_modified(string s)
        {
            if( s.length()< 10){ return s;}
            else
            {
                string t = s.substr(0,10);
                string final = t.replace(9,1,".");
                return final;
            }
        }

};

int main()
{
    Library library;
    while (true)
    {
        string command;
        cout << "choose one of these commands : ( ADD,SEARCH,EXIT) :";
        cin >> command;
        if (command == "ADD")
        {
            string book_name; string author_name; string link ; int ISBN;
            cout << "enter book name: ";
            cin >> book_name;
            cout << "enter the ISBN: ";
            cin >> ISBN;
            cout << "enter author name: ";
            cin >> author_name;
            cout << "enter the link: ";
            cin >> link;
            Book new_book{book_name,ISBN,author_name,link};
            library.ADD(new_book);

        }
        else if ( command == "SEARCH")
        {
            cout << "the containt of the library:" << endl;
            library.SEARCH();
            int index;
            cout << "choose the index: ";
            while (true)
            {
                cin >> index;
                if ( index > (library.get_number_book()-1) || (library.get_number_book()-1) <0)
                { 
                    cout << "book not valid." << endl<< "choose a valid index : "; 
                }
                else
                {
                    library.search2(index);
                    break;
                }
            }
        }
        else if ( command == "EXIT")
        {
            return 0;
        }
    }
    return 0;

}
