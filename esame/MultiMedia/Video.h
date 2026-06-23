//
// Created by jarro on 23/06/26.
//

#ifndef MULTIMEDIA_VIDEO_H
#define MULTIMEDIA_VIDEO_H
#include "MediaFile.h"


class Video : public MediaFile{
public:

    Video(std::string n, const int m, const int l) : MediaFile(std::move(n), m), Lenght(l) {}

    void describe() const override;

private:
    int Lenght;
};


#endif //MULTIMEDIA_VIDEO_H
