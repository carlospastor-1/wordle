#include <cctype>
#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define GREY "\033[90m"
std::string num;
int sized;
void ResetStats() {
    system("clear");
    std::string dummy;
    std::ofstream film;
    film.open("currentstreak.txt", std::ofstream::out | std::ofstream::trunc);
    film.close();
    std::ofstream filed;
    filed.open("timesplayed.txt", std::ofstream::out | std::ofstream::trunc);
    filed.close();
    filed.open("topstreak.txt", std::ofstream::out | std::ofstream::trunc);
    filed.close();
    filed.open("wins.txt", std::ofstream::out | std::ofstream::trunc);
    filed.close();
    filed.open("attempts.txt", std::ofstream::out | std::ofstream::trunc);
    filed.close();
    filed.open("wordstats.txt", std::ofstream::out | std::ofstream::trunc);
    filed.close();
    filed.open("statssummary.txt", std::ofstream::out | std::ofstream::trunc);
    filed.close();
    filed.open("words.txt", std::ofstream::out | std::ofstream::trunc);
    filed.close();
    filed.open("win_stats.txt", std::ofstream::out | std::ofstream::trunc);
    filed.close();
    filed.open("attempcount_stats.txt", std::ofstream::out | std::ofstream::trunc);
    filed.close();
    std::ofstream r;
    r.open("wins.txt", std::ios::app);
    if (r.is_open()) {
        r<<"0";
        r.close();
    }
    r.open("currentstreak.txt", std::ios::app);
    if (r.is_open()) {
        r<<"0";
        r.close();
    }
    r.open("topstreak.txt", std::ios::app);
    if (r.is_open()) {
        r<<"0";
        r.close();
    }
    r.open("attempts.txt", std::ios::app);
    if (r.is_open()) {
        r<<"0";
        r.close();
    }
    r.open("timesplayed.txt", std::ios::app);
    if (r.is_open()) {
        r<<"0";
        r.close();
    } 
    int times = 0;
    int averagecounter = 0;
    int winpercentage = 0;
    int streak = 0;
    int topstreak = 0;
    std::ofstream files;
    files.open("statssummary.txt", std::ios::app);
    if (files.is_open()) {
        files<<"Times Played:"<<std::setw(13)<<times<<"\n";
        files<<"Average Attempts"<<std::setw(10)<<averagecounter<<"\n";
        files<<"Win Percentage: "<<std::setw(9)<<std::setprecision(3)<<winpercentage<<"%"<<std::endl;
        files<<"Current Streak: "<<std::setw(10)<<streak<<std::endl;
        files<<"Longest Streak: "<<std::setw(10)<<topstreak<<std::endl;
        files.close();
    }
    std::cout<<"=========================="<<std::endl;
    std::cout<<"    STATISTICS SUMMARY    "<<std::endl;
    std::cout<<"=========================="<<std::endl;
    std::cout<<"Times Played:"<<std::setw(13)<<std::right<<times<<std::endl;
    std::cout<<"Average Attempts:"<<std::setw(9)<<std::right<<averagecounter<<std::endl;
    std::cout<<"Win Percentage:"<<std::setw(10)<<std::right<<winpercentage<<"%"<<std::endl;
    std::cout<<"Current Streak:"<<std::setw(11)<<std::right<<"0"<<std::endl;
    std::cout<<"Longest Streak"<<std::setw(12)<<std::right<<topstreak<<std::endl<<std::endl<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"WORD      ATTEMPTS     WIN"<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<"Press [enter] to continue"<<std::endl;
    std::cin.ignore();
    getline(std::cin,dummy);
}
void sendStatus(int number) {
    if (number == 1) {
        std::string path = "status.txt";
        std::ofstream file;
        file.open(path, std::ios::out);
        if (file.is_open()) {
            file<<"1"<<std::endl;;
            file.close();
        }
    }
    else if (number == 2) {
        std::string path = "status.txt";
        std::ofstream file;
        file.open(path, std::ios::out);
        if (file.is_open()) {
            file<<"2"<<std::endl;;
            file.close();
        }
    }
    else if (number == 9) {
        std::string path = "status.txt";
        std::ofstream file;
        file.open(path, std::ios::out);
        if (file.is_open()) {
            file<<"9"<<std::endl;;
            file.close();
        }
    }
    else if (number == 10) {
        std::string path = "status.txt";
        std::ofstream file;
        file.open(path, std::ios::out);
        if (file.is_open()) {
            file<<"10"<<std::endl;;
            file.close();
        }
    }
    else if (number == 11) {
        std::string path = "status.txt";
        std::ofstream file;
        file.open(path, std::ios::out);
        if (file.is_open()) {
            file<<"11"<<std::endl;
            file.close();
        }
    }
    
}
void displayMenu(int size) {
    system("clear");
    std::cout<<"========================="<<std::endl;
    std::cout<<"    WELCOME TO WORDLE    "<<std::endl;
    std::cout<<"========================="<<std::endl<<std::endl<<std::endl;
    std::cout<<"MODE: "<<size<<" LETTERED WORDLE"<<std::endl<<std::endl;
    std::cout<<"1. Play Wordle\n2. How to Play\n3. Statistics Summary\n4. Reset Statistics\n5. Exit\n\nSelect an option:"<<std::endl;
}
void How2PlayWordle(int size) {
    system("clear");
    std::string dummy;
    std::cout<<"============================================="<<std::endl;
    std::cout<<"              HOW TO PLAY                    "<<std::endl;
    std::cout<<"============================================="<<std::endl;
    std::cout<<"Guess the Wordle in 6 tries.\n\n\n";
    std::cout<<"HOW TO PLAY:\n- Each guess must be a valid "<<size<<" letter word.\n- The color of the tiles will change to show \n  you how close your guess was to the word.\n- If needed, input 'quiter' to exit the game.\n  The game will be considered a loss."<<std::endl<<std::endl<<std::endl;
    std::cout<<GREEN<<" ---  "<<RESET<<"---  ---  ---  ---"<<std::endl;
    std::cout<<GREEN<<"| W |"<<RESET<<"| E || A || R || Y |"<<std::endl;
    std::cout<<GREEN<<" ---  "<<RESET<<"---  ---  ---  ---"<<std::endl;
    std::cout<<"W is in the word and in the correct spot."<<std::endl<<std::endl<<std::endl;
    std::cout<<" --- "<<YELLOW<<" --- "<<RESET<<" ---  ---  ---"<<std::endl;
    std::cout<<"| P |"<<YELLOW<<"| I |"<<RESET<<"| L || L || S |"<<std::endl;
    std::cout<<" --- "<<YELLOW<<" --- "<<RESET<<" ---  ---  ---"<<std::endl;
    std::cout<<"I is in the word but in the wrong spot."<<std::endl<<std::endl<<std::endl;
    std::cout<<" ---  ---  ---  "<<GREY<<"---"<<RESET<<"  ---"<<std::endl;
    std::cout<<"| V || A || G |"<<GREY<<"| U |"<<RESET<<"| E |"<<std::endl;
    std::cout<<" ---  ---  --- "<<GREY" --- "<<RESET" --- "<<std::endl;
    std::cout<<"U is not in the word in any spot."<<std::endl<<std::endl<<std::endl;
    std::cout<<"Press [enter] to continue"<<std::endl;
    std::cin.ignore();
    getline(std::cin,dummy);
}
void stats2() {
    float winner, winpercentage;
    std::string statslines, lines, bigger, blocks;
    system("clear");
    if (winner == 0) {
        winpercentage = 0;
    }
    std::string dummy;
    std::ifstream files;
    files.open("statssummary.txt", std::ios::in) ;
    if (files.is_open()) {
        std::string lins;
        while (getline(files, lins)) {
            statslines += lins+"\n";
        }
        files.close();
    }    
    std::cout<<"=========================="<<std::endl;
    std::cout<<"    STATISTICS SUMMARY    "<<std::endl;
    std::cout<<"=========================="<<std::endl;
    std::cout<<statslines<<std::endl;
    std::ifstream file;
    file.open("wordstats.txt", std::ios::in);
    if (file.is_open()) {
        std::string line;
        while (getline(file,line)) {
        lines += line+ "\n";
        }
        file.close();
    }
    
    file.open("temporary.txt", std::ios::in);
    if (file.is_open()) {
        std::string rows;
        while(getline(file, rows)) {
            blocks+=rows+'\n';
        }
        file.close();
    }
    std::cout<<"------------------------------------\n";
    std::cout<<"WORD     ATTEMPTS      WIN    LENGTH\n";
    std::cout<<"------------------------------------\n";
    // std::cout<<bigger<<std::endl;
    std::cout<<lines<<std::endl;
    std::cout<<"Press [enter] to continue"<<std::endl;
    std::cin.ignore();
    getline(std::cin,dummy);
    statslines = "";
    lines = "";
}