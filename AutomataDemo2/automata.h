#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <cstring>
#include <algorithm>

#define N_MAX_NAME_SIZE 40
#define N_MAX_MENU_SIZE 20


class Automata {
public:

    void on();
    void off();

private:

    enum STATE {OFF, WAIT, ACCEPT, CHECK, COOK};
    int STATE = OFF;

    FILE *menuFile;
    struct coffeeList {
        char name[N_MAX_NAME_SIZE];
        int price;
    };
    struct coffeeList menu[N_MAX_MENU_SIZE];

    int menuSize;

    int balance;

    void coin(int);

    void printState();
    void checkMenu();
    void printMenu();
    void choice(int);
    void check(int);
    void cancel(int);
    void cook(int);
    void finish();
    void returnOdd();
    int getInt();

};

#endif // AUTOMATA_H
