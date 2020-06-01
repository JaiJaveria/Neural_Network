#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
void assert(bool a);
bool eqSize(std::vector<std::vector<double> > a,std::vector<std::vector<double> > b)
{
    //assuming that all the rows will have same size as that of the
    //0th one.
    if (a.size()==b.size())
    {
        /* code */
        if(a.size()==0)
            return true;
        if(a[0].size()==b[0].size())
            return true;
    }

    return false;
}
std::vector<std::vector<double> > transpose(std::vector<std::vector<double> > a)
{
    std::vector<std::vector<double> > ret;
    ret.assign(a[0].size(),{});
    int k;
    for (size_t i = 0; i < a.size(); i++)
    {
        k=0;
        for (size_t j = 0; j < a[i].size(); j++)
        {
            ret[k].push_back(a[i][j]);
            k++;
            /* code */
        }
    }
    return ret;

}

std::vector<std::vector<double> > elementWiseMult(std::vector<std::vector<double> > a, std::vector<std::vector<double> > b)
{
    assert(eqSize(a,b));
    std::vector<std::vector<double> > ret;

    ret.assign(a.size(),{});
    for(int i = 0; i < a.size(); ++i)
    {
        for(int j = 0; j < a[i].size(); ++j)
        {
            ret[i].push_back(a[i][j]*b[i][j]);
        }
    }
    return ret;

}

void elementWiseArithematic(std::vector<std::vector<double> > &a, std::vector<std::vector<double> > b, double (*operand)(double, double))
{
    assert(eqSize(a,b));
    // std::vector<std::vector<double> > ret;

    // ret.assign(a.size(),{});
    for(int i = 0; i < a.size(); ++i)
    {
        for(int j = 0; j < a[i].size(); ++j)
        {
            a[i][j]=operand(a[i][j],b[i][j]);
            // ret[i].push_back(a[i][j]-b[i][j]);
        }
    }
    // return ret;

}

void elementWiseArithematicAlpha(std::vector<std::vector<double> > &a, std::vector<std::vector<double> > b, double (*operand)(double, double), double alpha)
{
    assert(eqSize(a,b));
    // std::vector<std::vector<double> > ret;

    // ret.assign(a.size(),{});
    for(int i = 0; i < a.size(); ++i)
    {
        for(int j = 0; j < a[i].size(); ++j)
        {
            a[i][j]=operand(a[i][j],alpha*b[i][j]);
            // ret[i].push_back(a[i][j]-b[i][j]);
        }
    }
    // return ret;

}

void printMat(std::vector<std::vector<double>> bias)
{
    for (auto i =0; i <bias.size(); i++)
    {
        for (auto j = 0; j < bias[i].size(); j++)
        {
            printf("%f ",bias[i][j] );
            // printf("\n");
        }
        printf("\n");

    }
    printf("\n" );
}

std::vector<std::vector<double> > matMul(std::vector<std::vector<double> > a, std::vector<std::vector<double> > b)
{
    assert(a[0].size()==b.size());
    // printf("95--\n" );
    // printMat(a);
    // printMat(b);
    std::vector<std::vector<double> > ret;
    ret.assign(a.size(),{});

    for(int i = 0; i < a.size(); ++i)
    {
        // printf("13--\n" );
        for(int j = 0; j < b[0].size(); ++j)
        {
            ret[i].push_back(0);
            // printf("17--%f\n",ret[i][j] );
            for(int k = 0; k < b.size(); ++k)
                ret[i][j] += a[i][k] * b[k][j];
        }
    }


    return ret;
}

void addNum(std::vector<std::vector<double>> &v, std::vector<double> b)
{
    // std::vector<std::vector<double>> ret;
    // ret.assign(v.size(),{});
    for(int i = 0; i < v.size(); ++i)
        for(int j = 0; j < v[i].size(); ++j)
            v[i][j]=v[i][j]+b[i];
            // ret[i][j]=v[i][j]+b[i];
        // return ret;

}

std::vector<std::vector<double>> twoDArithematic(std::vector<std::vector<double>> v, std::vector<std::vector<double> > b, double (*operand)(double, double))
{
   std::vector<std::vector<double>> ret;
   ret.assign(v.size(),{});
   for(int i = 0; i < v.size(); ++i)
       for(int j = 0; j < v[i].size(); ++j)
            ret[i].push_back(operand(v[i][j],b[i][j]));
           // ret[i][j]=operand(v[i][j],b[i][j]);
           // ret[i][j]=v[i][j]+b[i];
       return ret;

}

double maxValMat(std::vector<std::vector<double> > v)
{
    double max=-DBL_MAX;
    for(int i = 0; i < v.size(); ++i)
        for(int j = 0; j < v[i].size(); ++j)
            if(v[i][j] > max )
                max=v[i][j];

    return max;
}
// void  broadcasting(std::vector<std::vector<double> > a, std::vector<std::vector<double> > b, double (*operand)(double, double))
// {
//     //the result of comuptation is stored in vector wich doesnot
//     //require broadcasting.
//     if(a.size()==1)
//     {
//         if(a[0].size()==1)
//         {
//             std::vector<std::vector<double> > broadcastedA;
//             broadcastedA.assign(b.size(),{});
//             for (size_t i = 0; i < b.size(); i++)
//                 for (size_t j = 0; j < b[i].size(); j++)
//                 {
//                     broadcastedA[i].push_back(a[0][0]);
//                 }
//             // twoDArithematic(broadcastedA, b,operand );
//             elementWiseArithematic(b, broadcastedA, operand);
//         }
//
//     }
//     else if (b.size()==1)
//     {
//         if(b[0].size()==1)
//         {
//             std::vector<std::vector<double> > broadcastedB;
//             broadcastedB.assign(a.size(),{});
//             for (size_t i = 0; i < a.size(); i++)
//                 for (size_t j = 0; j < a[i].size(); j++)
//                 {
//                     broadcastedB[i].push_back(b[0][0]);
//                 }
//             // twoDArithematic(a, broadcastedB,operand );
//             elementWiseArithematic(a, broadcastedB, operand);
//
//         }
//     }
// }
