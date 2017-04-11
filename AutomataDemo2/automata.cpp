#include "automata.h"

void Automata::on() {
    STATE = WAIT;
    checkMenu();
    balance = 0;

    while (STATE != OFF) {
        int option;

        switch(STATE) {
        case WAIT:

            printState();
            option = getInt();

            switch (option) {
            case 1:
               STATE = ACCEPT;
               break;

            case 2:
               STATE = CHECK;
               break;

            case 3:
               returnOdd();
               break;

            case 4:
               off();
               break;

            default:
               std::cout << "eror" << std::endl;
               STATE = WAIT;
            }
            break;

        case ACCEPT:
            printState();
            int money;
            money = getInt();
            cancel(money);
            coin(money);
            STATE = WAIT;
            break;

        case CHECK:

            printMenu();
            printState();
            int check;
            check = getInt();
            cancel(check);
            choice(check);
            break;

        default:
            ;
        }
    }
}

void Automata::off() {
    std::cout << "Automata is OFF. Press any button to ON or press ESC to exit" << std::endl;
    int tmp;
    tmp = getInt();
    if (tmp != 27)
        on();
}

void Automata::coin(int money) {
    balance += money;
}

void Automata::printMenu() {
    std::cout << "Menu:\n";
    for (int i = 0; i < menuSize; i++)
        std::cout << (i+1) << ". " << menu[i].name<< " " << menu[i].price << " rub" << std::endl;
}

void Automata::checkMenu() {
    menuFile = fopen("/home/terpsichore/task2/AutomataDemo2/menu.txt", "r");

    if (menuFile == NULL) {
         std::cout << "eror\n" << std::endl;
     }

    int i = 0;
    while (fscanf (menuFile, "%s%i", menu[i].name, &(menu[i].price)) != EOF)
        i++;
    menuSize = i;
}

void Automata::printState() {
    switch(STATE) {
    case WAIT:
        std::cout << "Options:\n"
            << "1 - Deposit money\n"
            << "2 - Choose drink\n"
            << "3 - Take odd money\n"
            << "4 - Turn off\n\n"
            << "Current balance: " << balance << " rub" << std::endl;
        break;
    case ACCEPT:
        std::cout << "Plz, give me your money (0 - back to menu)\n" << std::endl;
        break;
    case CHECK:
        std::cout << "\nChoose your drink (0 - back to menu)\n" << std::endl;
    }
}

void Automata::choice(int option) {

    if ((option >= 1) & (option <= menuSize))
        check(option);
    else {
        std::cout << "Eror check" << std::endl;
        STATE = WAIT;
    }
}

void Automata::check(int option) {
    if (balance >= menu[option - 1].price)
        cook(option);
    else {
        std::cout << "You don`t have enough money to buy " << menu[option - 1].name << std::endl;
        STATE = WAIT;
    }

}

void Automata::cancel(int zero) {
    if (zero == 0)
        STATE = WAIT;
}

void Automata::cook(int option) {
    balance -= menu[option - 1].price;
    std::cout << "Making your drink '" << menu[option - 1].name << "'..." << std::endl;
    finish();

}

void Automata::finish() {
    std::cout << "Your drink is ready. Have a nice day!" << std::endl;
    std::cin.get();
    STATE = WAIT;
}

void Automata::returnOdd() {
    std::cout << "Returning " << balance << " rub\n" << std::endl;
    balance = 0;
}

int Automata::getInt() {
    std::string str;
    int a;
    std::cin >> str;
    std::cin.clear();
    system("reset");
    if (str[0] == 27){
        a = 27;
        return a;
    }
    if (std::all_of(str.begin(), str.end(), ::isdigit) == true) {
        a = std::stoi(str);
        return a;
    } else
        return 0;
}

