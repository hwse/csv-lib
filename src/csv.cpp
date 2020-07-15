#include "../include/csv.h"

#include <iostream>
#include <utility>
#include <string>
#include <sstream>


csv::table::table(std::vector<row>& rows, bool has_header): rows(rows), has_header(has_header) {}

csv::table::table(std::vector<row>&& rows, bool has_header) : rows(std::move(rows)), has_header(has_header) {}

csv::row &csv::table::header_row() {
    if (!has_header) {
        throw std::runtime_error("table has no header");
    }
    return rows.at(0);
}


csv::table csv::read(std::istream& stream, char delimiter, bool has_header) {
    std::vector<csv::row> result;
    for(std::string line; std::getline(stream, line);) {
        csv::row r;
        std::istringstream line_stream(line);
        for(std::string cell; std::getline(line_stream, cell, delimiter);) {
            r.emplace_back(cell);
        }
        result.emplace_back(r);
    }
    return csv::table(std::move(result), has_header);
}
