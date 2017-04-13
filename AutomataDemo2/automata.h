#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <vector>

#define N_MAX_MENU_SIZE 20

class Automata {
public:

    void on();
    void off();

private:

    enum STATE {OFF, WAIT, ACCEPT, CHECK, SETMENU, DELETEMENU};
    int STATE = OFF;

    struct coffeeList {
        std::string name;
        int price;
    };
    std::vector <coffeeList> menu;

    int menuSize;

    int balance;

    void coin(int);

    void printState();
    void checkMenu();
    void setMenu();
    void deleteMenu(int);
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
