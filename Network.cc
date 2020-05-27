#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
// Exception AssertionError;
// std::vector<std::vector<std::vector<double> > > as threeDVector

bool eqSize(std::vector<std::vector<double> > a,std::vector<std::vector<double> > b)
{
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
double subt(double a, double b)
{
    return a-b;
}
double multiply(double a, double b)
{
    return a*b;
}
double add(double a, double b)
{
    return a+b;
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

double leakyRelu(double z)
{
    if (z>0)
        return z;
    else
        return 0.01*z;
}
double leakyReluDerivative(double z)
{
    if (z>0)
        return 1;
    else
        return 0.01;
}

void activationMat(std::vector<std::vector<double> > &v, double (*activation)(double) )
{
    for(int i = 0; i < v.size(); ++i)
        for(int j = 0; j < v[i].size(); ++j)
            v[i][j]=activation(v[i][j]);

}
//to return the new mat. without updating v
std::vector<std::vector<double>> activationMat2(std::vector<std::vector<double> > v, double (*activation)(double) )
{
    std::vector<std::vector<double>> ret;
    ret.assign(v.size(),{});
    for(int i = 0; i < v.size(); ++i)
        for(int j = 0; j < v[i].size(); ++j)
            ret[i].push_back(activation(v[i][j]));
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
class Network
{
private:
        int inpFeat;//number of input features
        int numLayer;//numbers of layers(hidden +output)
        int numNodes;//numbers of nodes in hidden layers
        int outFeat;//number of output features
        std::vector<std::vector<std::vector<double> > > weight;
        std::vector<std::vector<std::vector<double> > > bias;
        std::vector<std::vector<std::vector<double> > > Z;
        std::vector<std::vector<std::vector<double> > > A;
        void initWandB( int startI1, int endI1, int nodes, int feat)
        /*startI1 start index for the first index*/
        {
            // printf("237--%d\n", feat );
            for (size_t i0 = startI1; i0 <= endI1; i0++)
            {
                for (size_t i1 = 0; i1 < nodes; i1++)
                {

                    for (size_t i2 = 0; i2 < feat; i2++)
                        {
                            weight[i0][i1].push_back((rand()%32)*0.01);
                            //initialize with small numbers
                        }
                    bias[i0][i1].push_back(0);
                }
            }
        }


public:
    Network(int inpF, int numL, int numN, int outF )
    {
        //the index i corresponds to the ith layers
        //the 0th index is empty
        inpFeat=inpF, numLayer=numL;
        numNodes=numN, outFeat=outF ;
        weight.assign(numLayer+1,{});
        bias.assign(numLayer+1,{});
        // printf("263--%d\n",numNodes );
        for (size_t i = 1; i <numLayer; i++)
        {
            weight[i].assign(numNodes,{});
            bias[i].assign(numNodes,{});
            /* code */
        }
        weight[numLayer].assign(outFeat,{});
        bias[numLayer].assign(outFeat,{});
        //first layer of nodes
        initWandB( 1, 1, numNodes, inpFeat);
        //all other layers except output
        initWandB( 2, numLayer-1, numNodes, numNodes);
        // the output layer
        initWandB( numLayer, numLayer, outFeat, numNodes);
    }

    void printNetwork()
    {
        printf("Weights\n" );
        for (auto i =0; i <weight.size(); i++)
        {
            for (auto j = 0; j < weight[i].size(); j++)
            {
                for (auto k = 0; k <weight[i][j].size(); k++)
                {
                    printf("%f ",weight[i][j][k] );
                    // printf("\n");
                }
                printf("\n");

            }
            printf("\n");
            printf("\n");

            /* code */
        }
        printf("Baises\n" );
        for (auto i =0; i <bias.size(); i++)
        {
            for (auto j = 0; j < bias[i].size(); j++)
            {
                printf("%f ",bias[i][j][0] );
                // printf("\n");
            }
            printf("\n");

        }

    }

    std::vector<std::vector<double> > forwardProp(std::vector<std::vector<double> > inpV,  double (*activation)(double), int storeAZ)
    {
        //A and Z have the input value and the out put of each layer
        //including the output layer
        std::vector<std::vector<double> > v;
        v=matMul(weight[1], inpV);
        double (*arithematic) (double, double);
        arithematic=add;
        // printf("322--\n" );printMat(v);
        // printf("323--\n" );printMat(bias[1]);
        elementWiseArithematic(v,bias[1],arithematic);
        if (storeAZ)
        {
            Z.clear();
            Z.push_back(inpV);
            Z.push_back(v);
        }
        activationMat(v, activation);
        if (storeAZ)
        {
            A.clear();
            A.push_back(inpV);
            A.push_back(v);
        }
        // printf("194--\n" );printMat(v);
        for (size_t i = 2; i < numLayer; i++)
        {

            v=matMul(weight[i],v);
            // printMat(v);
            //addBias
            elementWiseArithematic(v,bias[i],arithematic);
            if(storeAZ)
            {
                Z.push_back(v);
            }
            activationMat(v, activation);
            if(storeAZ)
            {
                A.push_back(v);
            }
            // printMat(v);

        }
        std::vector<std::vector<double> > outVal;
        outVal=matMul(weight[numLayer], v);
        // addBias(outVal, bias[numLayer]);
        elementWiseArithematic(outVal, bias[numLayer],arithematic);
        if(storeAZ)
        {
            Z.push_back(outVal);

        }
        activationMat(outVal,activation);
        if(storeAZ)
        {
            A.push_back(outVal);

        }
        // printf("203--\n" );printMat(outVal);
        // print the Z vector

        // for (size_t i = 0; i < Z.size(); i++)
        // {
        //     printMat(Z[i]);
        //     printf("\n" );
        //     /* code */
        // }

        // return maxValMat(outVal);
        return (outVal);
    }

    void backProp(std::vector<std::vector<double>> targetQVal, double (*activationDerivative)(double) )
    {
        std::vector<std::vector<std::vector<double>>> da;
        std::vector<std::vector<std::vector<double>>> dz;
        std::vector<std::vector<std::vector<double>>> dw;
        std::vector<std::vector<std::vector<double>>> db;
        dz.assign(numLayer+1,{});//output of layers + input
        da.assign(numLayer+1,{});//output of layers + input
        dw.assign(numLayer+1,{});//1st layer not required but
        //used for clearance of notation used. dw[l] means lth layer
        db.assign(numLayer+1,{});//same as dw
        int l=numLayer;
        double (*arithematic)(double, double);
        // da[l]=2*(A[l]-y). y is the targetQVal. since the
        // loss function is L = (y-a)^2
        arithematic=subt;
        da[l]=(twoDArithematic(A[l],targetQVal,arithematic));
        // printf("408--%d\n",l );
        // printMat(da[l]);
        arithematic=multiply;
        std::vector<std::vector<double>> twoMat;
        twoMat.assign(da[l].size(), {});
        for (size_t i = 0; i < da[l].size(); i++)
            for (size_t j = 0; j < da[l][i].size(); j++)
                    twoMat[i].push_back(2);


        elementWiseArithematic(da[l],twoMat,arithematic);
        // da[l]=broadcasting({{2}},da[l],arithematic);
        // printf("410--%d\n",l );
        // printMat(da[l]);
        while (l>0)
        {
            std::vector<std::vector<double>> v =activationMat2(Z[l],activationDerivative);
            // printf("413--%d\n",l );
            // printMat(da[l]);
            dz[l]=elementWiseMult(da[l],v);
            // printf("434--\n" );
            // v=transpose(weight[l]);
            da[l-1]=matMul(transpose(weight[l]),dz[l]);
            // printf("430--\n" );
            // printMat(da[l-1]);
            dw[l]=matMul(dz[l],transpose(A[l-1]));
            db[l]=dz[l];
            arithematic=subt;
            elementWiseArithematicAlpha(weight[l],dw[l],arithematic,0.01);
            elementWiseArithematicAlpha(bias[l],db[l],arithematic,0.01);
            // printf("378--%d\n",l );
            // printMat( dw[l]);
            // printMat( dz[l]);
            // printMat( da[l]);
            // printMat( db[l]);
            // printMat( weight[l]);
            // printMat( bias[l]);
            l--;

            /* code */
        }


    }

};


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

// void leakyReluMat(std::vector<std::vector<double> > &v)
// {
//     for(int i = 0; i < v.size(); ++i)
//         for(int j = 0; j < v[i].size(); ++j)
//             v[i][j]=leakyRelu(v[i][j]);
//
// }
