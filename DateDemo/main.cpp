#include "datetime.h"

int main()
{
    DateTime randomDate1(26,03,2017);

    randomDate1.printToday();
    randomDate1.printTomorrow();
    randomDate1.printYesterday();

    std::cout << std::endl;

    DateTime copiedDate(randomDate1);

    copiedDate.printMonth();
    copiedDate.printWeekDay();

    std::cout << std::endl;

    DateTime randomDate2;

    randomDate2.printFuture(2);
    randomDate2.printPast(10);

    std::cout << std::endl;

    std::cout << randomDate2.calcDifference(randomDate1) << " days" << std::endl;

    return 0;
}
