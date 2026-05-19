#ifndef TEXT_H
#define TEXT_H

#include <string>

class Text {
public:
    explicit Text(std::string t="", int s=8) :
            text(t), fontSize(s) {}
    virtual ~Text() {}

    virtual void print();
    virtual void resize(int newSize);

    const std::string &getText() const {
        return text;
    }

    void setText(const std::string &text) {
        Text::text = text;
    }

    int getFontSize() const {
        return fontSize;
    }

    void setFontSize(int fontSize) {
        Text::fontSize = fontSize;
    }

protected:
    std::string text;
    int fontSize;
};


#endif //TEXT_H
