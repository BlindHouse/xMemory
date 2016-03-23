//
// Created by lunaticsoul on 20/03/16.
//

#include "xObject.h"
#include <iostream>


using namespace std;

xObject::xObject(string Name, string Lastname,
                 int Age, string Color) {
    setAge(Age);
    setColor(Color);
    setLastname(Lastname);
    setName(Name);

}
