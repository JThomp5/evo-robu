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
    for ( unsigned int i = 0; i < fields.size(); i++ ){
      v_id.insert( fields[i] );
    } 
  }

  return true;
}

/**
 * Opens the given file and copies the contents to output_file, 
 *    replacing any token that matches a string in v_id with 
 *    "UNKNOWN".
 */
bool removeIDs ( const string& filename, const string& output_file, const set < string >& v_id ){
  ifstream fin; ofstream fout ( output_file.c_str() );
  openFileHarsh ( &fin, filename );
  
  vector < string > fields;
  
  while ( fline_tr ( &fin, &fields, " " ) ){
    for ( unsigned int i = 0; i < fields.size(); i++ ){
      if ( v_id.find ( fields[i] ) != v_id.end() ){
	fout << "UNKNOWN";
      } else {
	fout << fields[i];
      }

      if ( i != fields.size() - 1 ) 
	fout << " ";
      else
	fout << endl;
    }
  }
  
  fout.close();

  return true;
}
