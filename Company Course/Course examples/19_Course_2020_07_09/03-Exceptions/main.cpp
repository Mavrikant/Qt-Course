// out_of_range example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector

int main_1 (void) {

  std::vector<int> myvector(10);

  try {
    myvector.at(10) = 100;      // vector::at throws an out-of-range
  }
  catch (const std::out_of_range& e) {
    std::cerr << "Out of Range error: " << e.what() << '\n';
  }

  return 0;
}


// invalid_argument example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::invalid_argument
#include <bitset>         // std::bitset
#include <string>         // std::string

int main_2 (void) {
  try {
    // bitset constructor throws an invalid_argument if initialized
    // with a string containing characters other than 0 and 1
    std::bitset<5> mybitset (std::string("01003"));
  }
  catch (const std::invalid_argument& ia) {
    std::cerr << "Invalid argument: " << ia.what() << '\n';
  }
  return 0;
}

// length_error example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::length_error
#include <vector>         // std::vector

int main_3 (void) {
  try {
    // vector throws a length_error if resized above max_size
    std::vector<int> myvector;
    myvector.resize(myvector.max_size()+1);
  }
  catch (const std::length_error& le) {
    std::cerr << "Length error: " << le.what() << '\n';
  }
  return 0;
}

//custom exception example
#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;

void MyFunc(int c)
{
    if (c > numeric_limits< char> ::max())
        throw invalid_argument("MyFunc argument too large.");
    //...
}

int main()
{
    try
    {
        MyFunc(256); //cause an exception to throw
    }

    catch (invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
    //...
    return 0;
}
