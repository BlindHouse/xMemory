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


//recordar leer del Cmake

//Función del parser del preprocesador,
// realiza los cambios necesarios en el codigo source y prepara las variables de la serialización


void xPro::xSerializationCheck(const char **token) {

}

void xPro::parser(string path_to_file) {
    bool parsed = false;
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
    xLinkedList* SerializeList = new xLinkedList();
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
        if (token[0]){
            if ((string)token[0] == "//<xL>Parsed"){
                parsed = true;
                break;
            }
        }
        //Ciclo para la comparación, lectura y corte del comentario
        for (int j = 0; j < n; j++) {
            //string temp = "//Bryan_se_la_come_entera";
            string temp_token = (string) token[j];
            if (temp_token == "//<xL>Include") {
                cout<<"Language found"<<"\n";

                if ((string)token[j-3] == "="){
                    cout<<"there's an ="<<"\n";
                    SerializeList->addNode((string)token[j-4], (string)token[j-5]);
                }else{
                    cout<<"there's no =";
                    cout<<(string)token[j-2] <<"\n";
                    SerializeList->addNode((string)token[j-2], (string)token[j-3]);
                }
                //cout << "Language separated from definition: " << temp_token << "\n";
                //token[j] = "";
                //string list;
                //list = ((string)token[-1]).substr(0,((string)token[-1]).size()-2);
                //cout<<list<<"\n";
            }
            if (temp_token == "class"){
                SerializeList->xclassname = ((string)token[j+1]);
                xPro::generatexPointer(SerializeList->xclassname, path_to_file);
                temp_token = ((string)token[j+1]) + ": public xObject";
                cout<<"Class Parsed and xPointer Generated: " + SerializeList->xclassname;
                token[j+1] = (temp_token).c_str();
                token[j+2] = ((string)token[j+2] + "\n" + "public: " + "\n").c_str();
                //cout <<"this is token[j+2]"<<((string)token[j+2])<<"\n";
                //cout <<"this is token[-1]"<< ((string)token[-1])<<"\n";

            }
            string temp_token2;
            temp_token2 = SerializeList->xclassname + "(){";
            if (temp_token == temp_token2){
                cout<<"Constructor found \n";
                temp_token2 = ((string)token[j]) + "\n" + "classname = typeid(*this).name();";
                token[j] = (temp_token2).c_str();
            }
        }

            //cout<<"token[0] is: "<<token[0]<<"\n";
            //ciclo que escribe el nuevo archivo

        for (int i = 0; i < n; i++) {// n = #of tokens
            //cout << "token[i]" << token[i] << "\n";
            //cout << "i: " << i << "\n";
            string temp_token3 = (string)token[i];
            if (temp_token3 == "};"){
                cout<<"token }; found"<<"\n";
                //string temp_token4 = ;
                //cout<<temp_token4 <<"\n";
                fout << (xPro::writeSerialize(SerializeList)  + "\n" + ((string)token[i])).c_str();
                delete(SerializeList);
                xLinkedList* SerializeList = new xLinkedList();
            }else if(temp_token3 == "#endif"){
                //temp_token3 = (string)token[i+1] + "\n"+ "#include <json/value.h>" +"\n" +"#include \"stdlib.h\"\n" + "#include \"iostream\"\n"+"#include \"xObject.h\"\n"+"#include \"sstream\"\n"+"#include <typeinfo>"+ "\n";
                token[i+1] =  (" "+ (string)token[i+1] + "\n"+ "#include <json/value.h>" +"\n" +"#include \"stdlib.h\"\n" + "#include \"iostream\"\n"+"#include \"xObject.h\"\n"+"#include \"sstream\"\n"+"#include <typeinfo>"+ "\n"+ "#include <json/reader.h>" +"\n").c_str();
                fout << token[i];

                //cout << "Token[" << i << "] = " << token[i] << endl;
            }else{
                fout<<token[i];
                fout << " ";
            }
        }//delete(SerializeList);
        fout << "\n";
        cout << endl;
        // process (print) the tokens
        //for (int i = 0; i < n; i++) // n = #of tokens
        //cout << "Token[" << i << "] = " << token[i] << endl;
        //cout << endl;
    }
    if(parsed){
        cout<<"Parsed";
    }else{
        fin.close();
        fout.close();
        remove(path_to_file.c_str());
        rename("/home/disoji/ClionProjects/xMemory/new_file.txt", path_to_file.c_str()); //cambia el nombre del archivo, si se agrega como direccion a otro folder tambien lo cambia.

    }
}

string xPro::writeSerialize(xLinkedList* list) {
    char format[40];
    char bufer[40];
    string code = " ";
    stringstream ss;
    //ifstream fin;

    fstream fin("/home/disoji/ClionProjects/xMemory/xPro/Serialization_Cemplate.txt", ios::in);
    //fin.open("/home/disoji/ClionProjects/xMemory/xPointer/XPointer_Cemplate.txt"); // open a file

    if (!fin.good()) {
        cout << "Serialization_Cemplate.txt Doesn't Exist" << "\n"; // exit if file not found
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
        int j = 0;
        for (j ; j < n ; j++){
            string temp_token = (string)token[j];
            if (temp_token == "//xSerialize"){
                for (xLnode* i = list->firstnode; i!=NULL; i = i->next){
                    code = code + "\n" + " root[ temp ][ " + "\"" + i->NodeString + "\"" + " ]" + " = " + i->NodeString + " ;";
                }
            }else if (temp_token == "//classname"){
                code = code + " " + list->xclassname + " ";

            }else if (temp_token == "//xDeserialize" ){
                for (xLnode* i = list->firstnode; i!=NULL; i = i->next){
                    //code = code + "\n" + "try{"+  i->NodeString + " = " + " root2[temp][ "+ "\"" +i->NodeString+ "\""  + "].toStyledString();}" + "\n" + "catch(...){" + "\n" + i->NodeString + " = " + " root2[temp][ "+ "\"" +i->NodeString+ "\""  + "].asInt();}";
                    if (i->type == "int"){
                        code = code + "\n" +   i->NodeString + " = " + " root2[temp][ "+ "\"" +i->NodeString+ "\""  + "].asInt();";
                    }else if (i->type =="string" ){
                        code = code + "\n" +   i->NodeString + " = " + " root2[temp][ "+ "\"" +i->NodeString+ "\""  + "].asString();";
                    }else if (i->type == "bool"){
                        code = code + "\n" +   i->NodeString + " = " + " root2[temp][ "+ "\"" +i->NodeString+ "\""  + "].asBool();";
                    }else if (i->type == "char*"){
                        code = code + "\n" +   i->NodeString + " = " + " (char*)(root2[temp][ "+ "\"" +i->NodeString+ "\""  + "].asCString);";
                    }else{
                        code = code + "\n" +   i->NodeString + " = " + " root2[temp][ "+ "\"" +i->NodeString+ "\""  + "];";
                    }
                }
            }else{
                code = code + " " + token[j];
            }
        }
        code = code + "\n";
    }
    fin.close();
    return code;
}
/*
xLinkedList* xPro::getPMakeList(string path_to_PMakeLists) {
    char format[40];
    char bufer[40];


    fstream fin("/home/disoji/ClionProjects/xMemory/xPro/PMakeLists.txt", ios::in);
    //fin.open("/home/disoji/ClionProjects/xMemory/xPointer/XPointer_Cemplate.txt"); // open a file

    if (!fin.good()) {
        cout << "PMakeLists.txt Doesn't Exist" << "\n"; // exit if file not found
    }
    // read each line of the file
    xLinkedList* LList = new xLinkedList();
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

        for (int l = 0; l <n; l++){
            string temp_tokenL = (string)token[l];
            LList->addNode(temp_tokenL);
        }
    }
    fin.close();
    return LList;
}*/

void xPro::generatexPointer(string name, string path){
    char format[40];
    char bufer[40];

    //ifstream fin;
    fstream fout("/home/disoji/ClionProjects/xMemory/xPointer/xPointers.h", ios::out | ios::app);//Crea el nuevo archivo con ese nombre.
    fstream fin("/home/disoji/ClionProjects/xMemory/xPointer/XPointer_Cemplate.txt", ios::in);
    //fin.open("/home/disoji/ClionProjects/xMemory/xPointer/XPointer_Cemplate.txt"); // open a file

    if (!fin.good()) {
        cout << "XPointer_Cemplate.txt Doesn't Exist" << "\n"; // exit if file not found
    }
    string temp_tokenI;
    temp_tokenI = "#include \"" + path + "\"";
    fout<< temp_tokenI;
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

        //escribe archivo

        for (int i = 0; i < n; i++) {
            string tempToken = ((string)token[i]);
            if (tempToken == "xPointer"){
                cout<<"after founding xPointer,name: " + name;
                token[i] = ("x" + name ).c_str();
                cout<<"after modifying token[j]: " + (string)token[i];

            }else if (tempToken == "xcontainer"){
                token[i] = (name + "container").c_str();

            }else if (tempToken == "xOb"){
                token[i] = name.c_str();
            }
            fout << token[i] << " ";
        }
        fout << "\n";
    }
    fin.close();
    fout.close();
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