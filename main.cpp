#include <bits/stdc++.h>
#include "Algorithm/Algorithm.h"
#include "CSVRow/CSVRow.h"

int main(int argc, char* argv[])
{

    int clusters_number;
    
    if(argc-1 == 2)
    {
        clusters_number = std::stod(argv[2]);
        if(clusters_number <= 0)
            clusters_number = 3;
    }
    else
    {
        std::cout<<"You provide incorrect number of arguments for this application"<<'\n';
        return 1;
    }
    std::ifstream dataPath("Resources/"+static_cast<std::string>(argv[1]));

    if(!dataPath)
    {
        std::cout<<"File <"<< argv[1] <<"> does not exists"<<'\n';
        return 1;
    }
    std::vector<Node> data(algs::createDataBase(dataPath));
    for(Node a : data)
    {
        std::cout<< a._variables[0]<<'\n';
    }
    
}