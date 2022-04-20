#include "Node.h"
#include <iostream>

Node::Node(std::vector<double>&& coords, uint8_t color)
{
    this->_variables = std::move(coords);
    this->_color = color;
}

Node::Node(std::vector<double>&& coords)
{
    this->_variables =std::move(coords);
}

std::vector<double> Node::getCoords() const
{
    return this->_variables;
}

uint8_t Node::getColor() const 
{
    return this->_color;    
}

double Node::at(int index) const
{
    return this->_variables[index];
}

void Node::setColor(int color)
{
    this->_color = color;
}

std::size_t Node::size() const
{
    return this->_variables.size();
}
