#include <iostream>
#include <vector>
using namespace std;
class Detail {
protected:
    Detail() { cout << "Detail created" << endl; }
public:
    virtual ~Detail() { cout << "Detail removed" << endl; }
    virtual void info() const = 0;
    template <typename E1>
    static E1* create() {
        return new E1();
    }
};
class Assembly : public Detail {
protected:
    Assembly() { cout << "Assembly created" << endl; }
public:
    ~Assembly() override { cout << "Assembly removed" << endl; }
    void info() const override { cout << "It's an assembly" << endl; }
    friend class Detail;
};
class Part : public Detail {
protected:
    Part() { cout << "Part created" << endl; }
public:
    ~Part() override { cout << "Part removed" << endl; }
    void info() const override { cout << "It's a part" << endl; }
    friend class Detail;
};
template<typename E1>
void create_and_store(vector<Detail*>& storage) {
    storage.push_back(Detail::create<E1>());
}
int main() {
    vector<Detail*> storage;    
    create_and_store<Assembly>(storage);
    create_and_store<Part>(storage);
    for (const auto& component : storage) {
        component->info();
    }
    for (auto& component : storage) {
        delete component;
        component = nullptr; 
    }
    storage.clear(); 
}