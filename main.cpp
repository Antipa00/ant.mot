#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>
using namespace std;

   typedef map<string,int> wordmap;
   typedef map<string,int>::const_iterator const_mapiter;

int main (int argc, char *argv[])
{
  wordmap words;
  string curstring;
  bool label = false;
  ifstream infile ("D:/Qt/Praktika_1_Antipin/Test1.txt");
  if( ! infile )
     {
         cerr << "Error in opening file.";
         return -1;
     }
  while ( infile >> curstring )
  {
      words[curstring]++;
  }


  cout << "Words : \n";

         for ( const_mapiter it = words.begin() ; it != words.end(); it++ )
          {
              if ( (*it).second > 1 )
                    {
                        label = true;
                        cout
                            <<         " Occurs "
                            <<         (*it).second
                            <<         " times "
                            <<         " word  :"
                            <<         (*it).first
                            <<         std::endl;
                    }
          }

         if( ! label )
            cout << " do not repeat.\n";

      return 0;
}
