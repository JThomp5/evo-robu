#ifndef RPI_INPUT
#define RPI_INPUT

#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

#include "../Libraries/Files/IOX.h"

using namespace std;

/**
 *@fn bool readIDs ( const string& filename, const string& dl, set < const string >& v_id )
 *
 *@param filename Community file to read from
 *@param dl Delimiter for the community file
 *@param v_id Set of current vertex IDs to add to
 **/
bool readIDs ( const string& filename, const string& dl, set < string >& v_id );

#endif
