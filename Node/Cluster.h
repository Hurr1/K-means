#pragma once
#include "Node.h"

class Cluster : public Node
{
public:
    Cluster(Node& a, int clusterIndex);
    ~Cluster() = default;
    std::vector<Node> getNodes() const;

    void changeCoords(std::vector<double> &&newCoords);
    void push_back(Node& node);
    void clearNode();

private:
    //Not a single-responsibility principle :/
    std::vector<Node> clustersNodes;
};