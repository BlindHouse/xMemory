//
// Created by lunaticsoul on 20/03/16.
//

#include "xObject.h"
#include <iostream>
#include <json/json.h>
#include <fstream>


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

string xObject::getName() {
    return name;
}

string xObject::getLastname(){
    return lastname;
}

int xObject::getAge(){
    return age;
}

string xObject::getColor(){
    return color;
}

void xObject::setName(const string &name) {
    xObject::name = name;
}

void xObject::setLastname(const string &lastname) {
    xObject::lastname = lastname;
}

void xObject::setAge(int age) {
    xObject::age = age;
}

void xObject::setColor(const string &color) {
    xObject::color = color;
}

void xObject::serialize(){
    Json::Value root; //Creates a Json Value to be exported to a .json file.

    //Assignation of variables to the Json Value with their
    //respective tags.
    root["className"]["name"] = name;
    root["className"]["lastname"] = lastname;
    root["className"]["age"] = age;
    root["className"]["color"] = color;
    //Creation and writing to the output file
    ofstream file;
    file.open("File.json"); //.json file that gets saved on
    file << root;           //the executable directory.
    file.close();
}

void xObject::deserialize() {
    //Creates a new Json Value to store variables
    //and be able to pull data from it.
    Json::Value root2;
    //Tries to see if the file exists.
    try {
        //Creation of a stream of a file to write
        //From reading.
        ifstream file2;
        //Opens the existent .json file
        file2.open("File.json");
        //Reads data to export it to the Json Value variable.
        file2 >> root2;
        file2.close();

        //TODO HERE WILL BE THE RETURN CODE

        //Debug print.
        cout << root2["className"]["name"].toStyledString() << endl;
    }
    catch (Json::RuntimeError) {
        cout << "There's no file to deserialize" << endl;

    }
}



