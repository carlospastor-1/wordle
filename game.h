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
char DupeinGuess(std::string guess) {
    for (int i = 0; i < guess.length();i++) {
        for (int j = i+1; j < guess.length();j++) {
            if (guess[i] == guess[j]) {
                guessdupe = guess[i];
            }
        }
    }
    return guessdupe;
}
int NumsofGuess_Dupe (std::string guess, std::string letter) {
    for (int i = 0; i < guess.length();i++) {
        if (std::to_string(guess[i]) == letter) {
            guessdupecounter++;
        }
    }
    return guessdupecounter;
}
int NumsofTarget_Dupe (std::string targeter, std::string letter) {
    for (int i = 0; i < targeter.length();i++) {
        if (std::to_string(targeter[i]) == letter) {
            targetdupecounter++;
        }
    }
    return targetdupecounter;
}
int NumsofTarget_Dupe2 (std::string targeter, std::string letter) {
    for (int i = 0; i < targeter.length();i++) {
        if (std::to_string(targeter[i]) == letter) {
            target2dupecounter++;
        }
    }
    return target2dupecounter;
}
int NumsofTarget_Dupe3 (std::string targeter, std::string letter) {
    for (int i = 0; i < targeter.length();i++) {
        if (std::to_string(targeter[i]) == letter) {
            target3dupecounter++;
        }
    }
    return target3dupecounter;
}
int NumsofTarget_Dupe4 (std::string targeter, std::string letter) {
    for (int i = 0; i < targeter.length();i++) {
        if (std::to_string(targeter[i]) == letter) {
            target4dupecounter++;
        }
    }
    return target4dupecounter;
}
int NumsofTarget_Dupe5 (std::string targeter, std::string letter) {
    for (int i = 0; i < targeter.length();i++) {
        if (std::to_string(targeter[i]) == letter) {
            target5dupecounter++;
        }
    }
    return target5dupecounter;
}
char DupeinTarget(std::string guess) {
    for (int i = 0; i < guess.length();i++) {
        for (int j = i+1; j < guess.length();j++) {
            if (guess[i] == guess[j]) {
                targetdupe = guess[i];
            }
        }
    }
    return targetdupe;
}
char SecondDupe_LetterinGuess(std::string target, std::string letter) {
    for (int i = 0; i < target.length();i++) {
        for (int j = i+1; j < target.length();j++) {
            if (target[i] == target[j] && std::to_string(target[i]) != letter) {
                second_dupe = target[i];
            }
        }
    }
    return second_dupe;
}
char SecondDupe_LetterinTarget(std::string target, std::string letter) {
    for (int i = 0; i < target.length();i++) {
        for (int j = i+1; j < target.length();j++) {
            if (target[i] == target[j] && std::to_string(target[i]) != letter) {
                targetdupe2 = target[i];
            }
        }
    }
    return targetdupe2;
}
char ThirdDuper_LetterinGuess(std::string target, std::string letter1,std::string letter2) {
    for (int i = 0; i < target.length();i++) {
        for (int j = i+1; j < target.length();j++) {
            if (target[i] == target[j] && (std::to_string(target[i]) != letter1 && std::to_string(target[i])!=letter2)) {
                third_dupe = target[i];
            }
        }
    }
    return third_dupe;
}
char FourthDuper_LetterinGuess(std::string target, std::string letter1,std::string letter2, std::string letter3) {
    for (int i = 0; i < target.length();i++) {
        for (int j = i+1; j < target.length();j++) {
            if (target[i] == target[j] && (std::to_string(target[i]) != letter1 && std::to_string(target[i])!=letter2) && std::to_string(target[i]) != letter3) {
                fourth_dupe = target[i];
            }
        }
    }
    return fourth_dupe;
}
char FifthDuper_LetterinGuess(std::string target, std::string letter1,std::string letter2, std::string letter3, std::string letter4) {
    for (int i = 0; i < target.length();i++) {
        for (int j = i+1; j < target.length();j++) {
            if (target[i] == target[j] && (std::to_string(target[i]) != letter1 && std::to_string(target[i])!=letter2) && std::to_string(target[i]) != letter3 && std::to_string(target[i]) != letter4) {
                fifth_dupe = target[i];
            }
        }
    }
    return fifth_dupe;
}
char ThirdDuper_LetterinTarget(std::string target, std::string letter1,std::string letter2) {
    for (int i = 0; i < target.length();i++) {
        for (int j = i+1; j < target.length();j++) {
            if (target[i] == target[j] && (std::to_string(target[i]) != letter1 && std::to_string(target[i])!=letter2)) {
                targetdupe3 = target[i];
            }
        }
    }
    return targetdupe3;
}
char FourthDuper_LetterinTarget(std::string target, std::string letter1,std::string letter2, std::string letter3) {
    for (int i = 0; i < target.length();i++) {
        for (int j = i+1; j < target.length();j++) {
            if (target[i] == target[j] && (std::to_string(target[i]) != letter1 && std::to_string(target[i])!=letter2) && std::to_string(target[i]) != letter3) {
                targetdupe4 = target[i];
            }
        }
    }
    return targetdupe4;
}
char FifthDuper_LetterinTarget(std::string target, std::string letter1,std::string letter2, std::string letter3, std::string letter4) {
    for (int i = 0; i < target.length();i++) {
        for (int j = i+1; j < target.length();j++) {
            if (target[i] == target[j] && (std::to_string(target[i]) != letter1 && std::to_string(target[i])!=letter2) && std::to_string(target[i]) != letter3 && std::to_string(target[i]) != letter4) {
                targetdupe5 = target[i];
            }
        }
    }
    return targetdupe5;
}
std::string PrintWordle(std::vector<int> test, int size) {
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
            wordle+=currentguess[i];
            wordle+=" |";
            wordle+=RESET;
        }
        else if (test[i] == 2) {
            wordle+=YELLOW;
            wordle+="| ";
            wordle+=currentguess[i];
            wordle+=" |";
            wordle+=RESET;
        }
        else if (test[i] == 3) {
            wordle+=GREY;
            wordle+="| ";
            wordle+=currentguess[i];
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
void nodupe () {
    
}
void PlayWordle(int size, std::string targets, std::string allowed) {
    wordle.clear();
    system("clear");
    std::cout<<"Input '6' to quit the game"<<std::endl;
    words = "Q4W4E4R4T4Y4U4I4O4P4A4S4D4F4G4H4J4K4L4Z4X4C4V4B4N4M4";
    clearColors(words);
    streak = retractCurrent_Streak();
    timesplayed = retractTimes_Played();
    attempts = retractAttempts();
    topstreak = retractTop_Streak();
    wincount = retractWins();
    if (size == 0) {
        size = 5;
    }
    randomword(targets);
    // target = "";
    uppercase(target);
    std::string dummy;
    char nondupe, nondupee, nonduper;
    int maxguess = 6, currentguessnum = 0, tempguess = 0, firstdupe = 0, seconddupe = 0, thirddupe = 0, correct = 0;
    int dupecounter = 0, seconddupecounter = 0, thirddupecounter = 0, fourthdupecounter = 0, fifthdupecounter = 0;
    int guessfirstdupecounter = 0, guessseconddupecounter = 0, guessthirdupecounter = 0, guessfourthdupecounter = 0, guessfifthdupecounter = 0;
    int targetcounter1 = 0, targetcounter2 = 0, targetcounter3 = 0, targetcounter4 = 0, targetcounter5 = 0;
    char targetdupe1;
    longestlengthword = 0;
    resizer = 0;
    status = 2;
    getline(std::cin,currentguess);
    if (currentguess.length() == 1 && currentguess == "6") {
            if (wordle != "") {
                system("clear");
                std::cout<<"Input '6' to quit the game"<<std::endl;
                std::cout<<wordle<<std::endl;
                std::cout<<"Enter guess: ";
            }
            else {
                system("clear");
                std::cout<<"Input '6' to quit the game"<<std::endl;
                std::cout<<currentguessnum<<"/"<<maxguess<<std::endl;
                std::cout<<"Enter guess: ";
            }
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
            streak = 0;
            ClearStats();
            savewords(target);
            savewin_stats(win);
            saveattempt_count(attempts);
            longestword();
            averagecounter = attempts/timesplayed;
            winpercentage = (wincount/timesplayed)*100;
            if (size > 8) {
            SaveWordStats(longwords, currentguessnum, win, size, longestlengthword, timesplayed);
            }
            else {
            SaveWordStats(target, currentguessnum, win, size, longestlengthword, timesplayed);
            }
            resizestats(longestlengthword);
            SaveAttempts(attempts);
            SaveCurrent_Streak(streak);
            SaveTop_Streak(topstreak);
            SaveTimesPlayed(timesplayed);
            SaveWins(wincount);
            SaveStatsSummary(timesplayed, averagecounter, winpercentage, streak, topstreak);
            currentguessnum = 6;
            getline(std::cin, dummy);
            sendGameStatus(9);
        }
    while (currentguessnum < maxguess) {
        auto start = std::chrono::high_resolution_clock::now();
        std::cout<<"Enter guess: ";
        getline(std::cin, currentguess);
        if (currentguess.length() == 1 && currentguess == "6") {
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
            streak = 0;
            ClearStats();
            savewords(target);
            longestword();
            savewin_stats(win);
            saveattempt_count(attempts);
            averagecounter = attempts/timesplayed;
            winpercentage = (wincount/timesplayed)*100;
            if (size > 8) {
            SaveWordStats(longwords, currentguessnum, win, size, longestlengthword, timesplayed);
            }
            else {
            SaveWordStats(target, currentguessnum, win, size, longestlengthword, timesplayed);
            }
            resizestats(longestlengthword);
            SaveAttempts(attempts);
            SaveCurrent_Streak(streak);
            SaveTop_Streak(topstreak);
            SaveTimesPlayed(timesplayed);
            SaveWins(wincount);
            SaveStatsSummary(timesplayed, averagecounter, winpercentage, streak, topstreak);
            currentguessnum = 6;
            getline(std::cin, dummy);
            sendGameStatus(9);
            continue;
        }
        while(currentguess.length() <= size-1 || currentguess.length() > size) {
            if (wordle != "") {
                system("clear");
                std::cout<<"Input '6' to quit the game"<<std::endl;
                std::cout<<currentguessnum<<"/"<<maxguess<<std::endl;
                std::cout<<wordle<<std::endl;
                std::cout<<"Enter guess: ";
            }
            else {
                system("clear");
                std::cout<<"Input '6' to quit the game"<<std::endl;
                std::cout<<"Enter guess: ";
            }
            getline(std::cin,currentguess);
            if (currentguess.length() == 1 && currentguess == "6") {
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
            streak = 0;
            ClearStats();
            savewords(target);
            longestword();
            averagecounter = attempts/timesplayed;
            winpercentage = (wincount/timesplayed)*100;
            if (size > 8) {
            SaveWordStats(longwords, currentguessnum, win, size, longestlengthword, timesplayed);
            }
            else {
            SaveWordStats(target, currentguessnum, win, size, longestlengthword, timesplayed);
            }
            resizestats(longestlengthword);
            SaveAttempts(attempts);
            SaveCurrent_Streak(streak);
            SaveTop_Streak(topstreak);
            SaveTimesPlayed(timesplayed);
            SaveWins(wincount);
            SaveStatsSummary(timesplayed, averagecounter, winpercentage, streak, topstreak);
            currentguessnum = 6;
            getline(std::cin, dummy);
            sendGameStatus(9);
            break;
        }
        }
        if (checkWord(currentguess, allowed) || inList(currentguess, targets)) {
            uppercase(currentguess);
            uppercase(target);
            DupeinGuess(currentguess);
            DupeinTarget(target);
            std::vector<int> test(size);
            system("clear");
            thirddupe = 0;
            seconddupe = 0;
            firstdupe = 0;
            tempguess = 0;
            correct = 2;
            guessfirstdupecounter = 0;
            guessseconddupecounter = 0;
            guessthirdupecounter = 0;
            guessfourthdupecounter = 0;
            guessfifthdupecounter = 0;
            targetdupecounter = 0;
            target2dupecounter = 0;
            target3dupecounter = 0;
            target4dupecounter = 0;
            target5dupecounter = 0;
            dupecounter = 0;
            seconddupecounter = 0;
            thirddupecounter = 0;
            fourthdupecounter = 0;
            fifthdupecounter = 0;
            longwords.clear();
            if (targetdupe == '*') {
                for (int i = 0; i<size;i++) {
                    if (i == 0) {
                        DupeinGuess(currentguess);
                        SecondDupe_LetterinGuess(currentguess, std::to_string (guessdupe));
                        ThirdDuper_LetterinGuess(currentguess, std::to_string (guessdupe), std::to_string (second_dupe));
                        FourthDuper_LetterinGuess(currentguess, std::to_string(guessdupe), std::to_string (second_dupe), std::to_string (third_dupe));
                        FifthDuper_LetterinGuess(currentguess, std::to_string(guessdupe), std::to_string (second_dupe), std::to_string (third_dupe), std::to_string (fourth_dupe));
                    }
                    for (int j = 0;j<size;j++) {
                        if (target.find(currentguess[i])<=size == false ){
                            test[i] = 3;
                            redirect(currentguess[i], '3');
                        }
                        if (currentguess[i] == target[i]) {
                            test[i] = 1;
                            redirect(currentguess[i], '1');
                            if (currentguess[i] == guessdupe) {
                                guessfirstdupecounter++;
                            }
                            else if (currentguess[i] == second_dupe) {
                                guessseconddupecounter++;
                            }
                            else if (currentguess[i] == third_dupe) {
                                guessthirdupecounter++;
                            }
                            else if (currentguess[i] == fourth_dupe) {
                                guessfourthdupecounter++;
                            }
                            else if (currentguess[i] == fifth_dupe) {
                                guessfifthdupecounter++;
                            }
                        }
                    }
                }
                for (int i = 0; i< size;i++) {
                    for (int j = 0;j<size;j++) {
                        if (currentguess[i] == target[j] && currentguess[i] != target[i]) {
                            redirect(currentguess[i], '2');
                            if (currentguess[i] == guessdupe) {
                                if (guessfirstdupecounter == 0) {
                                    test[i] = 2;
                                    guessfirstdupecounter++;
                                }
                                else {
                                    test[i] = 3;
                                }
                            }
                            else if (currentguess[i] == second_dupe) {
                                if (guessseconddupecounter == 0) {
                                    test[i] = 2;
                                    guessseconddupecounter++;
                                }
                                else {
                                    test[i] = 3;
                                }
                            }
                            else if (currentguess[i] == third_dupe) {
                                if (guessthirdupecounter == 0) {
                                    test[i] = 2;
                                    guessthirdupecounter++;
                                }
                                else {
                                    test[i] = 3;
                                }
                            }
                            else if (currentguess[i] == fourth_dupe) {
                                if (guessfourthdupecounter == 0) {
                                    test[i] = 2;
                                    guessfourthdupecounter++;
                                }
                                else {
                                    test[i] = 3;
                                }
                            }
                            else if (currentguess[i] == fifth_dupe) {
                                if (guessfifthdupecounter == 0) {
                                    test[i] = 2;
                                    guessfifthdupecounter++;
                                }
                                else {
                                    test[i] = 3;
                                }
                            }
                            else {
                                test[i] = 2;
                            }
                        }
                    }
                }
            }
            if (targetdupe != '*') {
                DupeinTarget(target);
                SecondDupe_LetterinTarget(target, std::to_string (targetdupe));
                ThirdDuper_LetterinTarget(target, std::to_string (targetdupe), std::to_string (targetdupe2));
                FourthDuper_LetterinTarget(target, std::to_string(targetdupe), std::to_string (targetdupe2), std::to_string (targetdupe3));
                FifthDuper_LetterinTarget(target, std::to_string(targetdupe), std::to_string (targetdupe2), std::to_string (targetdupe3), std::to_string(targetdupe4));
                NumsofTarget_Dupe(target, std::to_string (targetdupe));
                NumsofTarget_Dupe2(target, std::to_string (targetdupe2));
                NumsofTarget_Dupe3(target, std::to_string (targetdupe3));
                NumsofTarget_Dupe4(target, std::to_string(targetdupe4));
                NumsofTarget_Dupe5(target, std::to_string(targetdupe5));
                DupeinGuess(currentguess);
                SecondDupe_LetterinGuess(currentguess, std::to_string (guessdupe));
                ThirdDuper_LetterinGuess(currentguess, std::to_string (guessdupe), std::to_string (second_dupe));
                FourthDuper_LetterinGuess(currentguess, std::to_string(guessdupe), std::to_string(second_dupe), std::to_string (third_dupe));
                FifthDuper_LetterinGuess(currentguess, std::to_string(guessdupe), std::to_string(second_dupe), std::to_string (third_dupe), std::to_string(fourth_dupe));
                for (int i = 0; i < size;i++) {
                    for (int j = 0;j<size;j++) {
                        if (target.find(currentguess[i])<=size == false) {
                            test[i] = 3;
                            redirect(currentguess[i], '3');
                        }
                        else if (currentguess[i] == target[j] && i == j) {
                            test[i] = 1;
                            redirect(currentguess[i], '1');
                            if (currentguess[i] == targetdupe) {
                                guessfirstdupecounter++;
                            }
                            else if (currentguess[i] == targetdupe2) {
                                guessseconddupecounter++;
                            }
                            else if (currentguess[i] == targetdupe3) {
                                guessthirdupecounter++;
                            }
                            else if (currentguess[i] == targetdupe4) {
                                guessfourthdupecounter++;
                            }
                            else if (currentguess[i] == targetdupe5) {
                                guessfifthdupecounter++;
                            }
                        }
                    }
                }
                for (int i = 0; i < size;i++) {
                    for (int j = 0; j < size;j++) {
                        if (currentguess[i] == target[j] && i == j) {
                            if (currentguess[i] == guessdupe) {
                                dupecounter++;
                            }
                            else if (currentguess[i] == second_dupe) {
                                seconddupecounter++;
                            }
                            else if (currentguess[i] == third_dupe) {
                                thirddupecounter++;
                            }
                            else if (currentguess[i] == fourth_dupe) {
                                fourthdupecounter++;
                            }
                            else if (currentguess[i] == fifth_dupe) {
                                fifthdupecounter++;
                            }
                        }
                    }
                }
                for (int i = 0;i<size;i++) {
                    for (int j = 0;j<size;j++) {
                        redirect(currentguess[i], '2');
                        if (currentguess[i] == target[j] && currentguess[i] != target[i]) {
                        if (currentguess[i] == targetdupe) {
                            if (guessfirstdupecounter!=targetdupecounter) {
                                test[i] = 2;
                                guessfirstdupecounter++;
                                break;
                            }
                            else {
                                test[i] = 3;
                            }
                        }
                        else if (currentguess[i] == targetdupe2) {
                            if (guessseconddupecounter!=target2dupecounter) {
                                test[i] = 2;
                                guessseconddupecounter++;
                                break;
                            }
                            else {
                                test[i] = 3;
                            }
                        }
                        else if (currentguess[i] == targetdupe3) {
                            if (guessthirdupecounter!=target3dupecounter) {
                                test[i] = 2;
                                guessthirdupecounter++;
                                break;
                            }
                            else {
                                test[i] = 3;
                            }
                        }
                        else if (currentguess[i] == targetdupe4) {
                            if (guessfourthdupecounter!=target4dupecounter) {
                                test[i] = 2;
                                guessfourthdupecounter++;
                                break;
                            }
                            else {
                                test[i] = 3;
                            }
                        }
                        else if (currentguess[i] == targetdupe5) {
                            if (guessfifthdupecounter!=target5dupecounter) {
                                test[i] = 2;
                                guessfifthdupecounter++;
                                break;
                            }
                            else {
                                test[i] = 3;
                            }
                        }
                        else {
                            if (currentguess[i] == guessdupe) {
                                if (dupecounter == 0) {
                                    test[i] = 2;
                                    dupecounter++;
                                    break;
                                }
                                else {
                                    test[i] = 3;
                                }
                            }
                            else if (currentguess[i] == second_dupe) {
                                if (seconddupecounter == 0) {
                                    test[i] = 2;
                                    seconddupecounter++;
                                    break;
                                }
                                else {
                                    test[i] = 3;
                                }
                            }
                            else if (currentguess[i] == third_dupe) {
                                if (thirddupecounter == 0) {
                                    test[i] = 2;
                                    thirddupecounter++;
                                    break;
                                }
                                else {
                                    test[i] = 3;
                                }
                            }
                            else if (currentguess[i] == fourth_dupe) {
                                if (fourthdupecounter == 0) {
                                    test[i] = 2;
                                    fourthdupecounter++;
                                    break;
                                }
                                else {
                                    test[i] = 3;
                                }
                            }
                            else if (currentguess[i] == fifth_dupe) {
                                if (fifthdupecounter == 0) {
                                    test[i] = 2;
                                    fifthdupecounter++;
                                    break;
                                }
                                else {
                                    test[i] = 3;
                                }
                            }
                            else {
                                test[i] = 2;
                            }
                        }
                        }
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
            std::cout<<"Executed in "<< duration << "ms"<<std::endl;
            PrintWordle(test, size);
            std::cout<<"Input '6' to quit the game"<<std::endl;
            std::cout<<currentguessnum<<"/"<<maxguess<<std::endl;
            std::cout<<wordle;
            if (currentguess == target) {
                system("clear");
                std::cout<<"Executed in "<< duration << "ms"<<std::endl;
                std::cout<<wordle<<std::endl<<"Splendid!"<<std::endl<<std::endl<<"Press [enter] to continue"<<std::endl;
                getline(std::cin, dummy);
                win = "Yes";
                timesplayed++;
                wincount++;
                streak++;
                ClearStats();
                savewords(target);
                saveattempt_count(attempts);
                savewin_stats(win);
                longestword();
                averagecounter = attempts/timesplayed;
                winpercentage = (wincount/timesplayed)*100;
                if (size >8) {
                for (int i =0;i<8;i++) {
                    longwords+=target[i];
                }
                longwords+="...";
                }
                if (size > 8) {
                SaveWordStats(longwords, currentguessnum, win, size, longestlengthword, timesplayed);
                }
                else {
                SaveWordStats(target, currentguessnum, win, size, longestlengthword, timesplayed);
                }
                resizestats(longestlengthword);
                SaveAttempts(attempts);
                SaveCurrent_Streak(streak);
                SaveTop_Streak(topstreak);
                SaveTimesPlayed(timesplayed);
                SaveWins(wincount);
                SaveStatsSummary(timesplayed, averagecounter, winpercentage, streak, topstreak);
                sendGameStatus(9);
                break;
            }
            else if (currentguessnum == 6 && currentguess!= target) {
            system("clear");
            std::cout<<"Executed in "<< duration << "ms"<<std::endl;
            std::cout<<wordle<<std::endl<<std::endl<<"The word was "<<target<<std::endl<<std::endl<<"Better luck next time!"<<std::endl<<std::endl;
            std::cout<<"Press [enter] to continue";
            getline(std::cin,dummy);
            win = "No";
            timesplayed++;
            words = "Q4W4E4R4T4Y4U4I4O4P4A4S4D4F4G4H4J4K4L4Z4X4C4V4B4N4M4";
            if (streak>topstreak) {
                topstreak = streak;
            }
            streak = 0;
            averagecounter = attempts/timesplayed;
            winpercentage = (wincount/timesplayed)*100;
            ClearStats();
            savewords(target);
            longestword();
            if (size >8) {
                for (int i =0;i<8;i++) {
                    longwords+=target[i];
                }
                longwords+="...";
                }
            if (size > 8) {
                SaveWordStats(longwords, currentguessnum, win, size, longestlengthword, timesplayed);
                }
                else {
                SaveWordStats(target, currentguessnum, win, size, longestlengthword, timesplayed);
                }
                resizestats(longestlengthword);
            SaveAttempts(attempts);
            SaveCurrent_Streak(streak);
            SaveTop_Streak(topstreak);
            SaveTimesPlayed(timesplayed);
            SaveWins(wincount);
            SaveStatsSummary(timesplayed, averagecounter, winpercentage, streak, topstreak);
            sendGameStatus(9);
            break;
            }
        }
    }
}