//
// Created by jarro on 23/06/26.
//

#ifndef MULTIMEDIA_AUDIO_H
#define MULTIMEDIA_AUDIO_H
#include "MediaFile.h"


class Audio :public MediaFile{
public:

    Audio(std::string n, const int m, const int b) : MediaFile(std::move(n), m), bitrate(b) {}

    void describe() const override;

private:
    int bitrate;
};


#endif //MULTIMEDIA_AUDIO_H
