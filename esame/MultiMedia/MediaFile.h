//
// Created by jarro on 23/06/26.
//

#ifndef MULTIMEDIA_MEDIAFILE_H
#define MULTIMEDIA_MEDIAFILE_H
#include <iostream>
#include <string>

class MediaFile {
public:
    MediaFile(std::string n, const double m) : name(std::move(n)), MB(m) {}

    virtual ~MediaFile() = default;

    virtual void describe() const = 0;

    int getMB() const {
        return MB;
    }

protected:
    std::string name;
    int MB;
};

#endif //MULTIMEDIA_MEDIAFILE_H
