#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
std::vector<std::vector<double>> activationMat2(std::vector<std::vector<double> > v, double (*activation)(double) )
{
    std::vector<std::vector<double>> ret;
    ret.assign(v.size(),{});
    for(int i = 0; i < v.size(); ++i)
        for(int j = 0; j < v[i].size(); ++j)
            ret[i].push_back(activation(v[i][j]));
    return ret;

}

void activationMat(std::vector<std::vector<double> > &v, double (*activation)(double) )
{
    for(int i = 0; i < v.size(); ++i)
        for(int j = 0; j < v[i].size(); ++j)
            v[i][j]=activation(v[i][j]);

}

double leakyReluDerivative(double z)
{
    if (z>0)
        return 1;
    else
        return 0.01;
}

double leakyRelu(double z)
{
    if (z>0)
        return z;
    else
        return 0.01*z;
}
