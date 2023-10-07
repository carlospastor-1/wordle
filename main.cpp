#include <iostream>
#include "menu.h"
#include "game.h"
using namespace std;

int main(int argc, char* argv[]) {
    int size = 0;
    string allowed = "", targets = "", number;
    if (argc == 4) {
            size = atoi(argv[1]);
            targets = argv[2];
            allowed = argv[3];
            if (randomword(targets) == "") {
                system("clear");
                cout<<"ERROR! Please check targets file or file name"<<endl;
                return 0;
            }
            else if (filechecker(allowed) == "") {
                system("clear");
                cout<<"ERROR! Please check allowed words file or file name"<<endl;
                return 0;
            }
            else {
            displayMenu(size);
            sendStatus(1);
            }
    }
    else if (argc == 1) {
        size = 5;
        targets = "5-words.txt";
        allowed = "5-allowed.txt";
        displayMenu(size);
        sendStatus(1);
    }
    if (argc != 1 && argc !=4) {
        system("clear");
        cout<<"Please input './app' for 5 letter wordle or input correct values.\nEx. (5 5-words.txt 5-allowed.txt)"<<endl;
        return 0;
    }
    while (number != "5" && cin>> number) {
    system("clear");
        if (number == "1") {
            system("clear");
            clearColors(words);
            sendStatus(2);
            PlayWordle(size, targets, allowed);
        }
        if (number == "2") {
            How2PlayWordle(size);
        }
        if (number == "3") {
            stats2();
        }
        if (number == "4") {
            ResetStats();      
        }
        displayMenu(size);
    }
    sendStatus(10);
    system("clear");
    sendStatus(11);
    return 0;
}