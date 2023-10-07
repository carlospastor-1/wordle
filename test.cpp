#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char*argv[]) {
    auto start = std::chrono::high_resolution_clock::now();
    //PROBLEM SET 1;
    // std::cout<<"Height:";
    // std::string height;
    // std::cin>>height;
    // int heightnum = std::stoi(height),spaces = heightnum;
    // int amount =1;
    // for (int i = 0;i < heightnum;i++) {
    //     for (int i = 0; i < spaces-1;i++) {
    //         std::cout<<" ";
    //     }
    //     for (int m = 0; m < amount;m++) {
    //         std::cout<<"#";
    //         if (m == amount-1) {
    //             for (int i = 0; i < amount;i++) {
    //                 if (i==0) {
    //                 std::cout<<" ";
    //                 }
    //                 std::cout<<"#";
    //             }
    //         }
    //     }
    //     std::cout<<std::endl;
    //     spaces--;
    //     amount++;
    //     if (spaces == 0) {
    //         return 0;
    //     }
    // }
    
    //PROBLEM SET 3 (just missing a check if name is valid);
    // std::vector<std::string> names;
    // std::string enteredname;
    // int numofvotes, guesscount = 1;
    // std::vector<int> count;
    // for (int i = 1; i < argc;i++) {
    //     names.push_back(argv[i]);
    // }
    // for (int i = 1; i < argc;i++) {
    //     count.push_back(0);
    // }
    // int candidates = argc-1;
    // std::cout<<"Number of voters: ";
    // std::cin>>numofvotes;
    // std::cout<<"Vote: ";
    // std::cin>>enteredname;
    // while (guesscount != numofvotes) {
    //     for (int i = 0; i < names.size();i++) {
    //         if (enteredname == names[i]) {
    //             count[i] +=1;
    //         }
    //     }
    //     std::cout<<"Vote: ";
    //     std::cin>>enteredname;
    //     guesscount++;
    // }
    // if (guesscount == numofvotes) {
    //     for (int i = 0; i < names.size();i++) {
    //         if ((enteredname) == (names[i])) {
    //             count[i] +=1;
    //         }
    //     }
    // }
    // int maxvote = 0;
    // for (int i = 0 ; i < count.size();i++) {
    //     if (count[i] > maxvote) {
    //         maxvote = count[i];
    //     }
    // }
    // for (int i = 0 ; i < count.size();i++) {
    //     if (maxvote == count[i]) {
    //         std::cout<<names[i]<<std::endl;
    //     }
    // }    
    //max problem
    std::cout<<"Number of elements: ";
    int elements, num, temp = 0;
    std::cin>>elements;
    std::vector<int> arr, negs;
    for (int i = 0; i < elements;i++) {
        std::cout<<"Element "<<i<<": ";
        std::cin>>num;
        arr.push_back(num);
        num = 0;
    }
    for (int i = 0; i < elements;i++) {
        if (arr[i]<0) {
            arr[i]*=-1;
            negs.push_back(arr[i]);
        }
        if (arr[i]>temp) {
            temp = arr[i];
        }
        temp = temp;
    }
    std::cout<<temp<<std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout<<"Executed in "<< duration << "ms"<<std::endl;
    return 0;
}