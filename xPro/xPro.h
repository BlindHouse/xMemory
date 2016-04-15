//
// Created by disoji on 23/03/16.
//

#ifndef XMEMORY_XPRO_H
#define XMEMORY_XPRO_H

#include "stdlib.h"
#include <iostream>
#include "/home/disoji/ClionProjects/xMemory/Tools.h"

using namespace std;

class xPro {
public:
    //Función del parser del preprocesador
    static void parser(string path_to_file);
    //static void writeCemplate(string Cemplate_path);
    //static xLinkedList* makeFileList(string pathToFile);
    void xSerializationCheck(const char* token[]);
    //void writeSerializationCemplate(string pathToCemplate);
    //string getAtribute(const char* token[]);
    static void generatexPointer(string name, string path);
    static string writeSerialize(xLinkedList* list);
    static xLinkedList* getPMakeList(string path_to_PMakeLists);

    //static bool has_language(string Token);
    //static const char* replace(const char* token, unsigned long tempPos);
};


#endif //XMEMORY_XPRO_H
