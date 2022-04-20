#include "Algorithm.h"
#include "../CSVRow/CSVRow.h"
#include <random>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <set>


std::istream& operator>>(std::istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

std::vector<Node> algs::createDataBase(std::ifstream &stream, uint8_t maxColor)
{
    CSVRow row;
    std::vector<Node> data;
    std::vector<double>attributes;
    while(stream >> row)
    {
        for(int i = 0; i< row.size();i++)
            attributes.emplace_back(std::stod(row[i]));

        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(1,maxColor);
        int index = dist6(rng);
        data.emplace_back(Node(std::move(attributes),index));
        
    }
    return data;
}

void algs::setColors(Node& node, std::vector<Cluster>& clusters)
{
    double distance;
    std::set<std::pair<double,int>,std::less<std::pair<double,int>>> set;
    for(int i = 0; i<clusters.size();i++)
    {
        for(int j = 0; j<node.getCoords().size(); j++)
            distance += std::pow(node.at(j)-clusters[i].at(j),2);

        set.insert(std::make_pair(std::sqrt(distance),i));
        distance = 0;
    }
    clusters[set.begin()->second].push_back(node);
}

void algs::setClustersCoords(std::vector<Cluster> &clusters)
{
    for(Cluster& cl__ : clusters)
    {
        std::vector<double> newCoords(cl__.size(),0);
        std::vector<Node> nodes = cl__.getNodes();
        int size = nodes.size();
        if(!nodes.empty())
        {
            for(const Node& node : nodes)
            {
                std::vector<double> nodesCoords = node.getCoords();
                for(int i = 0; i< nodesCoords.size();i++)
                {
                    newCoords[i] += nodesCoords[i];
                }
            }
            std::for_each(newCoords.begin(),newCoords.end(),[size](double &value){value /= size;});

            cl__.changeCoords(std::move(newCoords));
            newCoords.clear();
        }
    }
}

