#include<vector>
#include <string>
#include <exception>
#include <stdexcept>
#include <istream>

#ifndef CSV_LIB_LIBRARY_H
#define CSV_LIB_LIBRARY_H

namespace csv {
    typedef std::vector<std::string> row;

    struct table {
        std::vector<row> rows;
        bool has_header;

        table(std::vector<row>& rows, bool has_header);
        table(std::vector<row>&& rows, bool has_header);

        row &header_row();
    };

    table read(std::istream &stream, char delimiter = ';', bool has_header = false);
}


#endif //CSV_LIB_LIBRARY_H
