#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include <unistd.h>
#include "Commands/info.h"
using namespace std;

//Variablen
  double Version = 0.1;
  string System = "Linux";
  char pfad[256];
  string input;
  string hostname = "NILL";
  //Variablen ende

// DAS HIER DANN IN COMMANDS_H
void befehl1(vector<string> args);

vector<string> names;
void(*befehle[2])(vector<string> args) =
{
  &befehl1,
  befehl1
};

void nInit()
{
  names.push_back("befehl1");
  names.push_back("befehl2");
}

void befehl1(vector<string> args)
{
  for (int i = 0; i < args.size(); i++)
  {
    cout << "Argument " << i << " = " << args[i] << endl;
  }
  cout << "Befehl1 bendet!" << endl;
  return;
}

#define ANZ names.size();
// ENDE COMMANDS_H

// API_H
bool checkCommand(string in, string s)
{
  if (in.substr(0, s.size()) == s)
  {
    return true;
  }
  return false;
}
// ENDE API_H



int shell(int argc, char const *argv[])
{
  string cmd = "";

  while (!checkCommand(cmd, "exit"))
  {
    string input;
    vector<string> args;

    getcwd(pfad, 256);
    //bald wird hier der Hostname des pcs definiert
    std::cout << "\033[0m\033[1m\033[32m" << "[" << getenv("USER") << "@" << hostname << "]" << "$ " << "\033[0m";
    getline(cin, input);

    stringstream ss(input);
    string buf;

    while (ss >> buf)
    {
        args.push_back(buf);
    }
    cmd = args[0];
      if (checkCommand(cmd, "befehl1") || checkCommand(cmd, "befehl2"))
      {
        befehl1(args);
      }

  }
}

int scriptfile(int argc, char const *argv[]) {
  cout << "\033[031;1;31mDie Script funktion ist noch nicht vervollständigt\n";
  return 0;
}


int main(int argc, char const *argv[]) {
  info(Version, System);
  if (argc==1) {
    shell(argc, argv);
  }
  else {
    scriptfile(argc, argv);
  }
return 0;
}
