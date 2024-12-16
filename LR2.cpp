#include <iostream>
#include <string>
using namespace std;
class Publication {
protected:
    string title;
    float price;
public:
    void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }
    void putData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};
class Sales {
protected:
    float salesData[3];
public:
    void getSalesData() {
        cout << "Enter sales data for the last three months:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> salesData[i];
        }
    }
    void putSalesData() const {
        cout << "Sales data for the last three months:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Month " << i + 1 << ": " << salesData[i] << endl;
        }
    }
};
class Book : public Publication, public Sales {
private:
    int numPages;
public:
    void getData() {
        Publication::getData();
        cout << "Enter number of pages: ";
        cin >> numPages;
        Sales::getSalesData();
    }
    void putData() const {
        Publication::putData();
        cout << "Number of pages: " << numPages << endl;
        Sales::putSalesData();
    }
};
class Tape : public Publication, public Sales {
private:
    float playTime;
public:
    void getData() {
        Publication::getData();
        cout << "Enter play time (in minutes): ";
        cin >> playTime;
        Sales::getSalesData();
    }
    void putData() const {
        Publication::putData();
        cout << "Play time: " << playTime << " minutes" << endl;
        Sales::putSalesData();
    }
};
int main() {
    Book book;
    Tape tape;
    cout << "Enter data for the book: " << endl;
    book.getData();
    cout << "\nEnter data for the tape: " << endl;
    tape.getData();
    cout << "\nBook details:" << endl;
    book.putData();
    cout << "\nTape details:" << endl;
    tape.putData();
}