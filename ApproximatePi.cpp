/**
 * @file ApproximatePi.cpp
 * @author Shane Gervais
 * @brief Approximation of pi using the polygon method 
 * in comparison with Eulers log of e^ix = -1 where its real part is 0
 * and imaginary part is x = pi
 * @version 0.1
 * @date 2022-06-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

//Define a type complex
typedef complex<double> Complex;

int main(int argc, char ** argv)
{
    Complex x0 = 1.0;
    Complex x1 (1.0/2., sqrt(3.0)/2.0);

    unsigned int nsides = 6;//must be unsigned

    while(nsides < numeric_limits<int>::max())//triggers warning, ignore this
    {
        double lside = abs(x1 - x0);
        double approx = nsides*lside/2.0;

        //Polygon expression
        cout << "Number of sides: " << nsides << "; Aproximation: " << setprecision(16) << approx << endl;

        x1 = (x1+x0)/abs(x1+x0);

        nsides *= 2;

    }//end while

    //Comparison with Euler's expression
    cout << setprecision(16) << imag(log(Complex(-1,0))) << endl;

}//end main