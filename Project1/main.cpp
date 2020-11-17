#include<iostream>

using namespace std;

class Uncopyable {
    protected:
        Uncopyable(){}
        ~Uncopyable(){}
    private: 
        Uncopyable(const Uncopyable&);
        Uncopyable& operator = (const Uncopyable&);
};

// class Book: private Uncopyable {

class Book {
    private:
        string title;
        string author;
        int pages;
        int timesRead;
        // Item 6
        // Book(const Book&);
        // Book& operator = (const Book&);
    public:
        Book();
        Book(string title, string author, int pages);
        ~Book();
        void getTitle();
        void getAuthor();
        void getPages();  
        void getTimesRead();  
        void changeTimesRead();    
};

Book::Book()
{

}

//Item 4
Book::Book(string title, string author, int pages):
    title(title),
    author(author),
    pages(pages),
    timesRead(0)
{
    cout<<"Book constructor: "<<" "<<this->title<<" "<<this->author<<" "<<this->pages<<" "<<this->timesRead<<"\n";
}

Book::~Book()
{
    cout<<"Book Destructor! \n";
}

void Book::getTitle(){
    cout<<"Book title: "<<this->title<<"\n";
}

void Book::getAuthor(){
    cout<<"Book author: "<<this->author<<"\n";
}

void Book::getPages(){
    cout<<"Book pages: "<<this->pages<<"\n";
}

void Book::getTimesRead(){
    cout<<"Book times read: "<<this->timesRead<<"\n";
}

void Book::changeTimesRead(){
    this->timesRead = this->timesRead + 1;
}

int main(){
    cout<<"Main \n";

    cout<<"Basic book \n";
    Book basic_book;
    basic_book.getTitle();
    basic_book.getTimesRead();
    cout<<"\n";

    cout<<"Book1 \n";
    Book book1("Origin", "Jane", 321);
    book1.getTitle();
    book1.getAuthor();
    book1.getPages();
    book1.getTimesRead();
    cout<<"\n";

    // Item 5
    cout<<"Book1 copy \n";
    Book book1_copy(book1);
    book1_copy.getTitle();
    book1_copy.getAuthor();
    book1_copy.getPages();
    book1_copy.getTimesRead();
    cout<<"\n";

    cout<<"Updated times read Book1: \n";
    book1.changeTimesRead();
    book1.getTimesRead();
    cout<<"\n";

    cout<<"Times read Book1 copy: \n";
    book1_copy.getTimesRead();
    cout<<"\n";

    return 0;
}