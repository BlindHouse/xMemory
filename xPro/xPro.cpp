//
// Created by disoji on 23/03/16.
//

#define _CRT_SECURE_NO_WARNINGS

#include "xPro.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_CHARS_PER_LINE = 512;//Limite de caracteres en la linea, recordar cambiarlo
const int MAX_TOKENS_PER_LINE = 20;//Limite de tokens (palabras) por linea, recordar cambiarlo
const char* const DELIMITER = " ";//Delimitador

/*
 * Recordar agregar el caso en que el comentario del language esté pegado a la definición
 * Dejar entradas y demás listas
 * preparar lo que falta en el enunciado
 *
 * recordar que es necesario leer del CMake para saber que archivos leer
 * ver si es necesario solo los .cpp o también los .h (casi seguro que también los .h)*/

void xPro::parser()
{
    cout<<"Que putas mae"<<"\n";
    char format[20];
    char bufer[20];
    // create a file-reading object
    cout<<"antes de Crea new_file.txt"<<"\n";
    ifstream fin;
    fstream fout("/home/disoji/ClionProjects/xMemory/new_file.txt",ios::out);//Crea el nuevo archivo con ese nombre.
    cout<<"Crea new_file.txt"<<"\n";
    fout.close();
    fout.open("/home/disoji/ClionProjects/xMemory/new_file.txt");
    fin.open("/home/disoji/ClionProjects/xMemory/xPro/xPro.cpp"); // open a file
    cout<<"abre xObject.cpp y new_file.txt"<<"\n";

    if (!fin.good()) {
        cout << "File Doesn't Exist" << "\n"; // exit if file not found
    }
    // read each line of the file
    while (!fin.eof())
    {
        // read an entire line into memory
        char buf[MAX_CHARS_PER_LINE];
        fin.getline(buf, MAX_CHARS_PER_LINE);

        // parse the line into blank-delimited tokens
        int n = 0; // a for-loop index

        // array to store memory addresses of the tokens in buf
        const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

        // parse the line
        token[0] = strtok(buf, DELIMITER); // first token
        if (token[0]) // zero if line is blank
        {
            for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
            {
                token[n] = strtok(0, DELIMITER); // subsequent tokens
                if (!token[n]) break; // no more tokens
            }
        }

        //Ciclo para la comparación, lectura y corte del comentario
        for (int j=0; j < n; j++){
            string temp = "xPro";
            if (((string)token[j]).compare(temp) == 0){

                cout<<"Yep maaan: "<<token[j]<<"\n";
                token[j] = "xPro/xPro.h";
                /*
                sprintf(format, "%%%ds", 6);//Genera el formato para el sscanf
                sscanf(token[j], format, bufer);//Lee la cantidad dada por format de token[j] y lo mete en bufer
                string a;
                a = (string)token[j];//conversion a string del token[j]
                a.erase(0,2);//Borra los elementos [0,2[
                cout<<"Yep cambiado a:"<<token[j]<<"--format es: "<<a<<"\n";*/

            } else{
                cout<<"WTF: "<<token[j]<<"\n";
                //cout<<typeid(token[j]).name()<<"\n";
            }
        }

        //ciclo que escribe el nuevo archivo
        for (int i = 0; i < n; i++){// n = #of tokens
            fout<<token[i];
            fout<<" ";
            //cout << "Token[" << i << "] = " << token[i] << endl;
        }
        fout<<"\n";
        cout << endl;
        // process (print) the tokens
        for (int i = 0; i < n; i++) // n = #of tokens
            cout << "Token[" << i << "] = " << token[i] << endl;
            cout << endl;
    }
    rename("/home/disoji/ClionProjects/xMemory/new_file.txt", "/home/disoji/ClionProjects/xMemory/new_file.cpp"); //cambia el nombre del archivo, si se agrega como direccion a otro folder tambien lo cambia.

}
//Fuck