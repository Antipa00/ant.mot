#include <iostream> //вводим необходимые библиотеки
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
  ifstream infile ("D:/Qt/Praktika_1_Antipin/Test1.txt"); //Открываем исходный файл, в котором нужно найти и удалить совпадения
  if( ! infile )
     {
         cerr << "Error in opening file."; //В случае ошибки выводим это для пользовал=теля
         return -1;
     }
  while ( infile >> curstring )
  {
      words[curstring]++;
  }


  cout << "Words : \n";

         for ( const_mapiter it = words.begin() ; it != words.end(); it++ )
          {
              if ( (*it).second > 1 )  //проверяем наличие совпадений в файле
                    {
                        label = true;
                        cout //в случаи нахождения совпадений выводим их пользователю
                            <<         " Occurs "
                            <<         (*it).second
                            <<         " times "
                            <<         " word  :"
                            <<         (*it).first
                            <<         std::endl;
                    }
          }

         if( ! label ) // в случае, если совпадений нет, выводим это пользователю
            cout << " do not repeat.\n";

      return 0;
}
