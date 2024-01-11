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
std::string lengthword = "", tempword, test, tester, something, block;
std::string toprow, bottomrow;
int longestlengthword = 0, resizer = 0;
std::vector<int> all_stats;
int longestword() {
    lengthword.clear();
    longestlengthword = 0;
    std::ifstream file("words.txt", std::ios::in);
    std::string stat1;
    int lines;
    if (file.is_open()) {
        while(getline(file, stat1)) {
            if (stat1.length() > lengthword.length()) {
                lengthword = stat1;
            }
        }
        file.close();
    }
    longestlengthword = lengthword.length();
    return longestlengthword;
}
void ClearStats() {
    std::ofstream file;
    file.open("stats.txt", std::ofstream::out);
    for (int i = 0; i < 6;i++) {
        file<<"0"<<std::endl;
    }
    file.close();
}
void savewords(std::string l) {
    std::ofstream filmd;
    filmd.open("words.txt", std::ios::app);
    if (filmd.is_open()) {
        filmd<<l<<std::endl;
    }
}
std::vector<int> retract_stats() {
    all_stats.clear();
    std::ifstream file("stats.txt", std::ios::in);
    std::string temp,temps;
    if (file.is_open()) {
       while(getline(file,temp)) {
        all_stats.push_back(stoi(temp));
       }
    }
    return all_stats;
}
void save_stats(int att,int curr, int times, int top, int wins, int average) {
    // film.open("currentstreak.txt", std::ofstream::out | std::ofstream::trunc);
    // film.close();
    std::ofstream file;
    file.open("stats.txt", std::ofstream::out | std::ofstream::trunc);
    file.close();
    file.open("stats.txt",std::ios::app);
    if (file.is_open()) {
        file<<att<<"\n";//total attempts
        file<<curr<<"\n";//current streak
        file<<times<<"\n";//times played
        file<<top<<"\n";//top streak
        file<<wins<<"\n";//total wins
        file<<average<<"\n";//average number to attempts
    }
    file.close();
}

void savewin_stats(std::string l) {
    std::ofstream filmd;
    filmd.open("win_stats.txt", std::ios::app);
    if (filmd.is_open()) {
        filmd<<l<<std::endl;
    }
}
void resizestats(int nothing) {
    std::ofstream file;
    file.open("temporary.txt", std::ios::app);
    if (file.is_open()) {
        while (toprow.length() < (nothing+21+(nothing-5))) {
            toprow+="-";
        }
        file<<toprow;
        file.close();
    }
}
void SaveWordStats(std::string target, int count, std::string win, int size, int lengthy, int test) {
    std::string toprow = "", bottomrow = "", middlerow = "", statcount1, statcount2, statcount3, statcount4, statcount5, statcount6;
    std::ofstream file;
    file.open("wordstats.txt",std::ios::app);
    if (file.is_open()) {
        if (size == 4) {
            file<<target<<std::setw(13)<<count<<std::setw(9)<<win;
        }
        else if (size == 5) {
            file<<target<<std::setw(12)<<count<<std::setw(9)<<win;
        }
        else if (size == 6) {
            file<<target<<std::setw(11)<<count<<std::setw(9)<<win;
        }
        else if (size == 7) {
            file<<target<<std::setw(10)<<count<<std::setw(9)<<win;
        }
        else if (size == 8) {
            file<<target<<std::setw(9)<<count<<std::setw(9)<<win;
        }
        else {
            file<<target<<std::setw(6)<<count<<std::setw(9)<<win;
        }
        file.close();
    }
    file.open("wordstats.txt",std::ios::app);
    if (file.is_open()) {
        if (size <10) {
            file<<"         "<<size<<"\n";
        }
        if (size > 9) {
            file<<"        "<<size<<"\n";
        }
    }
}

void SaveWins(int wins) {
    std::ofstream fffilmmd;
    fffilmmd.open("wins.txt", std::ios::app);
    if (fffilmmd.is_open()) {
        fffilmmd<<wins<<std::endl;
        fffilmmd.close();
    }
}
void SaveStatsSummary(int times, int averagecounter, float winpercentage, int streak, int topstreak) {
    std::ofstream files;
    files.open("statssummary.txt", std::ofstream::out);
    files.close();
    // "stats.txt", std::ofstream::out)
    files.open("statssummary.txt", std::ios::app);
    if (files.is_open()) {
        files<<"Times Played:"<<std::setw(13)<<times<<"\n";
        files<<"Average Attempts"<<std::setw(10)<<averagecounter<<"\n";
        files<<"Win Percentage: "<<std::setw(9)<<std::setprecision(3)<<winpercentage<<"%"<<std::endl;
        files<<"Current Streak: "<<std::setw(10)<<streak<<std::endl;
        files<<"Longest Streak: "<<std::setw(10)<<topstreak<<std::endl;
        files.close();
    }
}
