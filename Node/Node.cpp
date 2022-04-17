#include "Node.h"
void Node::changeCoords(std::vector<double> &&newCoords)
{
    this->_variables = newCoords;
}

Node::Node(std::vector<double>&& coords)
{
    this->_variables = coords;
}
