#include "../Libraries/Params/Parameters.h"
#include "../Libraries/Files/IOX.h"

#include "input.h"

int main ( int argc, char** argv ){
  Parameters P; P.Read(argc, argv);

  ifstream fin;
  set < string > IDs;
  openFileHarsh ( &fin, P.get < string > ( "i", "comlist" ) );
  vector < string > fields;
  
  while ( fline_tr ( &fin, &fields, " " ) ){
    for ( int i = 0; i < fields.size(); i++ ){
      readIDs ( fields[i], " ", IDs );
    }
  }  

  set < string >::iterator it_s;
  for ( it_s = IDs.begin(); it_s != IDs.end(); it_s++ ){
    cout << *it_s << endl;
  }
  
  return 1;
}
