#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define GREY "\033[90m"
std::string starter, words = "", returner = "";
void overrideColors() {
    std::ofstream file;
    file.open("status.txt", std::ios::out);
        if (file.is_open()) {
            file<<"10"<<std::endl;
            file.close();
        }
}
void readUpdatedColors() {
    std::ifstream file;
    std::string s,ss;
    file.open("colors.txt", std::ios::in);
    if (file.is_open()) {
        while (getline(file,s)) {
            ss+=s;
        }
    }
    words = ss;
}
void updateColors() {
    for (int i = 0; i < words.length();i++) {
         if (words[i] == '3') {
            std::cout<<GREY<<" --- "<<RESET;
        }
        else if (words[i] == '2') {
            std::cout<<YELLOW<<" --- "<<RESET;
        }
        else if (words[i] == '1') {
            std::cout<<GREEN<<" --- "<<RESET;
        }
        else if (words[i] == '4') {
            std::cout<<" --- "<<RESET;
        }
        if (words[i] == 'A') {
            break;
        }    
    }
    std::cout<<'\n';
    for (int i = 0; i < words.length();i++) {
         if (words[i] == '3') {
            std::cout<<GREY<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |"<<RESET;
        }
        else if (words[i] == '2') {
            std::cout<<YELLOW<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |"<<RESET;
        }
        else if (words[i] == '1') {
            std::cout<<GREEN<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |"<<RESET;
        }
        else if (words[i] == '4') {
            std::cout<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |";
        }
        if (words[i] == 'A') {
            break;
        }    
    }
    std::cout<<'\n';
    for (int i = 0; i < words.length();i++) {
         if (words[i] == '3') {
            std::cout<<GREY<<" --- "<<RESET;
        }
        else if (words[i] == '2') {
            std::cout<<YELLOW<<" --- "<<RESET;
        }
        else if (words[i] == '1') {
            std::cout<<GREEN<<" --- "<<RESET;
        }
        else if (words[i] == '4') {
            std::cout<<" --- "<<RESET;
        }
        if (words[i] == 'A') {
            break;
        }    
    }
    std::cout<<"\n   ";
    for (int i = 20; i < words.length();i++) {
        if (words[i] == '3') {
            std::cout<<GREY<<" --- "<<RESET;
        }
        else if (words[i] == '2') {
            std::cout<<YELLOW<<" --- "<<RESET;
        }
        else if (words[i] == '1') {
            std::cout<<GREEN<<" --- "<<RESET;
        }
        else if (words[i] == '4') {
            std::cout<<" --- "<<RESET;
        }
        if (words[i] == 'Z') {
            break;
        }    
    }
    std::cout<<"\n   ";
    for (int i = 20; i < words.length();i++) {
         if (words[i] == '3') {
            std::cout<<GREY<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |"<<RESET;
        }
        else if (words[i] == '2') {
            std::cout<<YELLOW<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |"<<RESET;
        }
        else if (words[i] == '1') {
            std::cout<<GREEN<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |"<<RESET;
        }
        else if (words[i] == '4') {
            std::cout<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |";
        }
        if (words[i] == 'Z') {
            break;
        }    
    }
    std::cout<<"\n   ";
    for (int i = 20; i < words.length();i++) {
        if (words[i] == '3') {
            std::cout<<GREY<<" --- "<<RESET;
        }
        else if (words[i] == '2') {
            std::cout<<YELLOW<<" --- "<<RESET;
        }
        else if (words[i] == '1') {
            std::cout<<GREEN<<" --- "<<RESET;
        }
        else if (words[i] == '4') {
            std::cout<<" --- "<<RESET;
        }
        if (words[i] == 'Z') {
            break;
        }    
    }
    std::cout<<"\n      ";
    for (int i = 38; i < words.length();i++) {
        if (words[i] == '3') {
            std::cout<<GREY<<" --- "<<RESET;
        }
        else if (words[i] == '2') {
            std::cout<<YELLOW<<" --- "<<RESET;
        }
        else if (words[i] == '1') {
            std::cout<<GREEN<<" --- "<<RESET;
        }
        else if (words[i] == '4') {
            std::cout<<" --- "<<RESET;
        } 
    }
    std::cout<<"\n      ";
    for (int i = 38; i < words.length();i++) {
         if (words[i] == '3') {
            std::cout<<GREY<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |"<<RESET;
        }
        else if (words[i] == '2') {
            std::cout<<YELLOW<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |"<<RESET;
        }
        else if (words[i] == '1') {
            std::cout<<GREEN<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |"<<RESET;
        }
        else if (words[i] == '4') {
            std::cout<<"| ";
            std::cout<<words[i-1];
            std::cout<<" |";
        }
    }
    std::cout<<"\n      ";
    for (int i = 38; i < words.length();i++) {
        if (words[i] == '3') {
            std::cout<<GREY<<" --- "<<RESET;
        }
        else if (words[i] == '2') {
            std::cout<<YELLOW<<" --- "<<RESET;
        }
        else if (words[i] == '1') {
            std::cout<<GREEN<<" --- "<<RESET;
        }
        else if (words[i] == '4') {
            std::cout<<" --- "<<RESET;
        }
    }
    std::cout<<std::endl;
}
void readstart() {
    std::ifstream file; 
    std::string filed, filedd;
    int test;
    file.open("status.txt", std::ios::in);
    if (file.is_open()) {
        while (getline(file, filed)) {
            filedd += filed;
        }
        file.close();
    }
    starter = (filedd);
}
void firstprint() {
    std::string row1 = "QWERTYUIOP";
    std::string row2 = "ASDFGHJKL";
    std::string row3 = "ZXCVBNM";
    std::string out1, out2, out3;
    for (int i = 0; i < row1.length();i++) {
        out1+= " --- ";
    }
    out1+="\n";
    for (int i = 0; i < row1.length();i++) {
        out1+= "| ";
        out1+= row1[i];
        out1+= " |";
    }
    out1+="\n";
    for (int i = 0; i < row1.length();i++) {
        out1+= " --- ";
    }
    out1+="\n   ";
    for (int i = 0; i < row2.length();i++) {
        out2+= " --- ";
    }
    out2+="\n   ";
    for (int i = 0; i < row2.length();i++) {
        out2+= "| ";
        out2+=row2[i];
        out2+=" |";
    }
    out2+="\n   ";
    for (int i = 0; i < row2.length();i++) {
        out2+= " --- ";
    }
    out2+="\n      ";

    for (int i = 0; i < row3.length();i++) {
        out3+= " --- ";
    }
    out3+="\n      ";
    for (int i = 0; i < row3.length();i++) {
        out3+= "| ";
        out3+=row3[i];
        out3+=" |";
    }
    out3+="\n      ";
    for (int i = 0; i < row3.length();i++) {
        out3+= " --- ";
    }
    out3+="\n   ";
    std::cout<<out1<<out2<<out3<<std::endl;
}