#include "book.h"

Book::Book(const string& title, const string& author)
    : title(title), author(author) {
}

// å �߰� �޼���
void BookManager::addBook(const string& title, const string& author) {
    books.push_back(Book(title, author)); // push_back ���
    cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
}

// ��� å ��� �޼���
void BookManager::displayAllBooks() const {
    if (books.empty()) {
        cout << "���� ��ϵ� å�� �����ϴ�." << endl;
        return;
    }

    cout << "���� ���� ���:" << endl;
    for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
        cout << "- " << books[i].title << " by " << books[i].author << endl;
    }
}

void BookManager::setBorrowManager( BorrowManager* manager)
{
    if (manager != nullptr)
    {
         borrowManager = manager;
    }

}

Book* BookManager::getBookByTitle(const string& title) const
{
    for (auto i : books)
    {
        if (title == i.title)
        {
            return &i;
        }
    }
    return nullptr;
}

Book* BookManager::getBookByAuthor(const string& Author) const
{
    for (auto i : books)
    {
        if (Author == i.author)
        {
            return &i;
        }
    }
    return nullptr;
}

Book* BookManager::findBookByTitle(const string& title)
{
    if (borrowManager!= nullptr)
    {
        if (borrowManager->borrowBook(title))
        {
            return getBookByTitle(title);
        }
        else
        {
            cout << "�ش� " << title << "�� �뿩���� ���߽��ϴ�" << endl;
            return nullptr;
        }
    }
}

Book* BookManager::findBookByAuthor(const string& author)
{
    if (borrowManager != nullptr)
    {
        
        if (borrowManager->borrowBook(getBookByAuthor(author)->title))
        {
            return getBookByAuthor(author);
        }
        else
        {
            cout << "�ش� " << getBookByAuthor(author)->title << "�� �뿩���� ���߽��ϴ�" << endl;
            return nullptr;
        }
    }
  
}

void BorrowManager::initializeStock(Book book, int quantity)
{
    stock.insert(make_pair(book.title, quantity));
}

bool BorrowManager::borrowBook(const string& title)
{

    auto it = stock.find(title);
    if (it != stock.end() && it->second > 0)
    {
        cout << it->first << "�� �뿩�߽��ϴ�" << endl;
        --it->second;
        return true;
    }
    return false;

}

bool BorrowManager::returnBook(const string& title)
{
    auto it = stock.find(title);
    if (it != stock.end())
    {
        cout << it->first << "�� �ݳ��߽��ϴ�" << endl;
        ++it->second;
        return true;
    }
    return false;
}

 void BorrowManager::displayStock()
{
    for (const auto& it : stock)
    {
        cout << "å �̸�: " << it.first << " | ���� ��: " << it.second << endl;
    }
}
