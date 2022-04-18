#pragma once
#include "Node.h"

class Cluster : public Node
{
public:
    Cluster(Node& a, int clusterIndex);
    void changeCoords(std::vector<double> &&newCoords);
    std::vector<Node> getNodes();
    void push_back(Node& node);
    void clearNode();
private:
    std::vector<Node> clustersNodes;
};