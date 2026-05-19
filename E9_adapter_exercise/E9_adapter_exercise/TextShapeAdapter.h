//
// Created by jarro on 19/05/26.
//

#ifndef E9_ADAPTER_EXERCISE_TEXTSHAPEADAPTER_H
#define E9_ADAPTER_EXERCISE_TEXTSHAPEADAPTER_H

#include "Shape.h"
#include "Text.h"

class TextShapeAdapter : public Shape, public Text {
public:
    TextShapeAdapter(int ax = 0, int ay = 0, std::string t = "", int s = 8) : Shape(ax, ay), Text(t, s) {}

    void draw() override;
    void resize(float f) override;
};


#endif //E9_ADAPTER_EXERCISE_TEXTSHAPEADAPTER_H
