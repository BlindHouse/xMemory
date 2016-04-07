//
// Created by lunaticsoul on 20/03/16.
//

#include "xObject.h"
#include <iostream>
#include <json/json.h>
#include <fstream>
#include <algorithm>

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

void xObject::serialize(string ClassName){
    Json::Value root; //Creates a Json Value to be exported to a .json file.

    try {
        //Creation of a stream of a file to write
        //From reading.
        ifstream file2;
        //Opens the existent .json file
        file2.open("File.json");
        //Reads data to export it to the Json Value variable.
        file2 >> root;
        file2.close();
    }
    catch (...){
        cout << "Theres no existent file to append" << endl;
    }

    //Assignation of variables to the Json Value with their
    //respective tags.

    root[ ClassName ][ "name" ] = name;
    root[ ClassName ]["lastname"] = lastname;
    root[ ClassName ]["age"] = age;
    root[ ClassName ]["color"] = color;
    //Creation and writing to the output file
    ofstream file;
    file.open("File.json"); //.json file that gets saved on
    file << root;           //the executable directory.
    file.close();
}

void xObject::deserialize(string ClassName) {
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

        string temp = root2[ClassName]["name"].toStyledString();
        temp = cutString(temp);
        (*this).name = temp;
        //Debug print.
        //cout << root2[ClassName][dataReturn].toStyledString() << endl;
    }
    catch (Json::RuntimeError) {
        cout << "There's no file to deserialize" << endl;
    }
}

string xObject::cutString(string ToCut) {
    unsigned long Position;
    Position= ToCut.find("\"");
    ToCut.erase(Position,Position+1);
    Position= ToCut.find("\"");
    ToCut.erase(Position,Position+1);
    return ToCut;
}


