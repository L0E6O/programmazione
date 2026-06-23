#include <memory>

#include "TextDocument.h"
#include "AutoSaver.h"
#include "ModifiedFlag.h"
#include "WordCountStatus.h"

int main() {

    TextDocument doc;

    auto wc = std::make_shared<WordCountStatus>(&doc);
    auto mf = std::make_shared<ModifiedFlag>(&doc);
    auto as = std::make_shared<Autosaver>(&doc);

    doc.addObserver(wc);
    doc.addObserver(mf);
    doc.addObserver(as);

    std::cout << "--- ADD WORDS ---" << std::endl;

    doc.addWord("Ciao");
    doc.addWord("sono");
    doc.addWord("Marco");

    std::cout << "--- INSERT WORD ---" << std::endl;

    doc.addWord("mi", 2);

    std::cout << "--- REMOVE WORD ---" << std::endl;

    doc.removeWord(2);

    std::cout << "--- GRAMMAR CHECK ---" << std::endl;

    if (doc.grammarCheck())
        std::cout << "Grammar OK" << std::endl;
    else
        std::cout << "Grammar NOT OK" << std::endl;

    return 0;
}
