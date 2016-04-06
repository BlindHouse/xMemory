//
// Created by disoji on 23/03/16.
//

#ifndef XMEMORY_XPRO_H
#define XMEMORY_XPRO_H

#include "stdlib.h"
#include <iostream>
using namespace std;

class xPro {
public:
    //Función del parser del preprocesador
    static void parser(string path_to_file);
    //static bool has_language(string Token);
    //static const char* replace(const char* token, unsigned long tempPos);
};


#endif //XMEMORY_XPRO_H
