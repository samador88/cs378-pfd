// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <vector>   //resize
#include <list>
#include <queue>
#include "PFD.h"

using namespace std;

vector<int> tasks(12); //contains number of dependencies left for job i
vector<list<int>> adjacency_list = {{},{},{},{},{},{}};
priority_queue<int, vector<int>, greater<int>> pri_q;
// ------------
// pfd_read_first
// ------------

int pfd_read_first (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    tasks.resize(i + 1);
    for(int k = 0; k < i+1; k++){
        tasks[k] = 0;
    }
    return j;}

// ------------
// pfd_read_rest
// ------------

list<int> pfd_read_rest (const string& s) {
    list<int> lst;
    istringstream sin(s);
    int tasknumber;
    int numdepend;
    sin >> tasknumber >> numdepend;
    lst.push_back(tasknumber);
    lst.push_back(numdepend);
    for(int i = 0; i < numdepend; ++i){
        int j;
        sin >> j;
        lst.push_back(j);
    }
    return lst;}
/*    tasks[tasknumber] = numdepend;

    for (int i = 0; i < numdepend; ++i){
        sin >> j;

    }
    tasks.resize(i);
    return j;}
*/
int build_adj_list (list<int> vals){
    int i = 0;
    list<int>::iterator p = vals.begin();
    int task = *p;
    ++++p;
    while(p != vals.end()){
        adjacency_list[*p].push_back(task);
        tasks[*p] += 1;
        ++i;
        ++p;}
        return i;}

void create_adj_list (){ //place holder function, absorb into main 
    adjacency_list.resize(tasks.size());
}

// ------------
// pfd_eval
// ------------
/*
int pfd_cycle_length(int i) {
    assert(i > 0);
    #ifdef CACHE
    int current = i;
    if (current < 1000000 && arr[current] != 0)
    {
     return arr[i];
    }
    #endif
    int c = 1;
    while (i > 1) 
    {
        #ifdef CACHE
        if (i < 1000000 && arr[i] != 0)
        {
            arr[current] = arr[i] + c - 1;
            return (arr[i] + c-1);       //-1 because one was already counted at initialization
        }    
        #endif
        if((i % 2) == 0)
            i = (i / 2);
        else
            i = (3 * i) + 1;
        ++c;
    }
    assert(c > 0);
    #ifdef CACHE
    arr[current] = c;
    #endif
    return c;
}


int pfd_maxcl(int i, int j) {
    assert(i > 0 && j > 0);
    assert(i < 1000000 && j < 1000000);
    int max = 0;
    int n;
    while(i <= j) 
    {
       n = pfd_cycle_length(i);
       if (n > max)
           {
               max = n;
           }
       ++i;
    }
    assert(max > 0);
    return max;
}


int pfd_eval (int i, int j) {
    // <your code>
    assert(i > 0);
    assert(j > 0);
    if (i <= j)
    {
        return pfd_maxcl(i, j);
    }
    else
       return pfd_maxcl(j, i);    //in case numbers are given backwards like someone on piazza said
    return 1;
}

        
// -------------
// pfd_print
// -------------

void pfd_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// pfd_solve
// -------------

void pfd_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = pfd_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = pfd_eval(i, j);
        pfd_print(w, i, j, v);}}
        */