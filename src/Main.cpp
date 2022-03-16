#include <iostream>
#include <sstream>
#include <fstream>
#include <stack>
#include <bits/stdc++.h>
#include "ReadFile.h"

using namespace std;

int main(int x, char** argv) {
    string dpdaFile = argv[1];
    string dpdaInputFile = argv[2];
    string output = argv[3];
    stack<string> stack1;
    ReadFile readFile;
    Dpda dpda;

    outputFile.open(output);
    readFile.readDPDA(dpdaFile);
    readFile.readDPDAinput(dpdaInputFile);

    for(int i=0;i<readFile.dpdaInput.size();i++){
        dpda.rr(readFile.T, stack1, readFile.startEndPoints, readFile.dpdaInput);
        dpda.index2++;
    }
    outputFile.close();
    return 0;
}