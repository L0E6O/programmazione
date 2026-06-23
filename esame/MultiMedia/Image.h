//
// Created by jarro on 23/06/26.
//

#ifndef MULTIMEDIA_IMAGE_H
#define MULTIMEDIA_IMAGE_H
#include "MediaFile.h"


class Image : public MediaFile{
public:
    Image(std::string n, const int m, const int r) : MediaFile(std::move(n), m), resolution(r) {}

    void describe() const override;

private:
    int resolution;
};


#endif //MULTIMEDIA_IMAGE_H
