#include <fstream>
#include <iostream>
#include <memory>

#include "splash_screen.h"

std::unique_ptr<FakeJPEG> loadBitmap(std::string fileName) {
    std::unique_ptr<FakeJPEG> result(new FakeJPEG());
    result->load(fileName);
    return result;
}

void displaySplash() {
    // ... start graphics

    try {
        const std::unique_ptr<FakeJPEG> splashScreen = loadBitmap(SPLASH_SCREEN_FILENAME); // XXX should work
    //const FakeJPEG* splashScreen = loadBitmap("non_existent_file.fake_jpg"); // XXX test GameFileException
    // const FakeJPEG* splashScreen = loadBitmap("./res/splash_screen_corrupted.fake_jpg"); // XXX test std::runtime_error
    // ... display bitmap
        auto bitmap = splashScreen->getBitmap();
        for (auto bitmapLine : bitmap)
            std::cout << bitmapLine << std::endl;
    } catch (GameFileException &e) {
        std::cerr << e.what() << std::endl;
        e.printError();
        if(e.isFatal())
            abort();
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }

    // ... stop display
}
