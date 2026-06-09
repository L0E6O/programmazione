#include <iostream>
#include <vector>

class MyFile {
public:
    explicit MyFile(std::string n) : name(n) {}
    std::string name;
    virtual void open() {}
};

class Directory : public MyFile {
public:
    explicit Directory(std::string name) : MyFile(name) {}
    std::vector<MyFile*> entries;
    void list() const{
        std::cout << "Directory list:" << std::endl;
        for(auto entry : entries)
            std::cout << entry->name << std::endl;
    }
};

int main(int argc, char *argv[]) {
    MyFile* pf = new Directory("/var/log");
    std::cout << pf->name << std::endl;

    const auto dir = dynamic_cast<Directory*>(pf);
    if (dir != nullptr)
        dir->list();
    else
        std::cout << "Error" << std::endl;

    delete pf;
}