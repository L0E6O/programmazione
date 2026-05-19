//
// Created by jarro on 19/05/26.
//

#ifndef E9_ADAPTER_EXERCISE_OTEXTSHAPEADAPTER_H
#define E9_ADAPTER_EXERCISE_OTEXTSHAPEADAPTER_H

#include "Text.h"
#include "Shape.h"

class OTextShapeAdapter : public Shape {
public:
    OTextShapeAdapter(Text& text) : adaptee(text) {}
    void draw() override;
    void resize(float f) override;
private:
    Text& adaptee;
};


#endif //E9_ADAPTER_EXERCISE_OTEXTSHAPEADAPTER_H
