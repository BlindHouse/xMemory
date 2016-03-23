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
char* xObject::getClassName(){
    if (classname.size() > 11){
        classname = classname.substr (2, classname.size() - 1);
        return (char*) classname.c_str();
    }else{
        classname = classname.substr(1, classname.size() - 1);
        return (char*) classname.c_str();
    }
}
