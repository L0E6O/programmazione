#include <iostream>
#include <map>
#include "Date.h"
#include "Task.h"

int main() {
    Date d1(2018, Months::Apr, 23);
    Date d2(2018, Months::May, 7);
    Date d3(2018, Months::May, 11);
    Date d4(2018, Months::Jun, 10);
    Task t1 {"Lezione Template", true, d1};
    Task t2 {"Lezione Eccezioni", true, d2};
    Task t3 {"Esercitazione Eccezioni+STL", false, d3};
    Task t4 {"Lezione coding style guidelines", false, d3};

    // @see http://en.cppreference.com/w/cpp/container/multimap/multimap
    // default comparator: http://en.cppreference.com/w/cpp/utility/functional/less
    std::multimap<Date, Task, DateComparator> agendaM;

    agendaM.insert(std::make_pair(d1, t1));
    agendaM.insert(std::make_pair(d2, t2));
    agendaM.insert(std::make_pair(d3, t3));
    agendaM.insert(std::make_pair(d4, t4));


    // @see http://en.cppreference.com/w/cpp/container/multimap/find
    // XXX compare with http://en.cppreference.com/w/cpp/algorithm/find
    auto p = agendaM.find(d4);
    if (p==agendaM.end()) {
        std::cout << "nessuna attività il " << d4 << std::endl;
    }else {
        std::cout << "task: " << (*p).second.description << std::endl;
    }

    std::cout << "blocco 2" << std::endl;
    auto range = agendaM.equal_range(d2);
    for (auto i = range.first; i != range.second; ++i) {
        std::cout << i->first.getDay() << ": " << i->second.description << std::endl;
    }

    std::cout << "Tutte le attivita'" << std::endl;
    // TODO write a for cycle to print all activities, printing the date and description
    for (auto i = agendaM.begin(); i != agendaM.end(); ++i) {
        std::cout << i->first.getDay() << ": " << i->second.description << std::endl;
    }
    return 0;
}