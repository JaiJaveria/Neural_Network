#include <vector>
#ifndef NETWORK_H
#define NETWORK_H
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
            void initWandB( int startI1, int endI1, int nodes, int feat);
            /*startI1 start index for the first index*/


    public:
        Network(int inpF, int numL, int numN, int outF );

        void printNetwork();

        std::vector<std::vector<double> > forwardProp(std::vector<std::vector<double> > inpV,  double (*activation)(double), int storeAZ)
        ;
        void backProp(std::vector<std::vector<double>> targetQVal, double (*activationDerivative)(double) )
        ;

};
#endif
