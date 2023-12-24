#include "factory.hpp"
#include "ork.hpp"
#include "knight.hpp"
#include "bear.hpp"

std::shared_ptr<NPC> factory(std::istream& in) {
    std::string type, name;
    int x, y;
    char c;
    in >> type >> name >> c >> x >> c >> y >> c;
    std::shared_ptr<NPC> res;
    if (type == "Ork") {
        res = std::make_shared<Ork>(x, y, name);
    }
    else if (type == "Knight") {
        res = std::make_shared<Knight>(x, y, name);
    }
    else if (type == "Bear") {
        res = std::make_shared<Bear>(x, y, name);
    }
    else if (type != "") {
        std::cerr << "Unknown type" << std::endl;
    }
    return res;
}

std::shared_ptr<NPC> factory(const std::string& type, const std::string& name, const int& x, const int& y) {
    std::shared_ptr<NPC> res;
    if (type == "Ork") {
        res = std::make_shared<Ork>(x, y, name);
    }
    else if (type == "Knight") {
        res = std::make_shared<Knight>(x, y, name);
    }
    else if (type == "Bear") {
        res = std::make_shared<Bear>(x, y, name);
    }
    else {
        std::cerr << "Unknown type" << std::endl;
    }
    return res;
}