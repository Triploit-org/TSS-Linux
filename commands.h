void befehl1(vector<string> args);

vector<string> names;
void (befehle[2])(vector<string> args) =
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
