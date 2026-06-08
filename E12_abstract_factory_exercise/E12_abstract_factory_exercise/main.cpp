#include <iostream>
#include "Window.h"
#include "Button.h"
#include "iOSFactory.h"

#include "WidgetFactory.h"
#include "WindowsFactory.h"

// TODO try compiling commenting the next define...
#define _iOS

int main() {
    std::unique_ptr<WidgetFactory> guiFactory;

#ifdef _WIN64
    guiFactory = std::make_unique<WindowsFactory>();
#else
    guiFactory = std::make_unique<iOSFactory>();
#endif

    auto clickButton = guiFactory->createButton("click");
    auto gameWindow = guiFactory->createWindow("Game name");


    // TODO draw button and window
    clickButton->draw();
    gameWindow->draw();
    // TODO resize window and set icon on button
    gameWindow->resize();
    clickButton->setIcon();

    return 0;
}
