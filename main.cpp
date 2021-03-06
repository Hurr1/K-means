#include <bits/stdc++.h>
#include "Algorithm/Algorithm.h"
#include "CSVRow/CSVRow.h"
#include "Node/Cluster.h"
#include <random>

int main(int argc, char *argv[])
{

    short clusters_number;

    if (argc - 1 == 2)
    {
        clusters_number = std::stod(argv[2]);
        if (clusters_number <= 0)
            clusters_number = 3;
    }
    else
    {
        std::cout << "You provide incorrect number of arguments for this application" << '\n';
        return 1;
    }
    std::ifstream dataPath("Resources/" + static_cast<std::string>(argv[1]));

    if (!dataPath)
    {
        std::cout << "File <" << argv[1] << "> does not exists" << '\n';
        return 1;
    }

    std::vector<Node> data(algs::createDataBase(dataPath, clusters_number));
    std::vector<Cluster> clusters;

    for (auto i = 0; i < clusters_number; i++)
    {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1, data.size() - 1);
        int index = dist6(rng);

        clusters.push_back(Cluster(data[index], i));
    }

    std::vector<int> clBefore(clusters.size(), 0);
    std::vector<int> clAfter(clusters.size(), 0);
    uint16_t round = 0;

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout<<"Round ["<< round <<"]"<<'\n'<<"----------"<<'\n';
        for (Node &node : data)
        {
            algs::setColors(node, clusters);
        }
        algs::setClustersCoords(clusters);
    
        std::size_t index = 0;
        for (auto &cl : clusters)
        {
            const auto cl_vec = cl.getCoords();
            std::cout<<"Cluster [" << index <<"] vector:  ";
            for (int i = 0; i < cl.size(); i++)
                std::cout <<std::setw(10)<< std::left<< cl_vec[i] <<std::setw(3)<<std::left<< ' ';

            std::cout << "  Nodes count : " << cl.getNodes().size() << '\n'<<'\n';
            clAfter.push_back(cl.getNodes().size());
            index++;
        }
        if (std::equal(clAfter.begin(), clAfter.end(), clBefore.begin(), clBefore.end()))
        {
            std::cout<<"Clusters from <Round "<< round-1<<"> have the same vectors as Clusters from <Round "<<round<<"> "<<'\n'<<'\n';
            std::cout<<"Success"<<'\n';
            return 0;
        }

        for(auto &cl : clusters)
            cl.clearNode();
        round++;
        clBefore = std::move(clAfter);
        clAfter.clear();

        std::cout << '\n'<<'\n';
    }
}