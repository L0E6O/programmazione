// Exercise - Resource Management / RAII (10+2+2 points)
// You are building a simple file logger. The class FileLogger opens a file
// in its constructor and must guarantee the file is always closed when the
// logger goes out of scope, even if an exception is thrown.
//
// The function runWithLogger() (which cannot be modified) creates a FileLogger,
// writes some lines, and may throw an exception mid-way.
//
// Implement FileLogger using RAII so that the file is always properly closed (10 points).
// Make FileLogger non-copyable, but movable (2 points).
// Rewrite FileLogger using std::unique_ptr to manage the file handle
// instead of a raw pointer (2 points).

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <memory>

// TODO implement FileLogger with RAII:
//   - constructor opens the file
//   - destructor closes it
//   - void log(const std::string& message)
//   - non-copyable, movable
//   - (bonus) rewrite using std::unique_ptr<std::ofstream>

class FileLogger {
public:
    explicit FileLogger(const std::string& f) : file(std::make_unique<std::ofstream>(f)) {}

    FileLogger(FileLogger&&) = default;
    FileLogger& operator=(FileLogger&&) = default;
    FileLogger(const FileLogger& f) = delete;

    ~FileLogger() {
        file->close();
    }

    void log(const std::string& message) {
        *file << message << "\n";
    }

private:
    std::unique_ptr<std::ofstream> file;
};

// the function that uses the logger: DO NOT MODIFY
void runWithLogger(const std::string& filename, bool shouldThrow) {
    FileLogger logger(filename);
    logger.log("Starting session");
    logger.log("Doing some work...");
    if (shouldThrow)
        throw std::runtime_error("Something went wrong!");
    logger.log("Session ended cleanly");
}

int main() {
    // TODO test runWithLogger() both with and without exception
    // verify the file is correctly closed in both cases
    return 0;
}