#pragma once
#include <string>
#include <vector>
#include <fstream>

class CSVRow
{
public:
    std::string operator[](std::size_t index) const;
    void readNextRow(std::istream& str);
    std::size_t size() const;
private:
    std::string            m_line;
    std::vector<double>    m_data;
};
