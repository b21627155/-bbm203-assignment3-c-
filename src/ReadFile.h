// Created by Mustafa on 17.12.2021.


#ifndef ASSINGMENT3_READFILE_H
#define ASSINGMENT3_READFILE_H

#endif //ASSINGMENT3_READFILE_H
#include "Dpda.h"
using namespace std;

class ReadFile{
public:
    string line;
    vector<string> Q; //state of Q
    vector<string> startEndPoints; // start point and finish points
    vector<string> A; // input alphabet
    vector<string> Z; // stack alphabet
    vector<vector<string>> T; // transition rule
    vector<vector<string>> dpdaInput; // input for stack

    void readDPDA(string input) {
        ifstream inputFile(input);
        while (getline(inputFile, line)) {
            string y;
            y = line[0];
            if(y == "Q"){
                string qSet = line.substr(2,line.find(' ')-1);
                string q = line.substr(line.find('>')+2);
                startEndPoints.push_back(q.substr(0,q.find(',')));
                startEndPoints.push_back(q.substr(5,q.find(',')));
                startEndPoints.push_back(q.substr(10));
                for(int x=0; x<qSet.length();x+=3){
                    Q.push_back(qSet.substr(x,qSet.find(',')));
                }
            }
            else if(y == "A"){
                string aSet = line.substr(2);
                for(int x=0; x<aSet.length();x+=2){
                    A.push_back(aSet.substr(x,aSet.find(',')));
                }
            }
            else if(y == "Z"){
                string zSet = line.substr(2);
                for(int x=0; x<zSet.length();x+=2){
                    Z.push_back(zSet.substr(x,zSet.find(',')));
                }
            }
            else if(y == "T"){
                vector<string> temp;
                string tSet = line.substr(2);
                string sub,sub1;
                sub=tSet;
                for(int i = 0;i<tSet.length()-6;i++){
                    temp.push_back(sub.substr(0,sub.find(',')));
                    sub1 = sub.substr(sub.find(',')+1);
                    sub = sub1;
                }
                if(count(Q.begin(), Q.end(), temp[0]) == false or count(Q.begin(), Q.end(), temp[3]) == false){
                    outputFile << "Error [1]:DPDA description is invalid!";
                    exit(0);
                }
                if(count(A.begin(), A.end(), temp[1]) == false and temp[1] != "e"){
                    outputFile << "Error [1]:DPDA description is invalid!";
                    exit(0);
                }

                T.push_back(temp);
                temp.clear();
            }
        }
        inputFile.close();
    }
    void readDPDAinput(string input) {
        ifstream inputFile(input);
        while (getline(inputFile, line)) {
            vector<string> temp;
            string sub,sub1;
            sub=line;
            for(char i : line){
                string y;
                y = i;
                if(y==","){
                    continue;
                }
                else{
                    temp.push_back(sub.substr(0, sub.find(',')));
                    sub1 = sub.substr(sub.find(',') + 1);
                    sub = sub1;
                }
            }
            if(!temp.empty()){
                dpdaInput.push_back(temp);
            }
            temp.clear();
        }
        inputFile.close();
    }
};