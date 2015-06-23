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
vector<list<int>> adjacency_list = {{},{},{},{},{},{}}; //empty lists for test harness
priority_queue<int, vector<int>, greater<int>> pri_q; //min priority queue
// ------------
// pfd_read_first
// ------------

/* Takes in first string
   Sets up data structures
   Returns how many lines left to read
*/
int pfd_read_first (const string& s) {
    assert(!s.empty());

    istringstream sin(s);
    int i;
    int j;

    sin >> i >> j;
    tasks.resize(i + 1);
    tasks[0] = -1; //not using 0 slot

    for(int k = 1; k < i+1; k++){
        tasks[k] = 0;
    }

    assert(j >= 0);
    return j;}

// ------------
// pfd_read_rest
// ------------
/*  Takes in a string  of ints
    Returns a list of ints representing the string
*/

list<int> pfd_read_rest (const string& s) {
    assert(!s.empty());

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
    assert(!lst.empty());
    return lst;}

// ------------
// build_adj_list
// ------------

/*  Takes in a list of ints
    Builds adjacency list so each node holds its successors
    Updates dependency vector with number of dependencies given
    returns number of lists updated
*/
int build_adj_list (list<int> vals){
    assert(!vals.empty());
    int i = 0;
    list<int>::iterator p = vals.begin();

    int task = *p;
    ++p;
    tasks[task] += *p;
    ++p;

    while(p != vals.end()){
        adjacency_list[*p].push_back(task);
        ++i;
        ++p;}
    assert(i >= 0);
    return i;}

// ------------
// pfd_eval
// ------------

/*  Checks the depency list for tasks that are no longer waiting
    Enqueues them in the priority queue
    Returns top of the queue or -1 if the queue is empty
*/
int pfd_eval (void) {
    assert(!tasks.empty());
    for(unsigned int i = 1; i < tasks.size(); ++i){
        if (tasks[i] == 0){
            pri_q.push(i);
            tasks[i] = -1;
        }
    }

    if(!pri_q.empty()){
        int q = pri_q.top();
        pri_q.pop();
        assert(q > 0);
        return q;}
    else{
        return -1;}}

      
// -------------
// pfd_print
// -------------

/*  Takes in a ostream and a list of ints
    Builds a string from the list
    Puts string in ostream
*/

void pfd_print (ostream& w, list<int> order) {
    assert(!order.empty());
    list<int>::iterator i = order.begin();
    list<int>::iterator e = order.end();
    string theString = "";
    
    while (i != e){
        if ((next(i)) != e){
            theString.append(to_string(*i).append(" "));}
        else{
            theString.append(to_string(*i));}
        i++;
    }
    w  << theString.append("\n");}

// ---------------
// pfd_update_tasks_list
// ---------------

/*  Takes in an int representing the current node to work on
    Decrements any tasks that are dependent on this node
    Sets a node to -1 after it runs
    Returns the node worked on
    Returns -1 for unworkable node
*/
int pfd_update_tasks_list(int node){
    if(node < 1 ||(unsigned) node > adjacency_list.size()){return -1;}

    list<int>::iterator p = adjacency_list[node].begin();
    
    while (p != adjacency_list[node].end()){
        tasks[*p] -= 1;
        ++p;
    }
    assert(node > 0);
    return node;}


// -------------
// pfd_solve
// -------------

/*  Takes in an istream and an ostream
    istream represents lines of nodes and their dependencies
    ostream will contain executable order of nodes 
    such that no node runs before one it is dependent on
*/
void pfd_solve (istream& r, ostream& w) {
    string s;

    getline(r,s);
    assert(!s.empty());

    int remaining_lines = pfd_read_first(s);
    adjacency_list.resize(tasks.size());

    assert(tasks.size() > 0);

    while (remaining_lines > 0) {
        getline(r, s);
        build_adj_list(pfd_read_rest(s));
        remaining_lines -= 1;}

    assert(remaining_lines == 0);

    list<int> order;
    int k = (pfd_update_tasks_list(pfd_eval()));
    while(k != -1){
        
        order.push_back(k);
        k =(pfd_update_tasks_list(pfd_eval()));
    }
    pfd_print(w, order);}