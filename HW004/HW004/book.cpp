#include "book.h"

Book::Book(const string& title, const string& author)
    : title(title), author(author) {
}

// 책 추가 메서드
void BookManager::addBook(const string& title, const string& author) {
    books.push_back(Book(title, author)); // push_back 사용
    cout << "책이 추가되었습니다: " << title << " by " << author << endl;
}

// 모든 책 출력 메서드
void BookManager::displayAllBooks() const {
    if (books.empty()) {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }

    cout << "현재 도서 목록:" << endl;
    for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
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
            cout << "해당 " << title << "을 대여하지 못했습니다" << endl;
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
            cout << "해당 " << getBookByAuthor(author)->title << "을 대여하지 못했습니다" << endl;
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
        cout << it->first << "를 대여했습니다" << endl;
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
        cout << it->first << "를 반납했습니다" << endl;
        ++it->second;
        return true;
    }
    return false;
}

 void BorrowManager::displayStock()
{
    for (const auto& it : stock)
    {
        cout << "책 이름: " << it.first << " | 남은 수: " << it.second << endl;
    }
}
