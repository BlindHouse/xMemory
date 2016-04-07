//
// Created by lunaticsoul on 20/03/16.
//

#ifndef XMEMORY_XOBJECT_H
#define XMEMORY_XOBJECT_H

#include <iostream>

using namespace std;

struct xObject {
    string* SerializeList;
    string name;
    string lastname;
    int age;
    string color;

    public:
        string classname;
        xObject(string Name, string Lastname, int Age,
                string Color);

    public:
        char* getClassName();

        string getName();

        string getLastname();

        int getAge();

        string getColor();

        void setName(const string &name);

        void setLastname(const string &lastname);

        void setAge(int age);

        void setColor(const string &color);

        void serialize(string ClassName);

        void deserialize(string ClassName);

        string cutString(string ToCut);

};


#endif //XMEMORY_XOBJECT_H
