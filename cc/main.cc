#include "../header/Network.h"
#include <stdio.h>
#include <stdlib.h>
// #include <float.h>
void printMat(std::vector<std::vector<double>> bias);
double leakyRelu(double z);
double leakyReluDerivative(double z);
int main()
{
    Network n(2,10,4,3);
    // n.printNetwork();
    for (size_t i = 0; i < 40; i++)
    {
        /* code */
        printf("437--\n" );
        printMat( n.forwardProp({{1.2},{3.4}},leakyRelu, 1) );
        n.backProp({{1.6},{3.7},{2.5}},(leakyReluDerivative));
    }

    return 0;

}
