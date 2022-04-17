#include "Algorithm.h"
#include "../CSVRow/CSVRow.h"

std::istream& operator>>(std::istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

std::vector<Node> algs::createDataBase(std::ifstream &stream)
{
    CSVRow row;
    std::vector<Node> data;
    std::vector<double>toAdd;
    while(stream >> row)
    {
        for(int i = 0; i< row.size()-1;i++)
            toAdd.emplace_back(std::stod(row[i]));
        data.emplace_back(Node(std::move(toAdd)));
        toAdd.clear();
    }
    return data;
}



