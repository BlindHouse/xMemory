//
// Created by lunaticsoul on 20/03/16.
//

#ifndef XMEMORY_XOBJECT_H
#define XMEMORY_XOBJECT_H

#include <iostream>
#include <cereal/archives/json.hpp>

using namespace std;

class xObject {

    string name;
    string lastname;
    int age;
    string color;

    public:
    string classname;
    xObject() { }

    xObject(string Name, string Lastname, int Age,
                string Color);

    public:

    char* getClassName();

        const string &getName() const {
            return name;
        }

        const string &getLastname() const {
            return lastname;
        }

        int getAge() const {
            return age;
        }

        const string &getColor() const {
            return color;
        }

        void setName(const string &name) {
                xObject::name = name;
        }

        void setLastname(const string &lastname) {
            xObject::lastname = lastname;
        }

        void setAge(int age) {
            xObject::age = age;
        }

        void setColor(const string &color) {
            xObject::color = color;
        }

        template<class Archive>
        void serialize(Archive & archive) {
            archive( name, lastname, age, color ); // serialize things by passing them to the archive
        }


};


#endif //XMEMORY_XOBJECT_H
