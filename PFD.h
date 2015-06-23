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

//-------
// build_adj_list
//----------

int build_adj_list (list<int> vals);
// ------------
// pfd_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int pfd_eval (int i, int j);

// -------------
// pfd_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void pfd_print (ostream& w, int i, int j, int v);

// -------------
// pfd_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void pfd_solve (istream& r, ostream& w);


// ------------
// pfd_cycle_length
// -----------
/**
 * @param i an int
 * @return the cycle length of int i
 */
int pfd_cycle_length (int i);

// ------------
// pfd_maxcl
// ------------
/**
 * @param i an int at beginning of range, inclusive
 * @param j an int at end of range, inclusive
 * @return max cycle length from [i, j]
 */
int pfd_maxcl (int i, int j);

#endif 
// PFD_h