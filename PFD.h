#ifndef PFD_h
#define PFD_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair
#include <vector>  
#include <list>		

using namespace std;

// ------------
// pfd_read_first
// ------------

/**
 * read two ints
 * @param s a string
 * @return an int representing the number of lines remaining
 */
int pfd_read_first (const string& s);

// ------------
// pfd_read_rest
// ------------

/**
 * read multiple ints
 * @param s a string
 * @return a list of ints
 */
list<int> pfd_read_rest (const string& s);

//---------------
// build_adj_list
//---------------

/**
 * build adjacency list of successors
 * @param vals a list of ints containing a node and its dependencies
 * @return the amount of lists that were updated
 */
int build_adj_list (list<int> vals);
// ------------
// pfd_eval
// ------------

/**
 * Find nodes that have no more dependencies
 * @return the next node to work on
 */
int pfd_eval ();

// -------------
// update
// ------------

/**
 * Decrement dependencies
 * @param node the current node we are working on
 * @return the node we are working on
 */
int pfd_update_tasks_list(int node);
// -------------
// pfd_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param l a list of ints representing the order of execution
 */
void pfd_print (ostream& w, list<int> l);

// -------------
// pfd_solve
// -------------

/**
 * Take in a list of dependencies and output execution order
 * @param r an istream
 * @param w an ostream
 */
void pfd_solve (istream& r, ostream& w);

#endif 
// PFD_h