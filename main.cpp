#include <iostream>
#include <fstream>
#include <json/json.h>
#include "xObject.h"

using namespace std;

static void Seriaalize(){
    xObject homer("Homer", "Simpson", 30, "Yellowish");

    homer.serialize();
    homer.deserialize();

};

int main(){

    Seriaalize();
    return 0;
}