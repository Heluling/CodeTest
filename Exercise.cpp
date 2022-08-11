#include "TradeStat.h"
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char ** argv){
    map< string, Trade_Stat> SymbolMap;
    //string FileName = "input.csv";
    //string FileName2 = "output.csv";
    char *FileName = argv[1];
    char *FileName2 = argv[2];
    ifstream inFile(FileName);
    ofstream outFile(FileName2);
    string LineStr;
    Trade_Stat Trade_New(0,0,0);
    while(getline(inFile,LineStr)){
        istringstream Readstr(LineStr);
        string str;
        vector<string> StrArray;

        while(getline(Readstr,str,',')){
            StrArray.push_back(str);
        }
        string Symbol = StrArray[1];
        int TimeStamp = atoi(StrArray[0].c_str());
        int Quanty = atoi(StrArray[2].c_str());
        int Price = atoi(StrArray[3].c_str());
        if(SymbolMap.find(StrArray[1]) == SymbolMap.end()){
            Trade_Stat Trade_New = Trade_Stat(TimeStamp,Quanty,Price);
            SymbolMap.insert(make_pair(Symbol,Trade_New));
        }else{
            auto it = SymbolMap.find(StrArray[1]);
            Trade_Stat Trade_s = it->second;
            it->second.Add_Record(TimeStamp,Quanty,Price);
        }
    }
    for(auto iter = SymbolMap.begin(); iter != SymbolMap.end(); iter++){
        Trade_Stat Trade_s = iter->second;
        outFile << iter->first << ',';
        Trade_s.Print(outFile);
    }
    return 0;
}