#include <algorithm>
#include <list>
#include <iostream>

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() {};

};

class Subject {
public:
    virtual void addObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notify() = 0;
    virtual ~Subject() {}
};

struct DiskFile {
    DiskFile(std::string n = "", float fs = 0. ) : name (n), fileSize(fs) {}

    bool operator==(const DiskFile &right) const {
        if ((name == right.name) && (fileSize == right.fileSize))
            return true;
        else
            return false;
    }

    std::string name;
    float fileSize; // size in MB
};

class Filesystem : public Subject{
public:
    Filesystem(float size) : freeSize(size), diskSize(size) {}

    void addObserver(Observer* o) override {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) override {
        observers.remove(o);
    }

    void notify() override {
        for (auto observer: observers) {
            observer->update();
        }
    }

    int getNumFiles() const {
        return files.size();
    }

    float getFreeSpace() const {
        return freeSize;
    }

    float getOccupiedSpace() const {
        return diskSize - freeSize;
    }

    void create(const DiskFile& newFile) {
        files.push_back(newFile);
        freeSize = diskSize - files.size();
        notify();
    }

    void remove(const DiskFile& oldFile) {
        files.remove(oldFile);
        freeSize = diskSize - files.size();
        notify();
    }
    bool rename(DiskFile oldFile, std::string newName) {
        std::list<DiskFile>::iterator it;
        it = std::find(files.begin(), files.end(), oldFile);
        if (it != files.end()) {
            it->name = newName;
            return true;
        }
        return false;
    };
    void printAll() {}; // TODO implement, must print all filenames

private:
    std::list <DiskFile> files;
    float diskSize; // disk size in MB
    float freeSize; // free space in MB
    std::list<Observer*> observers;
};

class FileSystemInfo : public Observer {

public:
    FileSystemInfo(Filesystem* subject) : subject(subject) {
        subject->addObserver(this);
    }

    virtual ~FileSystemInfo() {
        subject->removeObserver(this);
    }

    void update() override {
        std::cout << "Filesystem updated, num files: " << subject->getNumFiles() << std::endl;
    }

private:
    Filesystem* subject;
};

int main(int argc, char *argv[]) {
    DiskFile df1("foo.txt", 1);
    DiskFile df2("bar.log", 20);
    Filesystem fs(50);
    FileSystemInfo o(&fs);
    fs.create(df1);
    fs.create(df2);
    DiskFile df3("fizz.jpg", 20);
    fs.create(df3);
    fs.rename(df3, "buzz.jpg");
    DiskFile df4("fizz.jpg", 4);
    fs.create(df4);
    fs.remove(df4);
    fs.remove(df3);
    fs.create(df3);
    fs.create(df4);
    fs.printAll();
}