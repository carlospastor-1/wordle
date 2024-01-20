#include <cctype>
#include <cstdlib>
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
#include "stats.h"
std::string target, wordle, currentguess, win, filecheck, longwords;
char guessdupe = '*', targetdupe = '*', second_dupe, third_dupe, targetdupe2, targetdupe3, targetdupe4, targetdupe5;
int targetdupecounter, guessdupecounter, target2dupecounter, target3dupecounter, target4dupecounter, target5dupecounter;
float attempts, timesplayed;
int average, wincount, streak, topstreak, status;
float winpercentage, averagecounter;
char fourth_dupe, fifth_dupe;
std::string words = "Q4W4E4R4T4Y4U4I4O4P4A4S4D4F4G4H4J4K4L4Z4X4C4V4B4N4M4";
std::string uppercase(std::string&a) {
    for (int i =0; i < a.length();i++) {
        a[i] = toupper(a[i]);
    }
    return a;
}
std::string randomword(std::string targetlist) {
    std::string error = "NOT FOUND";
    std::string line;
    std::vector<std::string> lines;
    srand(time(0));
    std::ifstream file;
    int total = 0;
    file.open(targetlist);
    if (file){
    while (getline(file,line)) {
        total++;
        lines.push_back(line);
    }
    int randomnum = rand() % total;
    target = lines[randomnum];
    target = uppercase(target);
    }
    return target;
}
std::string filechecker(std::string allowedlist) {
    std::string error = "NOT FOUND";
    std::string line;
    std::vector<std::string> lines;
    srand(time(0));
    std::ifstream file;
    int total = 0;
    file.open(allowedlist);
    if (file){
    while (getline(file,line)) {
        total++;
        lines.push_back(line);
    }
    return lines[0];
    }
    return filecheck;
}
bool checkWord(std::string guess, std::string lists) {
        std::ifstream file;
        file.open(lists, std::ios::in);
        if (file.is_open()) {
            std::string lined;
            while(getline(file, lined)) {
                size_t pos = lined.find(guess);
                if (pos != std::string::npos) {
                    return true;
                }
            }
        }
    return false;
}
bool inList(std::string worda, std::string listed) {
        std::ifstream file;
        file.open(listed, std::ios::in);
        if (file.is_open()) {
            std::string lined;
            while(getline(file, lined)) {
                size_t pos = lined.find(worda);
                if (pos != std::string::npos) {
                    return true;
                }
            }
        }
    return false;
}
std::string PrintWordle(std::vector<int> test, int size, std::string guess) {
    for (int i = 0; i < test.size();i++) {
        if (test[i] == 1) {
            wordle+=GREEN;
            wordle+=" --- ";
            wordle+=RESET;
        }
        else if (test[i] == 2) {
            wordle+=YELLOW;
            wordle+=" --- ";
            wordle+=RESET;
        }
        else if (test[i] == 3) {
            wordle+=GREY;
            wordle+=" --- ";
            wordle+=RESET;
        }
    }
    wordle+="\n";
    for (int i = 0; i < test.size();i++) {
        if (test[i] == 1) {
            wordle+=GREEN;
            wordle+="| ";
            wordle+=guess[i];
            wordle+=" |";
            wordle+=RESET;
        }
        else if (test[i] == 2) {
            wordle+=YELLOW;
            wordle+="| ";
            wordle+=guess[i];
            wordle+=" |";
            wordle+=RESET;
        }
        else if (test[i] == 3) {
            wordle+=GREY;
            wordle+="| ";
            wordle+=guess[i];
            wordle+=" |";
            wordle+=RESET;
        }
    }
    wordle+="\n";
    for (int i = 0; i < test.size();i++) {
        if (test[i] == 1) {
            wordle+=GREEN;
            wordle+=" --- ";
            wordle+=RESET;
        }
        else if (test[i] == 2) {
            wordle+=YELLOW;
            wordle+=" --- ";
            wordle+=RESET;
        }
        else if (test[i] == 3) {
            wordle+=GREY;
            wordle+=" --- ";
            wordle+=RESET;
        }
    }
    wordle+="\n";
    return wordle;
}
void sendGameStatus(int number) {
    if (number == 3) {
        // std::string path = "status.txt";
        std::ofstream file;
        file.open("status.txt", std::ios::out);
        if (file.is_open()) {
            file<<"3";
            file.close();
        }
    }
    else if (number == 4) {
        // std::string path = "status.txt";
        std::ofstream file;
        file.open("status.txt", std::ios::out);
        if (file.is_open()) {
            file<<"4";
            file.close();
        }
    }
    else if (number == 5) {
        // std::string path = "status.txt";
        std::ofstream file;
        file.open("status.txt", std::ios::out);
        if (file.is_open()) {
            file<<"5";
            file.close();
        }
    }
    else if (number == 6) {
        // std::string path = "status.txt";
        std::ofstream file;
        file.open("status.txt", std::ios::out);
        if (file.is_open()) {
            file<<"6";
            file.close();
        }
    }
    else if (number == 7) {
        // std::string path = "status.txt";
        std::ofstream file;
        file.open("status.txt", std::ios::out);
        if (file.is_open()) {
            file<<"7";
            file.close();
        }
    }
    else if (number == 8) {
        // std::string path = "status.txt";
        std::ofstream file;
        file.open("status.txt", std::ios::out);
        if (file.is_open()) {
            file<<"8";
            file.close();
        }
    }
    else if (number == 9) {
        // std::string path = "status.txt";
        std::ofstream file;
        file.open("status.txt", std::ios::out);
        if (file.is_open()) {
            file<<"9";
            file.close();
        }
    }
}
void redirect(char l, char m) {//add number so it wont accidentally overwrite a second letter
    for (int i = 0; i < words.length();i++) {
        if (l == words[i]) {
            if (words[i+1] == '4') {
                words[i] = l;
                words[i+1] = m;
                break;
            }
            else if (words[i+1] == '2') {
                words[i] = l;
                words[i+1] = m;
                break;
            }
            else if (words[i+1] == '1') {
                words[i] = words[i];
                words[i+1] = words[i+1];
            }
        }
    }
    // words = words;//add numbers to file, and then read using keyboard length since theyre same length
    std::string path = "colors.txt";
    std::ofstream file;
    file.open(path, std::ios::out);
    if (file.is_open()) {
        file<<words;//make sure its either 4 or 2 to change it, if it is 1 it should ignore it and not change it
    }
}
void clearColors(std::string word) {
    std::string path = "colors.txt";
    std::ofstream file;
    file.open(path, std::ios::out);
    if (file.is_open()) {
        file<<word;
    }
    file.close();
}
void PlayWordle(int size, std::string targets, std::string allowed) {
    
    int currentguessnum = 0, maxguess = 6, j = 0;
    wordle.clear();
    system("clear");
    std::cout<<"Input '6' to quit the game"<<std::endl;
    words = "Q4W4E4R4T4Y4U4I4O4P4A4S4D4F4G4H4J4K4L4Z4X4C4V4B4N4M4";
    clearColors(words);
    if (size == 0) {
        size = 5;
    }
    randomword(targets);
    uppercase(target);
    status = 2;
    std::string temptarget = target;
    while (currentguessnum < maxguess) {
        retract_stats();
        attempts = all_stats[0];
        streak = all_stats[1];
        timesplayed = all_stats[2];
        topstreak = all_stats[3];
        averagecounter = all_stats[4];
        target = temptarget;
        std::cout<<target<<std::endl;
        currentguess = "";
    std::cin>>currentguess;
     if (currentguess == "6") {
        std::string dummy;
        std::cout<<std::endl<<"You have quit the game! This was considered as a loss."<<std::endl<<std::endl;
        std::cout<<"The word was "<<target<<std::endl<<std::endl;
        std::cout<<"Please press [enter] to continue"<<std::endl;
        win = "Quit";
        if (wincount == 0) {
            wincount = 0;
        }
        timesplayed++;
        if (streak>topstreak) {
            topstreak = streak;
       }
        if (size >8) {
            for (int i =0;i<8;i++) {
                longwords+=target[i];
            }
            longwords+="...";
        }
        attempts++;
        streak = 0;
        ClearStats();  
        savewords(target);  
        savewin_stats(win);   
        longestword();
        averagecounter = attempts/timesplayed;
        if (wincount == 0) {
            winpercentage = 0;
        }
        else {
        winpercentage = (wincount/timesplayed)*100;
        }
        SaveWordStats(target, currentguessnum, win, size, longestlengthword, timesplayed);
        resizestats(longestlengthword);
        SaveStatsSummary(timesplayed, averagecounter, winpercentage, streak, topstreak);
        getline(std::cin, dummy);
        sendGameStatus(9);
        save_stats(attempts,streak,timesplayed,topstreak,winpercentage,averagecounter);
        currentguessnum = 6;
        getline(std::cin, dummy);
        continue;
     }

    if (currentguess.length() == 0 || currentguess.length() > size) {
        system("clear");
            std::cout<<"Input '6' to quit the game"<<std::endl;
            std::cout<<currentguessnum<<"/"<<maxguess<<std::endl;
            std::cout<<wordle<<std::endl;
            std::cout<<"Enter guess: ";
            std::cin>>currentguess;
        }

    if (checkWord(currentguess, allowed) || inList(currentguess, targets)) {
        auto start = std::chrono::high_resolution_clock::now();
        uppercase(currentguess);
        uppercase(target);
        std::vector<int> temp(size);
        std::string tempguess = currentguess;
        target = temptarget;
        for (int i = 0; i < target.length();i++) {
                if (currentguess[i] == target[i]) {
                    redirect(currentguess[i], '1');
                    temp[i] = 1;
                    target[i] = '-';
                }
        }
        for (int i = 0; i < target.length();i++) {
            if (target.find(currentguess[i])<=target.length() ) {
                if (temp[i] != 1) {
                    redirect(currentguess[i], '2');
                temp[i] = 2;
                }
            }
            else if (target.find(currentguess[i])<=target.length() == false){
                if (temp[i] != 1) {
                    redirect(currentguess[i], '3');
                    temp[i] = 3;
                }
            }
        }  
        status++;
        attempts++;
        currentguessnum++;
        guessdupecounter = 0;
        sendGameStatus(status);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        system("clear");
        std::cout<<"Executed in "<< duration << "ms"<<std::endl;
        std::cout<<"Input '6' to quit the game"<<std::endl;
        std::cout<<currentguessnum<<"/"<<maxguess<<std::endl;
        std::cout<<PrintWordle(temp, size,tempguess);
        if (tempguess == temptarget) {
                system("clear");
                std::string dummy;
                std::cout<<"Executed in "<< duration << "ms"<<std::endl;
                std::cout<<wordle<<std::endl<<"Splendid!"<<std::endl<<std::endl<<"Input '1' to continue"<<std::endl;
                win = "Yes";
                timesplayed++;
                wincount++;
                streak++;
                ClearStats();
                savewords(target);
                longestword();
                averagecounter = attempts/timesplayed;
                winpercentage = (wincount/timesplayed)*100;
                if (size >8) {
                for (int i =0;i<8;i++) {
                    longwords+=target[i];
                }
                longwords+="...";
                }
                SaveWordStats(temptarget, currentguessnum, win, size, longestlengthword, timesplayed);
                save_stats(attempts,streak,timesplayed,topstreak,winpercentage,averagecounter);
                SaveStatsSummary(timesplayed, averagecounter, winpercentage, streak, topstreak);
                sendGameStatus(9);
                break;
    }

    else if (currentguessnum == 6 && tempguess!= temptarget) {
        system("clear");
                std::string dummy;
                std::cout<<"Executed in "<< duration << "ms"<<std::endl;
                std::cout<<wordle<<std::endl<<std::endl<<"The word was "<<temptarget<<std::endl<<std::endl<<"Better luck next time!"<<std::endl<<std::endl;
                std::cout<<"Input '1' to continue."<<std::endl;
                std::cin>>dummy;
                win = "No";
                timesplayed++;
                if (streak>topstreak) {
                topstreak = streak;
                }
                streak = 0;
                ClearStats();
                savewords(target);
                longestword();
                averagecounter = attempts/timesplayed;
                winpercentage = (wincount/timesplayed)*100;
                if (size >8) {
                for (int i =0;i<8;i++) {
                    longwords+=target[i];
                }
                longwords+="...";
                }
                SaveWordStats(temptarget, currentguessnum, win, size, longestlengthword, timesplayed);
                SaveStatsSummary(timesplayed, averagecounter, winpercentage, streak, topstreak);
                save_stats(attempts,streak,timesplayed,topstreak,winpercentage,averagecounter);
                sendGameStatus(9);
                break;
    }
    }
    }
    }
