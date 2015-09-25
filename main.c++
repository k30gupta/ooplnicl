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

using namespace std;
// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

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
        while(num != 1){
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
    collatz_solve(cin, cout);
    return 0;}
