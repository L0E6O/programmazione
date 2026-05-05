#ifndef GAMEFILEEXCEPTION_H
#define GAMEFILEEXCEPTION_H

#include <string>

// FIXME extend std::runtime_error
class GameFileException {
public:
    GameFileException(std::string whatMsg, std::string fileName, bool f=false);
    void printError() const;
    // FIXME add getters for attributes

private:
    // FIXME add useful attributes as fatal error and file name
};


#endif //GAMEFILEEXCEPTION_H
