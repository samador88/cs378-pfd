#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

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
    tasks[0] = -1; //not using 0 slot
    for(int k = 1; k < i+1; k++){
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

// ----------
// build_adj_list
// ------------
int build_adj_list (list<int> vals){
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
        return i;}



// ------------
// pfd_eval
// ------------

int pfd_eval (void) {
    //check for tasks with no more dependencies, and push onto pq
    for(unsigned int i = 1; i < tasks.size(); ++i){
        if (tasks[i] == 0){
            pri_q.push(i);
            tasks[i] = -1;
        }
    }
    if(!pri_q.empty()){
        int q = pri_q.top();
        pri_q.pop();
        return q;}
    else{
        return -1;}
}

      
// -------------
// pfd_print
// -------------

void pfd_print (ostream& w, list<int> order) {
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

int pfd_update_tasks_list(int node){
    if(node == -1 ){//|| adjacency_list[node].empty())
        return -1;}
    list<int>::iterator p = adjacency_list[node].begin();
    while (p != adjacency_list[node].end()){
        tasks[*p] -= 1;
        ++p;
    }
    return node;
}


// -------------
// pfd_solve
// -------------

void pfd_solve (istream& r, ostream& w) {
    string s;
    getline(r,s);
    int remaining_lines = pfd_read_first(s);
    adjacency_list.resize(tasks.size());

    while (remaining_lines > 0) {
        getline(r, s);
        build_adj_list(pfd_read_rest(s));
        remaining_lines -= 1;}

    list<int> order;
    int k = (pfd_update_tasks_list(pfd_eval()));
    while(k != -1){
        
        order.push_back(k);
        k =(pfd_update_tasks_list(pfd_eval()));
    }
    pfd_print(w, order);}
// -------
// defines
// -------


// --------
// includes
// --------



// ----
// main
// ----

int main () {
    using namespace std;
    pfd_solve(cin, cout);
    return 0;}

