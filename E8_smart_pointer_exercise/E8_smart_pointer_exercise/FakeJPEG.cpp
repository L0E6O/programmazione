#include <fstream>
#include "FakeJPEG.h"

FakeJPEG::FakeJPEG(int width, int height) : width(width), height(height) {
    bitmap.reserve(height);
}

const std::vector<std::string> &FakeJPEG::getBitmap() const {
    return bitmap;
}

void FakeJPEG::load(std::string fileName) throw(GameFileException, std::runtime_error) {
    std::ifstream in;
    // Set exceptions to be thrown on failure
    // @see http://en.cppreference.com/w/cpp/io/ios_base/iostate
    in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        in.open(fileName);
    } catch (std::ios_base::failure &e) {
        throw GameFileException("Can not open FakeJPEG file", fileName, false);
    }
    std::string fileLine;
    std::getline(in, fileLine);
    if (fileLine.compare("FakeJPEG") != 0)
        throw GameFileException("FakeJPEG file is in wrong format", fileName, false);
    std::getline(in, fileLine);
    width = std::stoi(fileLine);
    std::getline(in, fileLine);
    height = std::stoi(fileLine);
    int y = 0;
    bitmap.clear(); // clear old bitmap
    while (!in.eof() && std::getline(in, fileLine)) {
        bitmap.push_back(fileLine);
        y++;
    }
    if (y != height)
        throw std::runtime_error("Can not decompress correctly FakeJPEG file");
    in.close();
}
