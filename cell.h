#pragma once
using namespace std;
#include <string>
class cell
{
  private:
      enum states {
       E,X,O
      };

      states state = E;

  public:
      string getState();
      void setState(int set);
};

