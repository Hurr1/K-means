#include <vector>
#include <string>

class Node
{
public:
    Node(std::vector<double>&& coords);
    void changeCoords(std::vector<double> &&newCoords);
private:

public:
    std::vector<double> _variables;
    std::string _color;
};