/**
 *remove_id : Program takes as input a list of filenames
 *    ( themselves in a file ) holding temporal community
 *    structures ( one time step per file ). It chooses
 *
 *@param -i Input file 
 *          (should list all community files, space separated)
 *@param -r Ratio of vertices to remove from the communities.
 *
 *@result Creates a '.rem' file for each community file listed in
 *           the input, consisting of the same communities with
 *           the random vertex IDs removed.
 *
 *@author James Thompson
 **/

#include "../Libraries/Params/Parameters.h"
#include "../Libraries/Files/IOX.h"
#include "../Libraries/Random/Wrappers.h"

#include "input.h"

/**
 * Insertion point for program
 */
int main ( int argc, char** argv ){
  Parameters P; P.Read(argc, argv); //Gets command line parameters

  // Reads in the IDs from each community file independently
  ifstream fin;
  set < string > IDs;
  openFileHarsh ( &fin, P.get < string > ( "i", "comlist" ) );
  vector < string > fields;
  
  while ( fline_tr ( &fin, &fields, " " ) ){
    for ( unsigned int i = 0; i < fields.size(); i++ ){
      readIDs ( fields[i], " ", IDs );
    }
  }  
  
  fin.close();

  // Chooses the vertex IDs to remove
  set < string > to_remove = get_random_subset (IDs, P.get < double > ( "r", 0.1 ) * IDs.size() );
  
  // Goes through each community file again and removes the chosen
  //     vertex IDs.
  openFileHarsh ( &fin, P.get < string > ( "i", "comlist" ) );  
  while ( fline_tr ( &fin, &fields, " " ) ){
    for ( unsigned int i = 0; i < fields.size(); i++ ){
      removeIDs ( fields[i], fields[i]+".rem", to_remove );
    }
  }  
  
  fin.close();
  
  return 1;
}


