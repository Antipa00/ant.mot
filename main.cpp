#include <iostream> //Вводим нужные библиотеки
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
  ifstream infile ("D:/Qt/Praktika_1_Antipin/Test1.txt"); //указываем файл, из которого нужно удалить совпадения
  fstream Output;
  string Outfile = "D:/Qt/Praktika_1_Antipin/Test2.txt"; //указываем файл, куда нужно сохранить результат
  Output.open(Outfile);
  if( ! infile )
     {
         cerr << "Error in opening file."; //в случае ошибки, сообщаем об этом пользователю
         return -1;
     }
  while ( infile >> curstring )
  {
      words[curstring]++; //С помощью цикла подсчитываем количество слов в файле
  }


  cout << "Words : \n";

         for ( const_mapiter it = words.begin() ; it != words.end(); it++ )
          {
              if ( (*it).second > 1 ) //Ищем совпадения в файле
                    {
                        label = true;
                        cout
                            <<         " Occurs "
                            <<         (*it).second
                            <<         " times "
                            <<         " word  :"
                            <<         (*it).first
                            <<         std::endl;
                        Output << (*it).first<<endl; //Записываем совпадения в файл, только уже в единичном варианте

                    }
          }

         if( ! label ){
            cout << " do not repeat.\n"; //в случае отсутствия совпадений выводим данное сообщение
         }
      system("pause");
      return 0;
}
