#include <iostream>
using namespace std;

int main_1()
{
  int x = -1;

  // Some code
  cout << "Before try \n";
  try {
    cout << "Inside try \n";
    if (x < 0)
    {
      throw x;
      cout << "After throw (Never executed) \n";
    }
  }
  catch (int x ) {
    cout << "Exception Caught \n";
  }

  cout << "After catch (Will be executed) \n";

  return 0;
}

int main_2()
{
  try {
    throw 10;
  }
  catch (char *excp) {
    cout << "Caught " << excp;
  }
  catch (...) {
    cout << "Default Exception\n";
  }

  return 0;
}


int main_3()
{
  try {
  throw 'a';
  }
  catch (int x) {
    cout << "Caught " << x;
  }
  catch (...) {
    cout << "Default Exception\n";
  }
  return 0;
}

#include <iostream>
using namespace std;

int main_4()
{
  try {
  throw 'a';
  }
  catch (int x) {
    cout << "Caught ";
  }
  return 0;
}



// Here we specify the exceptions that this function
// throws.
void fun(int *ptr, int x) throw (int *, int)
{
  if (ptr == NULL)
    throw ptr;
  if (x == 0)
    throw x;
  /* Some functionality */
}

int main_5()
{
  try {
    fun(NULL, 0);
  }
  catch(...) {
    cout << "Caught exception from fun()";
  }
  return 0;
}



int main_6()
{
  try {

    try {
      throw 20;
    }
    catch (int n) {
      cout << "Handle Partially ";
      throw; //Re-throwing an exception
    }


  }
  catch (int n) {
    cout << "Handle remaining ";
  }
  return 0;
}


class Test {
public:
  Test() { cout << "Constructor of Test " << endl; }
  ~Test() { cout << "Destructor of Test " << endl; }
};

int main() {
  try {
    Test t1;
    throw 10;
    //...
  } catch(int i) {
    cout << "Caught " << i << endl;
  }
}
