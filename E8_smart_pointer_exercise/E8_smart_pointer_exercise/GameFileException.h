#ifndef GAMEFILEEXCEPTION_H
#define GAMEFILEEXCEPTION_H


#include <stdexcept>
#include <string>

class GameFileException : public std::runtime_error {
public:
    GameFileException(std::string whatMsg, std::string fileName, bool f=false);
    std::string getFilename() const { return fileName; };
    void printError() const;
    bool isFatal() { return fatal; }

private:
    std::string fileName;
    bool fatal;
};


#endif //GAMEFILEEXCEPTION_H
