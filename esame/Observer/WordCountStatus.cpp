//
// Created by jarro on 23/06/26.
//

#include "WordCountStatus.h"
#include "TextDocument.h"

void WordCountStatus::update() const {
    std::cout << "Words: " << subject->fileSize() << std::endl;
}
