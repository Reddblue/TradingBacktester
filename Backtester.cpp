#include <iostream>
#include <time.h>
using namespace std;

int trades;
long double sbal;
long double bal;
int wr;
int lvg;
double mo;
double lo;
double tp;
double sl;
double win;
double loss;
double rwin;
double rloss;
double liq;
double orderfee;
int wins;
int ls;
int rando;
bool liquid;
int counter;

void trade(int n){
    if(wr >= rando){
        sbal = bal;
        rwin = (sbal * ((tp*lvg/100)));
        orderfee = rwin/7.5;
        if(orderfee < 1){
            orderfee = 1;
        }
        win = rwin-(rwin*lo*2);
        bal += win-orderfee;
        cout << "TRADE #" << n+1 << " |W| PNL: +" << win << " BAL: " << bal << endl;
        wins++;
    }
    else if(rando > wr){
        sbal = bal;
        rloss = (sbal * ((sl*lvg)/100));
        rloss = -rloss;
        orderfee = rloss/7.5;
        loss = rloss+(rloss*(mo*2));
        liq = bal+loss-orderfee;
        if(liq <= 1){
            bal = -bal;
            cout << "LIQUIDATED | TRADE #" << n+1 << " |L| PNL: " << sbal << " BAL: " << bal << endl;
            liquid = true;
        }
        else {
            bal += loss;
            cout << "TRADE #" << n+1 << " |L| PNL: " << loss << " BAL: " << bal << endl;
            liquid = false;
            ls++;
        }
    }

}

int main(){
    srand(time(0));
    cout << "How many trades? ";
    cin >> trades;
    cout << trades << endl;
    cout << "Starting balance? ";
    cin >> bal;
    cout << bal << endl;
    cout << "Winrate %? ";
    cin >> wr;
    cout << wr << endl;
    cout << "What leverage? ";
    cin >> lvg;
    cout << lvg << endl;
    cout << "Take profit %? ";
    cin >> tp;
    cout << tp << endl;
    cout << "Stop loss %? ";
    cin >> sl;
    cout << sl << endl;
    cout << "Market order fee %? ";
    cin >> mo;
    cout << mo << endl;
    cout << "Limit order fee %? ";
    cin >> lo;
    cout << lo << endl;

    cout << "Processing..\n\n";
    counter = 0;
    liquid = false;
    
    do{
        if(liquid == true){
            break;
        }
        else {
            rando = rand() % 100 +1;
            trade(counter);
            counter++;
        }
    }
    while((counter < trades) || (liquid = false));
    
    cout << "Final balance: " << bal << endl;
    cout << "Wins: " << wins << " | Losses: " << ls << endl;

    return 0;
}