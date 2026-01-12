#include<iostream>
#include<string>
class Book {
    private:
        std::string m_title;
        std::string m_author;
        int m_pages;
    public:
        Book(std::string title, std::string author, int pages)
            : m_title(title), m_author(author), m_pages(pages) {}

    void display() const {
        std::cout << "Title: " << m_title << ", Author: " << m_author << ", Pages: " << m_pages << std::endl;
    }        
};

class Shelf{
    private:
        Book* m_books[10];
        int m_count;


    public:
        Shelf():m_count(0){
            for(int i=0;i<10;i++){
                m_books[i]=nullptr;
            }
        }

    Shelf& operator+=(Book* book){
        if(m_count<10){
            m_books[m_count++] = book;
        }

        else {
            std::cout<<"Shelf is full, cannot add more books."<<std::endl;
        }
        return *this;
    }

    void display() const {
        for(int i=0;i<m_count;i++){
            m_books[i]->display();
        }
    }
};

class Library{
    private:
        Shelf* m_shelves[5];
        int m_count;

    public:
        Library():m_count(0){
            for(int i=0;i<5;i++){
                m_shelves[i]=nullptr;
            }
        }

    Library& operator+=(Shelf* shelf){
        if(m_count<5){
            m_shelves[m_count++] = shelf;
        }
        else {
            std::cout<<"Library is full, cannot add more shelves."<<std::endl;
        }
        return *this;
    }

    void display() const {
        for(int i=0;i<m_count;i++){
            m_shelves[i]->display();
        }
    }
};
int main() {
    Book b1("The Hobbit", "J.R.R. Tolkien", 310);
    Book b2("Dune", "Frank Herbert", 412);
    Book b3("To Kill a Mockingbird", "Harper Lee", 281);
    Book b4("1984", "George Orwell", 328);
    Book b5("Pride and Prejudice", "Jane Austen", 279);
    
    Shelf s1, s2;
    s1+=&b1;
    s1+=&b2;
    s2+=&b3;
    s2+=&b4;
    s2+=&b5;

    Library lib;
    lib+=&s1;
    lib+=&s2;

    lib.display();

    return 0;
}