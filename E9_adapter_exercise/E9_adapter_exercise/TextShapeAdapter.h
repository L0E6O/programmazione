//
// Created by jarro on 19/05/26.
//

#ifndef E9_ADAPTER_EXERCISE_TEXTSHAPEADAPTER_H
#define E9_ADAPTER_EXERCISE_TEXTSHAPEADAPTER_H

#include "Shape.h"
#include "Text.h"

class TextShapeAdapter : public Shape, public Text {
public:
    TextShapeAdapter(const Text& adaptee) : Text(adaptee.getText(), adaptee.getFontSize()) {}
    TextShapeAdapter(int x, int y, const Text& adaptee) : Text(adaptee.getText(), adaptee.getFontSize()) {}

    void draw() override;
    void resize(float f) override;
};


#endif //E9_ADAPTER_EXERCISE_TEXTSHAPEADAPTER_H
