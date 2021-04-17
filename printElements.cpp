#include "printElements.hpp"
void printVec(std::vector<int>vec){

    std::cout << "{";

    for(auto element: vec)
        std::cout << element << ", ";

    std::cout << "}" << std::endl;

}

std::string vecToStr(std::vector<int>vec){

    std::string output = "{";
    
    for(auto element: vec){
        output += std::to_string(element);
        output += ",";
    }
    output += "}";
    return output;

}