#include <vector>
#include "../Node/Node.h"
#include "../Node/Cluster.h"

namespace algs
{
    std::vector<Node> createDataBase(std::ifstream &stream, uint8_t maxColor);

    void setColors(Node& node, std::vector<Cluster>& clusters);

    void setClustersCoords(std::vector<Cluster> &clusters);
}