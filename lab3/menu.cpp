#include "menu.hpp"
#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

void terminal::file_read()
{
  file = new fstream();
  terminal_data = new fstream();

  string name;

  cout << "Enter file name: ";
  getline(cin, name);

  file->open(name, ios_base::out);
  file->close();
  file->open(name);


  terminal_data->open("terminal_data.txt", ios_base::out);
  terminal_data->close();
  terminal_data->open("terminal_data.txt");

  while (!file->eof()) {
    string str;
    getline(*file, str);
    *terminal_data << str << endl;
  }
}

void terminal::input()
{
  terminal_data->clear();
  terminal_data->seekp(0, ios_base::end);  //указатель в конец файла

  cout << "Enter the string: ";

  string user_string;
  cin >> user_string;

  *terminal_data << user_string << endl;
}

void terminal::output()
{
  terminal_data->clear();
  terminal_data->seekp(0, ios_base::beg); //указатель в начало файла

  while (!terminal_data->eof()) {
    string str;
    getline(*terminal_data, str);
    cout << str << endl;
  }
}

void terminal::file_output()
{
  file->clear();
  file->seekp(0, ios_base::beg); //указатель в начало файла

  while (!file->eof()) {
    string str;
    getline(*file, str);
    cout << str << endl;
  }
}

void terminal::search()
{
  terminal_data->clear();
  terminal_data->seekp(0, ios_base::beg);

  string str_user;
  cout << "Enter the search word: ";
  cin >> str_user;
  cout << endl;

  int count = 0;    //кол-во совпадений
  int strNumber = 0;      //номер строки

  while (!terminal_data->eof()) {
    string lookup;

    getline(*terminal_data, lookup);
    strNumber++;

    long unsigned int i = 0;

    for (i = lookup.find(str_user, i++); i != string::npos;
     i = lookup.find(str_user, i + 1)) {
       cout << "line: " << strNumber << endl;
       cout << "position: " << i << endl;
       count++;
    }
  }
  cout << endl;
  cout << "______________________" << endl;
  cout << "matches found: " << count << endl;
}

void terminal::delete_word()
{
  terminal_data->clear();
  terminal_data->seekp(0, ios_base::beg);

  fstream temp;
  temp.open("delete_buf.txt");

  string str_user;
  cout << "Enter the deleting word: ";
  cin >> str_user;
  cout << endl;

  int count = 0;    //кол-во совпадений

  while (!terminal_data->eof()) {
    string lookup;

    getline(*terminal_data, lookup);

    long unsigned int i = 0;

    for (i = lookup.find(str_user, i++); i != string::npos;
     i = lookup.find(str_user, i + 1)) {
       lookup.erase(i, str_user.length());
       count++;
    }
    temp << lookup << endl;
  }
  clear();

  temp.seekp(0, ios_base::beg);

  while(!temp.eof()) {
    string str;
    getline(temp, str);

    *terminal_data << str << endl;
  }

  cout << "delete words: " << count << endl;
  temp.close();
  temp.open("delete_buf.txt", ios::out);      //удаление данных в буфере
  temp.close();
}

void terminal::clear()
{
  terminal_data->close();
  terminal_data->open("terminal_data.txt", ios::out);
  terminal_data->close();

  terminal_data->open("terminal_data.txt");
}

void terminal::save()
{
  file->clear();
  terminal_data->clear();
  terminal_data->seekp(0, ios_base::beg);

  while (!terminal_data->eof()) {
    string str;

    getline(*terminal_data, str);
    *file << str << endl;
  }
}

void menu::interface()
{
  for (;;) {
    int choice;

    cout << endl;

    cout << "Press '1' to add text" << endl;
    cout << "Press '2' to show text stored terminal" << endl;
    cout << "Press '3' to find word" << endl;
    cout << "Press '4' to delete word from terminal" << endl;
    cout << "Press '5' to clear terminal" << endl;
    cout << "Press '6' to save changes in file" << endl;
    cout << "Press '7' to exit" << endl;

    cout << endl;
    cout << "selection: ";
    cin >> choice;
    cout << endl;

    if (choice == 1) {
      Str_Add();
    }

    if (choice == 2) {
      Show_Text();
    }

    if (choice == 3) {
      Word_Search();
    }

    if (choice == 4) {
      Word_Delete();
    }

    if (choice == 5) {
      Terminal_Clear();
    }

    if (choice == 6) {
      File_Save();
    }

    if (choice == 7) {
      break;
    }
  }
}

terminal::terminal()
{
  file_read();
  file_output();
}

terminal::~terminal()
{
  terminal_data->close();
  file->close();
}
