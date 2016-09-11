bool checkCommand(string in, string s)
{
  if (in.substr(0, s.size()) == s)
  {
    return true;
  }
  return false;
}
