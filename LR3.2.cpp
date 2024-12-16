#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
class Base {
public:
    virtual ~Base() {
        cout << "Base  removed" << endl;
    }
    virtual void show() const {
        cout << "It's a Base component" << endl;
    }
};
class Derived : public Base {
public:
    ~Derived() override {
        cout << "Derived component removed" << endl;
    }
    void show() const override {
        cout << "It's a Derived component" << endl;
    }
};
void add(vector<Base*>& storage, Base* component) {
    try {
        storage.push_back(obj); 
    }
    catch (const bad_alloc& e) {
        cerr << "Failed allocation: " << e.what() << endl;
    }
}
int getUserInput(const string& prompt) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input, enter a valid number" << endl;
        }
        else {	
            break;
        }
    }
    return input;
}
int main() {
    srand(static_cast<unsigned>(time(0)));
    vector<Base*> storage;
    int nComponents = getUserInput("Enter the number of components to create: ");
    for (int i = 0; i < nComponents; ++i) {
        if (rand() % 2 == 0) {
            add(storage, new Base()); 
        }
        else {
            add(storage, new Derived()); 
        }
    }
    for (const auto& component : storage) {
        component->show();
    }
    for (auto& component : storage) {
        delete component;
    }
}