#include "input.h"

/**
 * Simply opens the given file, goes through each line, splitting
 *    on the given delimiter, and adds each token to the given set 
 *    of strings
 **/
bool readIDs ( const string& filename, const string& dl, set < string >& v_id ){
  ifstream fin;
  openFileHarsh ( &fin, filename );

  vector < string > fields;
  while ( fline_tr ( &fin, &fields, dl ) ) {
    for ( int i = 0; i < fields.size(); i++ ){
      v_id.insert( fields[i] );
    } 
  }

  return true;
}
