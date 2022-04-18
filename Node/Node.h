#pragma once
#include <vector>
#include <string>

class Node
{
public:
    Node(std::vector<double>&& coords, uint8_t color);
    Node(std::vector<double>&& coords);
    std::vector<double> getCoords() const;
    uint8_t getColor() const;
    double at(int index) const;
    void setColor(int color);
    std::size_t size();
public:
    uint8_t _color;
protected:
    std::vector<double> _variables;
};