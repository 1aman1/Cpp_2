#include <iostream>
#include <sstream>

using namespace std;

int main()
{
     stringstream ss;

     int nInt = 2019;
     double nDouble = 3.142;
     ss << nInt << " " << nDouble;

     string myStr1, myStr2;
     ss >> myStr1 >> myStr2;

     cout << "The numeric values converted to string:" << endl;
     cout << "myStr1 = " << myStr1 << " "
          << "myStr2 = " << myStr2 << endl;

     // string to numeric
     stringstream ns;
     int nIntval;
     double nDoubleval;

     // stringstream ns("2019 3.142"); OR
     ns << "2019 3.142"; // insert a string of numbers into the stream

     ns >> nIntval >> nDoubleval;
     cout << "The string values converted to numeric types:" << endl;
     cout << "nIntval = " << nIntval << " "
          << "nDoubleval = " << nDoubleval << endl;

     return 0;
}
