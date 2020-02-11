//====================================================================================================
//Name: Pranathi Pothukanuri
//File: AssignmentOne.cpp
//====================================================================================================
#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    //create array of alphabet
    string alp = "abcdefghijklmnopqrstuvwxyz";
    char a[26];
    for (int k = 0; k<26; k++)
    {
        a[k] = alp[k];
    }
    
    if (argc == 1)
    {
        cout << "MISSING COMMAND" << endl;
    }
    
    else if (strcmp(argv[1], "-r") == 0)
    {
        if (argc ==3)//If a file name is provided
        {
             ifstream inFile;
             inFile.open(argv[2]);
             string line;
            string changed ="";
            int location;
              while (getline(inFile, line))
            {
                  
                for (int i = 0; i< line.length(); i++)
                {
                    
                    for (int j = 0; j < 26; j++)
                    {
                        if(line[i] == ' ')
                        {
                            changed+= ' ';
                            i++;
                        }
                        else if (ispunct(line[i]))
                        {
                            changed+=line[i];
                            i++;
                        }
                        else if(isupper(line[i]))
                        {
                            if ( tolower(line[i]) == a[j])
                            {
                            location  = j + 13;
                            if (location > 25)
                            {
                                location = location %26;
                            }
                            changed += (toupper(a[location])); 
                            }
                        }
                        else if ( tolower(line[i]) == a[j])
                        {
                            location  = j + 13;
                            if (location > 25)
                            {
                                location = location %26;
                            }
                            changed += (a[location]); 
                        }
                    }
                }  
                      changed += "\n"; 
            }
                  cout << changed ; 
        }
        else// If file name is not provided
        {
            string line;
            string changed = "";
            int location;
            while (getline(cin, line))
            {
                 for (int i = 0; i< line.length(); i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if(line[i] == ' ')
                        {
                            changed+= ' ';
                            i++;
                        }
                        else if (ispunct(line[i]))
                        {
                            changed+=line[i];
                            i++;
                        }
                        else if(isupper(line[i]))
                        {
                            if ( tolower(line[i]) == a[j])
                            {
                            location  = j + 13;
                            if (location > 25)
                            {
                                location = location %26;
                            }
                            changed += (toupper(a[location])); 
                            }
                        }
                        else if ( tolower(line[i]) == a[j])
                        {
                            location  = j + 13;
                            if (location > 25)
                            {
                                location = location %26;
                            }
                            changed += (a[location]); 
                        }
                            
                    }
                }  
                changed += "\n";
            }
                  
            cout << changed ;
        }     
    }
    
    else if (strcmp(argv[1], "-g") == 0)
    {
        srand(time(NULL));
    int taken[26];
    taken[25] = 100;
    int random = rand() % 26;
    string alp = "abcdefghijklmnopqrstuvwxyz";
    string r = "";
    bool contains = false;
    int index = 0;
    map<char,char> caesar;
    while (taken[25] == 100)
    {
        for (int i = 0; i<26 ; i++)
        {
            if (taken[i] == random)
                contains = true;
        }
        if (!contains)
        {
            if (!(alp[random]== alp.at(index)))
            {
            taken[index] = random;
            index = index+1;
            r+= alp[random];
            }
            
        }
            random = rand() % 26;
            contains = false;
    }
    
    for (int k = 0; k<alp.length(); k++)
            {
                caesar.insert({alp.at(k),r.at(k)});
            }
    for (auto itr = caesar.begin(); itr != caesar.end(); ++itr) { 
        cout << itr->first << itr->second << '\n';
       }
    }
    
    
    else if (strcmp(argv[1], "-e") == 0)
    {
        if (argc == 2)// no dictionary given
        {
            cout << "NO GIVEN DICTIONARY"<<endl;
        }
        
        else if (argc == 3)// dictionary given but no file
        {
            ifstream inFile;
                inFile.open(argv[2]);
            
            map<char, char> en;
            string outputen;
            char letter;
            string line;
            string l;
            int index = 0;
            char n[26];
            int nindex = 0;
            
                if(inFile)
                {
                     while(getline(inFile, line))
                      {
                         
                         for (int j = 0; j < 26 ; j++)
                         {
                             if (n[j] == line[1])
                             {
                                 cout << "DUPLICATE CIPHERTEXT " << n[j]<< endl;   
                              exit(0);
                             }
                         }
                         
                          if (line.length() != 2)
                          {
                              cout<< "FORMATTING ERROR " << line<< endl;
                              exit(0);
                              
                          }
                         
                         else if (line[0] == line[1])
                         {
                          cout << "MAPPING ERROR " << line[0]<< endl;  
                             exit(0);
                          
                         }
                         
                         else if (line[0] != a[index])
                         {
                            cout << "MISSING LETTER " << a[index]<< endl;   
                              exit(0);
                         }
                         
                         
                        
                          else 
                          {
                          en.insert({line[0], line[1]});
                              n[nindex] = line[1];
                              nindex++;
                              
                          }
                         index++;
                      }
                    while (getline(cin, l))
                    {
                         for (int i = 0; i< l.length(); i++)
                        {
                             letter = l[i];
                             for (auto j : en)
                                {
                                if (letter == j.first)
                                   {
                                        outputen += j.second;
                                    }
                                else if (isupper(letter))
                                    {
                                if (tolower(letter) == j.first)
                                    {
                                        outputen += toupper(j.second);
                                    }
                
                                    }        
                                 else if (ispunct(letter))
                                   {
                                 outputen+= letter;  
                                 break;
                                    }
                             else if (letter ==  ' ')
                            {
                                 outputen += " ";  
                                 break;
                            }
                    }
                    }
                    outputen += "\n";
                 }
                    cout<<outputen;
                    
                }
                else
                {
                    cout << argv[2] << " DICTIONARY COULD NOT BE OPENED" << endl;
                }
           
        }
        
        else if (argc == 4)//dictionary and file given
        {
            ifstream inFile;
             inFile.open(argv[3]);
            ifstream inF;
            inF.open(argv[2]);
            string outputen;
            string line;
            char letter;
            string l;
            int index = 0;
            int nindex = 0;
            char n[26];
            map<char, char> e;
            if(inFile)
            {
                if(inF)
                {
                     while(getline(inF, line))
                      {
                         
                         for (int j = 0; j < 26 ; j++)
                         {
                             if (n[j] == line[1])
                             {
                                 cout << "DUPLICATE CIPHERTEXT " << n[j]<< endl;   
                              exit(0);
                             }
                         }
                         
                          if (line.length() != 2)
                          {
                              cout<< "FORMATTING ERROR " << line<< endl;
                              exit(0);
                              
                          }
                         
                         else if (line[0] == line[1])
                         {
                          cout << "MAPPING ERROR " << line[0]<< endl;  
                             exit(0);
                          
                         }
                         
                         else if (line[0] != a[index])
                         {
                            cout << "MISSING LETTER " << a[index]<< endl;   
                              exit(0);
                         }
                          else 
                          {
                          e.insert({line[0], line[1]});
                              n[nindex] = line[1];
                              nindex++;
                              
                          }
                         index++;
                      }
                    while (getline(inFile, l))
                    {
                         for (int i = 0; i< l.length(); i++)
                        {
                             letter = l[i];
                             for (auto j : e)
                                {
                                if (letter == j.first)
                                   {
                                        outputen += j.second;
                                    }
                                else if (isupper(letter))
                                    {
                                        if (tolower(letter) == j.first)
                                            {
                                                outputen += toupper(j.second);
                                            }
                                    }        
                                 else if (isalpha(letter) == 0)
                                 {
                                     outputen+= letter;  
                                     break;
                                 }         
                    }
                    }
                    outputen += "\n";
                 }
                    cout<<outputen;
                    
                }
                
                 else
                {
                    cout << argv[2] << " DICTIONARY COULD NOT BE OPENED" << endl;
                }
            }
            else
            {
                cout << argv[3] << " FILE COULD NOT BE OPENED"<< endl;
            }
        }
        
        else
        {
            cout << "TOO MANY ARGUMENTS"<<endl;
        }
    }
    
    else if (strcmp(argv[1], "-d") == 0)
    {
        if (argc == 2)// no dictionary given
        {
            cout << "NO GIVEN DICTIONARY"<<endl;
        }
        
        else if (argc == 3)// dictionary given but no file
        {
            ifstream inFile;
                inFile.open(argv[2]);
            
            map<char, char> de;
            string outputde;
            char letter;
            string line;
            string l;
            int index = 0;
            char n[26];
            int nindex = 0;
            
                if(inFile)
                {
                     while(getline(inFile, line))
                      {
                         
                         for (int j = 0; j < 26 ; j++)
                         {
                             if (n[j] == line[1])
                             {
                                 cout << "DUPLICATE CIPHERTEXT " << n[j]<< endl;   
                              exit(0);
                             }
                         }
                         
                          if (line.length() != 2)
                          {
                              cout<< "FORMATTING ERROR " << line<< endl;
                              exit(0);
                              
                          }
                         
                         else if (line[0] == line[1])
                         {
                          cout << "MAPPING ERROR " << line[0]<< endl;  
                             exit(0);
                          
                         }
                         
                         else if (line[0] != a[index])
                         {
                            cout << "MISSING LETTER " << a[index]<< endl;   
                              exit(0);
                         }
                         
                         
                        
                          else 
                          {
                          de.insert({line[1], line[0]});
                              n[nindex] = line[1];
                              nindex++;
                              
                          }
                         index++;
                      }
                    while (getline(cin, l))
                    {
                         for (int i = 0; i< l.length(); i++)
                        {
                             letter = l[i];
                             for (auto j : de)
                                {
                                if (letter == j.first)
                                   {
                                        outputde += j.second;
                                    }
                                else if (isupper(letter))
                                    {
                                        if (tolower(letter) == j.first)
                                            {
                                                outputde += toupper(j.second);
                                            }
                                    }        
                                 else if (isalpha(letter) == 0)
                                 {
                                     outputde+= letter;  
                                     break;
                                 }   
                    }
                    }
                    outputde += "\n";
                 }
                    cout<<outputde;
                    
                }
                else
                {
                    cout << argv[2] << " DICTIONARY COULD NOT BE OPENED" << endl;
                }
           
        }
        
        else if (argc == 4)//dictionary and file given
        {
            ifstream inFile;
             inFile.open(argv[3]);
            ifstream inF;
            inF.open(argv[2]);
            string outputde;
            string line;
            char letter;
            string l;
            int index = 0;
            int nindex = 0;
            char n[26];
            map<char, char> d;
            if(inFile)
            {
                if(inF)
                {
                     while(getline(inF, line))
                      {
                         
                         for (int j = 0; j < 26 ; j++)
                         {
                             if (n[j] == line[1])
                             {
                                 cout << "DUPLICATE CIPHERTEXT " << n[j]<< endl;   
                              exit(0);
                             }
                         }
                         
                          if (line.length() != 2)
                          {
                              cout<< "FORMATTING ERROR " << line<< endl;
                              exit(0);
                              
                          }
                         
                         else if (line[0] == line[1])
                         {
                          cout << "MAPPING ERROR " << line[0]<< endl;  
                             exit(0);
                          
                         }
                         
                         else if (line[0] != a[index])
                         {
                            cout << "MISSING LETTER " << a[index]<< endl;   
                              exit(0);
                         }
                          else 
                          {
                          d.insert({line[1], line[0]});
                              n[nindex] = line[1];
                              nindex++;
                              
                          }
                         index++;
                      }
                    while (getline(inFile, l))
                    {
                         for (int i = 0; i< l.length(); i++)
                        {
                             letter = l[i];
                             for (auto j : d)
                                {
                                if (letter == j.first)
                                   {
                                        outputde += j.second;
                                    }
                                else if (isupper(letter))
                                    {
                                        if (tolower(letter) == j.first)
                                            {
                                                outputde += toupper(j.second);
                                            }
                                    }        
                                 else if (isalpha(letter) == 0)
                                 {
                                     outputde+= letter;  
                                     break;
                                 }         
                    }
                    }
                    outputde += "\n";
                 }
                    cout<<outputde;
                    
                }
                
                 else
                {
                    cout << argv[2] << " DICTIONARY COULD NOT BE OPENED" << endl;
                }
            }
            else
            {
                cout << argv[3] << " FILE COULD NOT BE OPENED"<< endl;
            }
        }
        
        else
        {
            cout << "TOO MANY ARGUMENTS"<<endl;
        }
    }
}
