#include <iostream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>

#include "xObject.h"

int main() {
    std::stringstream ss;
    {
        cereal::JSONOutputArchive oarchive(std::cout); // Create an output archive

        xObject Person = xObject("B", "H", 21, "nigga");
        oarchive(Person); // Write the data to the archive
        cout << ss << endl;
    }

    /*{
        cereal::JSONInputArchive iarchive(ss); // Create an input archive

        xObject Person = xObject("B", "H", 21, "nigga");
        iarchive(Person); // Read the data from the archive
    }*/
}
