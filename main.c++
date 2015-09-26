// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout
#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <map>

using namespace std;

 //   map<pair<int, int>,int> metaCache;

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    int max = 0;
    int num;
    if (i > j)
        swap(i, j);
    for(int k = i;k <= j; ++k){

        int count = 1;
        num = k;
        while((num != 1) && (num > 0)){
            if ((num % 2) == 0){
                num = (num >> 1);
                ++count;
            }
            else{
                num += (num >> 1) + 1;
                count += 2;
            }
        }
        if (count > max)
            max = count;

    }
    return max;
}

// ------------
// round calculator
// ------------

void round_number_thousand(int start, int end){
    while (start <= ((end/1000) * 1000) - 1){
        cout <<"Pair"<<start<<"-"<<((start/1000) + 1)*1000<<endl;
        start = ((start/1000) + 1) * 1000;
    }
   if (start <= end)
        cout <<"Pair"<<start<<"-"<<end<<endl;
}

// ------------
// range cache
// ------------

int max_value_range(pair<int, int> pair_range){
    return 0;
}

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    ostringstream output;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        output << i << " " << j << " " << v << endl;
    }
    cout << output.str();
    }

// ----
// main
// ----

int main () {


//    collatz_solve(cin, cout);
//    for (int i=0; i<=999000; i += 1000){
//        cout << i << " " << (i + 1000)<< " " << collatz_eval(i, (i + 1000)) << endl;
//        }
    return 0;}
