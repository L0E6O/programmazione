//
// Created by jarro on 23/06/26.
//

#include "TextDocument.h"

void TextDocument::addObserver(const std::shared_ptr<Observer> &ob) {
    observers.push_back(ob);
}

void TextDocument::removeObserver(const int pos) {

    if (pos >= observers.size() || pos < 0)
        throw std::out_of_range("Bad index");

    observers.erase(observers.begin() + pos);
}

void TextDocument::notify() const {
    for (const auto& ob : observers) {
        ob->update();
    }
}

void TextDocument::addWord(const std::string &s) {
    file.push_back(s);
    notify();
}

void TextDocument::addWord(const std::string &s, const int pos) {

    if (pos == file.size()) {
        addWord(s);
        notify();
    }
    else if (pos < file.size() && pos >= 0) {
        file.insert(file.begin() + pos, s);
        notify();
    }
    else
        throw std::out_of_range("Bad index");
}

void TextDocument::removeWord(int pos) {
    if (pos >= file.size() || pos < 0)
        throw std::out_of_range("Bad index");

    file.erase(file.begin() + pos);
    notify();
}

bool TextDocument::grammarCheck() const {
    return file.size() % 2 == 0;
}
