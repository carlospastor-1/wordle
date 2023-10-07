#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>
#include "reading.h"

using namespace std;

int main(int argc, char* argv[]) {

    readstart();
    while(starter != "11") {
        readUpdatedColors();
        if (starter == "1") {
            system("clear");
            cout<<"please start wordle game"<<endl;
            while (starter == "1") {
                readstart();
            }
        }
        readUpdatedColors();
        if (starter == "10") {
            system("clear");
            cout<<"please start wordle program"<<endl;
            while (starter == "10") {
                readstart();
            }
        }
        readUpdatedColors();
        if (starter == "9") {
            system("clear");
            cout<<"please start wordle game"<<endl;
            while (starter == "9") {
                readstart();
            }
        }
        readUpdatedColors();
        if (starter == "2") {
            system("clear");
            firstprint();
            while (starter == "2") {
                readstart();
            }
        }
        readUpdatedColors();
        if (starter == "3") {
            system("clear");
            updateColors();
            while(starter == "3"){
                readstart();
            }
        }
        readUpdatedColors();
        if (starter == "4") {
            system("clear");
            updateColors();
            while(starter=="4") {
                readstart();
            }
        }
        readUpdatedColors();
        if (starter == "5") {
            system("clear");
            updateColors();
            while(starter=="5") {
                readstart();
            }
        }
        readUpdatedColors();
        if (starter == "6") {
            system("clear");
            updateColors();
            while(starter=="6") {
                readstart();
            }
        }
        readUpdatedColors();
        if (starter == "7") {
            system("clear");
            updateColors();
            while(starter=="7") {
                readstart();
            }
        }
        readUpdatedColors();
        if (starter == "8") {
            system("clear");
            updateColors();
            while (starter == "8") {
                readstart();
            }
        }
        readUpdatedColors();
        readstart();
    }
    overrideColors();
    system("clear");
    return 0;
}