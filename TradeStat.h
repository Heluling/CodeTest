#include <fstream>
#include <iostream>

class Trade_Stat{
public:
    Trade_Stat(int TimeStamp,int Quantity,int Price){
        Last_TimeStamp = TimeStamp;
        Max_TimeStamp_Gap = 0;
        Total_Volumn = Quantity;
        Total_Amount = Quantity * Price;
        Max_Price = Price;   
    }
    void Add_Record(int TimeStamp, int Quantity, int Price){
        if(TimeStamp - Last_TimeStamp > Max_TimeStamp_Gap) Max_TimeStamp_Gap = TimeStamp - Last_TimeStamp;
        Last_TimeStamp = TimeStamp;
        Total_Volumn += Quantity;
        Total_Amount += Quantity * Price;
        if(Price > Max_Price) Max_Price = Price;
    }
    void Print(std::ofstream& out){
        out << Max_TimeStamp_Gap << ',' << Total_Volumn << ',' << int(Total_Amount/Total_Volumn) << ',' << Max_Price << std::endl;
    }

private:
    int Last_TimeStamp;
    int Max_TimeStamp_Gap;
    int Total_Volumn;
    int Total_Amount;
    int Max_Price;
};