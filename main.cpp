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
  string input;
  if(argc==2){
      input = argv[1];
  }
  else {
      cout<<"Enter file read ";  //указываем файл, из которого нужно удалить совпадения
      cin>>input;
  }
  ifstream fileToRead;
  fileToRead.open(input);
  string Output;
  if(argc==2){
      Output = argv[1];
  }
  else {
      cout<<"Enter file path "; //указываем файл, куда нужно сохранить результат
      cin>>Output;
  }
  fstream fileToSave;
  fileToSave.open(Output);
  if( ! fileToRead )
     {
         cerr << "Error in opening file."; //в случае ошибки, сообщаем об этом пользователю
         return -1;
     }
  while ( fileToRead >> curstring )
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
                        fileToSave << (*it).first<<endl; //Записываем совпадения в файл, только уже в единичном варианте

                    }
          }

         if( ! label ){
            cout << " do not repeat.\n"; //в случае отсутствия совпадений выводим данное сообщение
         }
      system("pause");
      return 0;
}

