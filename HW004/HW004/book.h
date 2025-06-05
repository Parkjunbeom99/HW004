#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class BorrowManager;
class Book {
public:
    string title;
    string author;
    

    Book(const string& title, const string& author);
};

class BookManager {
private:
    vector<Book> books; // å ��� ����
    BorrowManager* borrowManager;
public:
    
    // å �߰� �޼���
    void addBook(const string& title, const string& author);

    // ��� å ��� �޼���
    void displayAllBooks() const;
    void setBorrowManager(BorrowManager* manager);
    Book* getBookByTitle(const string& title)const;
    Book* getBookByAuthor(const string& Author)const;
    Book* findBookByTitle(const string& title);
    Book* findBookByAuthor(const string& author);

};
class BorrowManager
{
private:
    unordered_map<string, int> stock;
public:
    void initializeStock(Book book, int quantity = 3);
    bool borrowBook(const string& title);
    bool returnBook(const string& title);
    void displayStock();

};