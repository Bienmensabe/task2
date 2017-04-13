#include "automata.h"

void Automata::on() {
    menu.resize(N_MAX_MENU_SIZE);
    STATE = WAIT;
    balance = 0;

    while (STATE != OFF) {
        int option;

        switch(STATE) {
        case WAIT:
            checkMenu();
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

            case 5:
                STATE = SETMENU;
                break;
            case 6:
                STATE = DELETEMENU;
                break;

            default:
               std::cout << "error case" << std::endl;
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

        case SETMENU:
            printState();
            setMenu();
            break;

        case DELETEMENU:
            printMenu();
            printState();
            int positionMenu;
            positionMenu = getInt();
            cancel(positionMenu);
            deleteMenu(positionMenu);
            break;

        default:
            std::cout << "error STATE" << std::endl;
        }
    }
}

void Automata::off() {
    std::cout << "Automata is OFF. Press any button to ON or press ESC to exit" << std::endl;
    int tmp;
    tmp = getInt();
    if (tmp != 27)
        on();
    else
        exit(0);
}

void Automata::coin(int money) {
    balance += money;
}

void Automata::printMenu() {
    std::cout << "Menu:\n";
    for (int i = 0; i < menuSize; i++)
        std::cout << (i+1) << ". " << menu[i].name<< "\t" << menu[i].price << " rub" << std::endl;
}

void Automata::checkMenu() {
    std::ifstream menuFILE ("/home/terpsichore/task2/AutomataDemo2/menu.txt");

    if(menuFILE.is_open()){
        char ch;
        std::string tmpName;
        std::string tmpPrice;
        int i = 0;

        while (menuFILE.get(ch)) {
           if(isdigit(ch)) {
               tmpPrice += ch;
           } else if (ch != '\n' && ch != '\0') {
               tmpName += ch;
           } else {
               menu[i].name = tmpName;
               menu[i].price = stoi(tmpPrice);

               tmpName = "";
               tmpPrice = "";
               i++;
           }
        }

        menuSize = i;
        menuFILE.close();
    } else {
        std::cout << "File not found" << std::endl;
        menuFILE.close();
    }
}

void Automata::setMenu() {

    std::ofstream menuFILE ("/home/terpsichore/task2/AutomataDemo2/menu.txt", std::ios_base::app);

    if(menuFILE.is_open()){
        std::string str1;

        std::getline(std::cin, str1);
        system("reset");

        if (str1 == "0")
            STATE = WAIT;
        else {
            menuFILE << str1;
            menuFILE << "\n";
            menuFILE.close();
        }

    } else {
        std::cout << "File not found" << std::endl;
        menuFILE.close();
    }
    STATE = WAIT;
}

void Automata::deleteMenu(int position) {

    if (position > menuSize || position < menuSize) {
        std::cout << "Error delete" << std::endl;
        STATE = WAIT;
    } else {
        position--;
        std::ifstream menuFILE ("/home/terpsichore/task2/AutomataDemo2/menu.txt");
        if(menuFILE.is_open()){
            std::string deleteline;
            std::string pricestring = std::to_string(menu[position].price);
            std::string line;

            deleteline = menu[position].name;
            deleteline += pricestring;
            //deleteline += "\n";

            while (std::getline(menuFILE, line)) {
                if (line == deleteline) {
                    line.replace(line.find(deleteline),deleteline.length(),"");
                }
            }
            menu.erase (menu.begin() + position);
            menuFILE.close();
            STATE = WAIT;
        } else {
            std::cout << "File not found" << std::endl;
            menuFILE.close();
        }
    }
}

void Automata::printState() {
    switch(STATE) {
    case WAIT:
        std::cout << "Options:\n"
            << "1 - Deposit money\n"
            << "2 - Choose drink\n"
            << "3 - Take odd money\n"
            << "4 - Turn off\n"
            << "5 - Set menu\n"
            << "6 - Delete menu\n\n"
            << "Current balance: " << balance << " rub" << std::endl;
        break;
    case ACCEPT:
        std::cout << "Plz, give me your money (0 - back to menu)\n" << std::endl;
        break;
    case CHECK:
        std::cout << "\nChoose your drink (0 - back to menu)\n" << std::endl;
        break;
    case SETMENU:
        std::cout << "Input your menu position(name price)\n0 - back to menu\n" << std::endl;
        break;
    case DELETEMENU:
        std::cout << "Choose menu position (0 - back to menu)\n" << std::endl;
        break;

    }
}

void Automata::choice(int option) {

    if ((option >= 1) & (option <= menuSize))
        check(option);
    else {
        std::cout << "Error check" << std::endl;
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

    std::getline(std::cin, str);
    std::cin.clear();
    system("reset");

    if (str[0] == 27){
        a = 27; //ESC
        return a;
    }
    if (std::all_of(str.begin(), str.end(), ::isdigit) == true) {
        a = std::stoi(str);
        return a;
    } else
        return 0;
}
