#include "Date.h"

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    int maxDay = getMaxDays();
    if (day <= 0 || day>maxDay)
        return;
    Date::day = day;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

Months Date::getMonth() const {
    return month;
}

void Date::setMonth(Months month) {
    Date::month = month;
    int maxDay = getMaxDays();
    if (day>maxDay)
        day = maxDay;
}

int Date::getMaxDays() {
    switch(month) {
        case Months::Sep:
        case Months::Apr:
        case Months::Jun:
        case Months::Nov:
            return 30;
        case Months::Feb:
            return ((getYear()%4==0 && getYear()%100!=0) || (getYear()%400==0)) ? 29 : 28;
        default:
            return 31;
    }
}

Date::Date(int y, Months m, int d) : day(d), month(m), year(y) {
    if (day > getMaxDays())
        day = 1;
}

std::ostream &operator<<(std::ostream &stream, const Date &date) {
    stream << date.day << "/" << date.getMonthString() << "/" << date.year;
    return stream;
}

std::string Date::getMonthString() const {
    switch (month) {
        case Months::Jan:
            return "Jan";
        case Months::Feb:
            return "Feb";
        case Months::Mar:
            return "Mar";
        case Months::Apr:
            return "Apr";
        case Months::May:
            return "May";
        case Months::Jun:
            return "Jun";
        case Months::Jul:
            return "Jul";
        case Months::Aug:
            return "Aug";
        case Months::Sep:
            return "Sep";
        case Months::Oct:
            return "Oct";
        case Months::Nov:
            return "Nov";
        case Months::Dec:
            return "Dec";
    }
}

