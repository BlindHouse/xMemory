//
// Created by disoji on 23/03/16.
//
/*
 * Dividir en varios parseadores, uno para los includes, que haga un string en forma de [] (lista de elementos)
 * Y que devuelva un wrapper con el string y un entero de cuantos elementos tiene
 * Otro para que ponga las herencias y ecriba la definicion de la lista, recordar ver las comillas
 * Otro para las versiones que cambie los nombres de las funciones
 * revisar el hecho de que dos clases puedan estar en el mismo archivo
 * comprobar si es necesario solo parsear .h o tambien .cpp (preguntar al profe)
 * probrar si el error de funcionamiento anomalo se debe a el resuso de variables definidas en stack con el mismo tag.
*/

#define _CRT_SECURE_NO_WARNINGS

#include "xPro.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_CHARS_PER_LINE = 1024;//Limite de caracteres en la linea, recordar cambiarlo
const int MAX_TOKENS_PER_LINE = 50;//Limite de tokens (palabras) por linea, recordar cambiarlo
const char* const DELIMITER = " ";//Delimitador
#include <new>
/*
 * Recordar agregar el caso en que el comentario del language esté pegado a la definición
 * Dejar entradas y demás listas
 * preparar lo que falta en el enunciado
 *
 * recordar que es necesario leer del CMake para saber que archivos leer
 * ver si es necesario solo los .cpp o también los .h (casi seguro que también los .h)*/
//Función del parser del preprocesador,
// realiza los cambios necesarios en el codigo source y prepara las variables de la serialización
void xPro::parser(string path_to_file) {
    char format[40];
    char bufer[40];
    // create a file-reading object
    cout << "antes de Crea new_file.txt" << "\n";
    ifstream fin;
    fstream fout("/home/disoji/ClionProjects/xMemory/new_file.txt", ios::out);//Crea el nuevo archivo con ese nombre.
    cout << "Crea new_file.txt" << "\n";
    fout.close();
    fout.open("/home/disoji/ClionProjects/xMemory/new_file.txt");
    fin.open(path_to_file); // open a file
    cout << "Abre xObject.cpp y new_file.txt" << "\n";

    if (!fin.good()) {
        cout << "File Doesn't Exist" << "\n"; // exit if file not found
    }
    // read each line of the file
    while (!fin.eof()) {
        // read an entire line into memory
        char buf[MAX_CHARS_PER_LINE];
        fin.getline(buf, MAX_CHARS_PER_LINE);

        // parse the line into blank-delimited tokens
        int n = 0; // a for-loop index

        // array to store memory addresses of the tokens in buf
        const char *token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

        // parse the line
        token[0] = strtok(buf, DELIMITER); // first token
        if (token[0]) // zero if line is blank
        {
            for (n = 1; n < MAX_TOKENS_PER_LINE; n++) {
                token[n] = strtok(0, DELIMITER); // subsequent tokens
                if (!token[n]) break; // no more tokens
            }
        }

        //Ciclo para la comparación, lectura y corte del comentario
        for (int j = 0; j < n; j++) {
            //string temp = "//Bryan_se_la_come_entera";
            string temp_token = (string) token[j];
            if (temp_token == "//<xL>Include") {
                cout << "Language separated from definition: " << temp_token << "\n";
                token[j] = "";
                //string list;
                //list = ((string)token[-1]).substr(0,((string)token[-1]).size()-2);
                //cout<<list<<"\n";
            }
            if (temp_token == "class"){
                temp_token = ((string)token[j+1]) + ": public xObject";
                token[j+1] = (temp_token).c_str();
            }

            /*
            if (has_language(temp_token)) {

                    string definition = " ";
                    cout << "Language with definition: " << temp_token << "\n";
                    unsigned long pos = temp_token.find("e");
                    cout << pos << "\n";
                    definition = temp_token.substr(pos + 1, temp_token.length() - 1);
                    cout << definition << "\n";
                    const char *def;
                    def = definition.c_str();
                    token[j] = " ";
                    token[j] = def;
                    cout << "This is the token with the problem: " << token[j] << "\n";

                    sprintf(format, "%%%ds", 6);//Genera el formato para el sscanf
                    sscanf(token[j], format, bufer);//Lee la cantidad dada por format de token[j] y lo mete en bufer
                    string a;
                    a = (string)token[j];//conversion a string del token[j]
                    a.erase(0,2);//Borra los elementos [0,2[
                    cout<<"Yep cambiado a:"<<token[j]<<"--format es: "<<a<<"\n";


            }*/
        }
            //cout<<"token[0] is: "<<token[0]<<"\n";
            //ciclo que escribe el nuevo archivo
            for (int i = 0; i < n; i++) {// n = #of tokens
                cout << "token[i]" << token[i] << "\n";
                cout << "i: " << i << "\n";
                fout << token[i];
                fout << " ";
                //cout << "Token[" << i << "] = " << token[i] << endl;
            }
            fout << "\n";
            cout << endl;
            // process (print) the tokens
            //for (int i = 0; i < n; i++) // n = #of tokens
            //cout << "Token[" << i << "] = " << token[i] << endl;
            //cout << endl;
        }
        fin.close();
        fout.close();
        remove(path_to_file.c_str());
        rename("/home/disoji/ClionProjects/xMemory/new_file.txt", path_to_file.c_str()); //cambia el nombre del archivo, si se agrega como direccion a otro folder tambien lo cambia.
    }

/*
bool xPro::has_language(string Token) {
    if (Token.find("//<xL>Include") != string::npos){
        cout<<"Language found, erasing it..."<<"\n";
        return true;
    }else{
        cout<<"Nope"<<"\n";
        return false;
    }
}


const char* xPro::replace(const char* token,unsigned long tempPos){
    const char* temp_token;
    temp_token = token;
    temp_token = (((string)(temp_token)).insert((size_t)(tempPos-1), (const string&)(": public xObject ")).c_str()) ;
    token =(temp_token);
    return token;
}*/
//Fuck