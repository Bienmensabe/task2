#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include <iomanip>
#include <ctime>

class DateTime {

public:

    DateTime(int, int, int);
    DateTime(const DateTime&);
    DateTime();

    void printToday();
    void printYesterday();
    void printTomorrow();

    void printFuture(int);
    void printPast(int);

    void printMonth();
    void printWeekDay();

    int calcDifference(DateTime);

    void printSomeDay(int);
    time_t getRawtime() const;
    
private:

    struct tm * timeinfo;
    time_t rawtime;
    const int secsPerDay = 86400;

};

#endif // DATETIME_H
