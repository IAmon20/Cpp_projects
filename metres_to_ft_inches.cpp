#include <iostream>
using namespace std;
/*#include <cmath>
#include <cstdlib>*/
#include <ctime> 
using namespace std;

int main() {
    float metre_values;
   
    
    cout << "Enter a measured value in metres : ";
    cin >>  metre_values;
    float feet_values =  3.281* metre_values;
    float inches_values = 39.37 * metre_values;
    cout << "Conversion to feet:"<<endl << feet_values << endl;
    cout << "Conversion to inches :" << endl << inches_values;
     return 0;
}