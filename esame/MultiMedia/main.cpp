#include <iostream>
#include <memory>
#include <vector>

#include "MediaFile.h"
#include "Audio.h"
#include "Video.h"
#include "Image.h"

void visitAllMedia(const std::vector<std::shared_ptr<MediaFile>>& medias) {
    int tot = 0;
    for (const auto& media : medias) {
        media->describe();
        tot+=media->getMB();
    }
    std::cout << "Total MB: " << tot << std::endl;
}

int main() {
    auto audio = std::make_shared<Audio>("Canzone", 2, 140);
    auto video = std::make_shared<Video>("Filmato", 6, 10);
    auto img = std::make_shared<Image>("Immagine", 1, 4);

    std::vector<std::shared_ptr<MediaFile>> medias;

    medias.push_back(audio);
    medias.push_back(video);
    medias.push_back(img);

    visitAllMedia(medias);

    return 0;
}