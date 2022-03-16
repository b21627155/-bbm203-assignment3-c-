//
// Created by Mustafa on 18.12.2021.
//

#ifndef ASSINGMENT3_DPDA_H
#define ASSINGMENT3_DPDA_H

#endif //ASSINGMENT3_DPDA_H
#include "WriteFile.h"
using namespace std;

class Dpda{

public:
string tut;
int index = 0;
int index2 = 0;
int sayac =1;

void printStack(stack<string> w) {

    string temp;
    if (w.empty()) {
        return;
    }
    temp = w.top();
    w.pop();
    printStack(w);

    outputFile << temp;
    outputFile << " ";
    w.push(temp);
}

void ss(vector<vector<string>> x, stack<string> y, vector<string> z, vector<vector<string>> m) {

    stack<string> temp;
    for (int h = 0; h < x.size(); h++) {
        if (tut == x[h][0] and (x[h][1] == m[index2][index] or x[h][1] == "e")) {
            if (x[h][1] == m[index2][index]) {
                if (x[h][4] != "e") {
                    y.push(x[h][4]);
                }
                if (x[h][2] != "e") {
                    y.pop();
                }
                outputFile << x[h][0] << "," << x[h][1] << "," << x[h][2];
                outputFile << " => ";
                outputFile << x[h][3] << "," << x[h][4];
                outputFile << " ";
                outputFile << "[STACK]:";
                printStack(y);
                outputFile << "\n";
                index++;
            }
            else{
                if (x[h][4] != "e") {
                    y.push(x[h][4]);
                }
                if (x[h][2] != "e") {
                    y.pop();
                }
                outputFile << x[h][0] << "," << x[h][1] << "," << x[h][2];
                outputFile << " => ";
                outputFile << x[h][3] << "," << x[h][4];
                outputFile << " ";
                outputFile << "[STACK]:";
                printStack(y);
                outputFile << "\n";
            }
            tut = x[h][3];
            break;
        }
    }
    if( index == m[index2].size() or sayac == x.size()+10){
        if (("[" + tut + "]" == z[1] or "[" + tut + "]" == z[2]) and (y.top() == "$" or y.empty())) {
            outputFile << "ACCEPT" << "\n\n";
        }
        else {
            for (int h = 0; h < x.size(); h++) {
                if (tut == x[h][0] and (x[h][1] == m[index2][index] or x[h][1] == "e")) {
                    if (x[h][4] != "e") {
                        y.push(x[h][4]);
                    }
                    if (x[h][2] != "e") {
                        y.pop();
                    }
                    outputFile << x[h][0] << "," << x[h][1] << "," << x[h][2];
                    outputFile << " => ";
                    outputFile << x[h][3] << "," << x[h][4];
                    outputFile << " ";
                    outputFile << "[STACK]:";
                    printStack(y);
                    outputFile << "\n";
                    tut = x[h][3];
                    break;
                }
            }
            if (("[" + tut + "]" == z[1] or "[" + tut + "]" == z[2]) and (y.top() == "$" or y.empty())) {
                outputFile << "ACCEPT" << "\n\n";
            }
            else {
                outputFile << "REJECT" << "\n\n";
            }
        }
        return;
    }
    sayac++;
    ss(x, y, z, m);
}

void rr(vector<vector<string>> x, stack<string> y, vector<string> z, vector<vector<string>> m) {

    for (int i = 0; i < x.size(); i++) {
        if (z[0] == "(" + x[i][0] + ")") {
            y.push(x[i][4]);
            outputFile << x[i][0] << "," << x[i][1] << "," << x[i][2];
            outputFile << " => ";
            outputFile << x[i][3] << "," << x[i][4];
            outputFile << " ";
            outputFile << "[STACK]:" << y.top();
            outputFile << "\n";
            tut = x[i][3];
            ss(x, y, z, m);
        }
    }
    index=0;
}
};

