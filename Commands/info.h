#include <iostream>

using namespace std;

int info(double Version, string OS) {
  /* code */
  std::cout<<"\033[1mTriploit ShellScript Version "<<Version<<"-"<<OS<<std::endl<<"(c) 2016 Triploit. Alle Rechte vorbehalten."<<std::endl<<std::endl;
  return 0;
}
