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
int retractCurrent_Streak() {
    srand(time(0));
    std::ifstream file("currentstreak.txt", std::ios::in);
    std::string stat1, topstreak;
    if (file.is_open()) {
        while(getline(file, stat1)){
        topstreak+=stat1;
        }
        file.close();
    }
    int currentstreak, stat2;
    std::stringstream one, two;
    one<<topstreak;
    one>>currentstreak;
    return currentstreak;
}
int retractTimes_Played() {
    srand(time(0));
    std::ifstream file("timesplayed.txt", std::ios::in);
    std::string stat1, topstreak;
    if (file.is_open()) {
        while(getline(file, stat1)){
        topstreak+=stat1;
        }
        file.close();
    }
    int currentstreak, stat2;
    std::stringstream one, two;
    one<<topstreak;
    one>>currentstreak;
    return currentstreak;
}
int retractAttempts() {
    srand(time(0));
    std::ifstream file("attempts.txt", std::ios::in);
    std::string stat1, topstreak;
    if (file.is_open()) {
        while(getline(file, stat1)){
        topstreak+=stat1;
        }
        file.close();
    }
    int currentstreak, stat2;
    std::stringstream one, two;
    one<<topstreak;
    one>>currentstreak;
    return currentstreak;
}
int retractTop_Streak() {
    srand(time(0));
    std::ifstream file("topstreak.txt", std::ios::in);
    std::string stat1, topstreak;
    if (file.is_open()) {
        while(getline(file, stat1)){
        topstreak+=stat1;
        }
        file.close();
    }
    int currentstreak, stat2;
    std::stringstream one, two;
    one<<topstreak;
    one>>currentstreak;
    return currentstreak;
}
int retractWins() {
    srand(time(0));
    std::ifstream file("wins.txt", std::ios::in);
    std::string stat1, topstreak;
    if (file.is_open()) {
        while(getline(file, stat1)){
        topstreak+=stat1;
        }
        file.close();
    }
    int currentstreak, stat2;
    std::stringstream one, two;
    one<<topstreak;
    one>>currentstreak;
    return currentstreak;
}
void ClearStats() {
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
    filed.open("statssummary.txt", std::ofstream::out | std::ofstream::trunc);
    filed.close();
    filed.open("temporary.txt", std::ofstream::out | std::ofstream::trunc);
    filed.close();
}
void savewords(std::string l) {
    std::ofstream filmd;
    filmd.open("words.txt", std::ios::app);
    if (filmd.is_open()) {
        filmd<<l<<std::endl;
    }
}
void saveattempt_count(int l) {
    std::ofstream filmd;
    filmd.open("attempcount_stats.txt", std::ios::app);
    if (filmd.is_open()) {
        filmd<<l<<std::endl;
    }
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
        // if (win.length() == 3) {
        //     // file<<win<<std::setw(8)<<count<<std::setw(10)<<std::right<<target<std::endl;
        //     file<<win<<std::setw(8)<<count<<std::setw(10)<<std::right<<target<<std::endl;
        // }
        // else if (win.length() == 2) {
        //     file<<win<<std::setw(9)<<count<<std::setw(10)<<std::right<<target<<std::endl;
        // }
        // else if (win.length() == 4) {
        // file<<win<<std::setw(7)<<count<<std::setw(lengthy+10+(size-5))<<std::right<<target<<std::endl;
        // }
        // for (int i = 0; i < test;i++) {
        // std::ifstream filer;
        // filer.open("words.txt", std::ios::in);
        // if (filer.is_open()) {
        // while (getline(filer, statcount1)) {
        //     statcount2+=statcount1;
        //     file<<statcount2<<std::setw(lengthy+21);
        //     break;
        // }
        // filer.close();
        // }
        // filer.open("win_stats.txt", std::ios::in);
        // if (filer.is_open()) {
        // while (getline(filer, statcount3)) {
        //     file<<statcount3;
        //     break;
        // }
        // filer.close();
        // }
        // filer.open("attempcount_stats.txt", std::ios::in);
        // if (filer.is_open()) {
        // while (getline(filer, statcount5)) {
        //     statcount6+=statcount5;
        // }
        // filer.close();
        // }
        // file<<"\n";
    
        //     for (int i = 0 ; i < 1;i++) {
        //     for (int j = 0 ; j < 3; j++) {
        //         if (j ==1) {
        //             file<<statcount3;
        //         }
        //     }
        // }
        // }
        // filer.close();
        // }
        // filer.open("attempcount_stats.txt", std::ios::in);
        // if (filer.is_open()) {
        // while (getline(filer, statcount5)) {
        //     for (int i = 0 ; i < 1;i++) {
        //     for (int j = 0 ; j < 3; j++) {
        //         if (j == 2) {
        //             file<<statcount5;
        //         }
        //     }
        // }
        // }
        // filer.close();
        // }
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
            // file<<target<<std::setw(9)<<count<<std::setw(8)<<win<<"\n";
    //         std::ofstream testsome;
    //         testsome.open("wordstats.txt", std::ios::app);
    //         if (testsome.is_open()) {
    //                 for (int i = 0; i < 1;i++) {
    //                     for (int j = 0 ; j < 3;j++) {
    //                         if ( j == 0) {
    //                             testsome<<
    //                         }
    //                     }
    //             }
    //         }
    //     }
        
}
void SaveAttempts(int attempts) {
    std::ofstream filmd;
    filmd.open("attempts.txt", std::ios::app);
    if (filmd.is_open()) {
        filmd<<attempts<<std::endl;
        filmd.close();
    }
}
void SaveCurrent_Streak(int streak){
    std::ofstream fffilmmd;
    fffilmmd.open("currentstreak.txt", std::ios::app);
    if (fffilmmd.is_open()) {
        fffilmmd<<streak<<std::endl;
        fffilmmd.close();
    }
}
void SaveTop_Streak(int topstreak) {
    std::ofstream fffilmmd;
    fffilmmd.open("topstreak.txt", std::ios::app);
    if (fffilmmd.is_open()) {
        fffilmmd<<topstreak<<std::endl;
        fffilmmd.close();
    }
}
void SaveTimesPlayed(int times) {
    std::ofstream fffilmmd;
    fffilmmd.open("timesplayed.txt", std::ios::app);
    if (fffilmmd.is_open()) {
        fffilmmd<<times<<std::endl;
        fffilmmd.close();
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