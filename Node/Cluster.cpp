#include "Cluster.h"
#include <iostream>

Cluster::Cluster(Node &a, int clusterIndex) : Node(a.getCoords())
{
    this->_color = clusterIndex;
    this->clustersNodes = std::vector<Node>();
}

void Cluster::changeCoords(std::vector<double> &&newCoords)
{
    this->_variables = newCoords;
}

std::vector<Node> Cluster::getNodes()
{
    return this->clustersNodes;
}

void Cluster::push_back(Node& node)
{
    this->clustersNodes.push_back(node);
}

void Cluster::clearNode()
{
    this->clustersNodes.clear();
}
