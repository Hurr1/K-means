#pragma once
#include <vector>
#include <string>

class Node
{
public:
    Node(std::vector<double>&& coords, uint8_t color);
    Node(std::vector<double>&& coords);
    ~Node() = default;
    std::vector<double> getCoords() const;
    uint8_t getColor() const;
    double at(int index) const;
    std::size_t size() const;

    void setColor(int color);

public:
    uint8_t _color;
protected:
    std::vector<double> _variables;
};