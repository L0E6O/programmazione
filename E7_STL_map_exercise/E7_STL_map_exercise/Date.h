#ifndef DATE_H
#define DATE_H

#include <ostream>

enum class Months {
    Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

class Date {
public:
    explicit Date(int y = 2018, Months m = Months::Jan, int d = 1);

    Months getMonth() const;

    void setMonth(Months month);

    int getDay() const;

    void setDay(int day);

    int getYear() const;

    void setYear(int year);

    friend std::ostream &operator<<(std::ostream &stream, const Date &date);

private:
    int day, year;
    Months month;

    int getMaxDays();

    std::string getMonthString() const;
};

class DateComparator {
public:
    bool operator()(const Date &lhs, const Date &rhs) const {
        if (lhs.getYear() < rhs.getYear())
            return true;
        else if (lhs.getYear() > rhs.getYear()) {
            return false;
        }
        else {
            if (lhs.getMonth() < rhs.getMonth())
                return true;
            else if (lhs.getMonth() > rhs.getMonth()) {
                return false;
            } else {
                if (lhs.getDay() < rhs.getDay())
                    return true;
                else
                    return false;
            }
        }
    }
};

#endif //DATE_H
