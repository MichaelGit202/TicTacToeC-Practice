#pragma once
using namespace std;
#include <string>
class cell
{
  private:
      enum states {
       X,O,E
      };

      states state;

  public:
      string getState();
};

