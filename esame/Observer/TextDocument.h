//
// Created by jarro on 23/06/26.
//

#ifndef OBSERVER_TEXTDOCUMENT_H
#define OBSERVER_TEXTDOCUMENT_H
#include <memory>
#include <vector>

#include "Observer.h"


class TextDocument {
public:

    int fileSize() const {
        return file.size();
    }

    void addObserver(const std::shared_ptr<Observer>& obs);

    void removeObserver(const int pos);

    void notify() const;

    void addWord(const std::string& s);

    void addWord(const std::string& s, const int pos);

    void removeWord(int pos);

    bool grammarCheck() const;

private:

    std::vector<std::shared_ptr<Observer>> observers;
    std::vector<std::string> file;
};

#endif //OBSERVER_TEXTDOCUMENT_H
