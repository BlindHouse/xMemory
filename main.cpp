


#include <fstream>

#include "xObject.h"
#include "xMemoryManager/xMemoryManager.h"
#include "xPro/xPro.h"




int main(){
    cout<<"Proyecto XMemory \n";
    xObject o("Juean", "Del Rancho", 69, "negro");
    cout<<"Before Deserialize: "<<o.getName()<<"\n";
    o.deserialize("Vagina");
    cout<<"After Desirialize: "<<o.getName()<<"\n";

}






















/*


#include <cpplexer/cpp_lex_token.hpp>
#include "wave/trace_policies.hpp"
#include "wave/language_support.hpp"
#include "wave/cpp_iteration_context.hpp"
#include "wave/cpp_context.hpp"
#include "wave/cpp_exceptions.hpp"


int main() {

    std::ifstream instream("input.cpp");
    std::string input(std::istreambuf_iterator<char>(instream.rdbuf()),std::istreambuf_iterator<char>());

// The template wave::cpplexer::lex_token<> is the default
// token type to be used by the Wave library.
// This token type is one of the central types throughout
// the library, because it is a template parameter to many
// of the public classes and templates and it is returned
// from the iterators itself.
    typedef wave::context <std::string::iterator,
    wave::cpplexer::lex_token<>>
            context_t;

// The C++ preprocessor iterators shouldn't be constructed
// directly. These are to be generated through a
// wave::context<> object. Additionally this wave::context<>
// object is to be used to initialize and define different
// parameters of the actual preprocessing.
    context_t ctx(input.begin(), input.end(), "input.cpp");
    context_t::iterator_t first = ctx.begin();
    context_t::iterator_t last = ctx.end();

// The preprocessing of the input stream is done on the fly
// behind the scenes during the iteration over the
// context_t::iterator_t based stream.
    while (first != last) {
        std::cout << (*first).get_value();
        ++first;
    }
}*/
     /*
    std::stringstream ss;
    {
        cereal::JSONOutputArchive oarchive(std::cout); // Create an output archive

        xObject Person = xObject("B", "H", 21, "nigga");
        oarchive(Person); // Write the data to the archive
        cout << ss << endl;
        std::cout<<typeid(Person).name()<<"\n";
        //std::cout<<"Nombre de la clase de Person, debería ser xObject:---"<<Person.getClassName()<<"\n";
    }
    xMemoryManager MM;

    float a;
    string b = typeid(MM).name();
    std::cout<<b[1]<<"\n";
    std::cout<<typeid(MM).name()<<"\n";
    std::cout<<typeid(a).name()<<"\n";
    std::cout<<"Nombre de la clase de MM, debería ser xMemoryManager:---"<<MM.getClassName()<<"\n";*/

    /*
    xMemoryManager MM = xMemoryManager();
    std::cout<<sizeof(MM.AviableMem)<<"fuck"<<"\n";
    std::cout<<MM.AviableMem<<"----"<<MM.AviableMem+1<<"\n";
    int* a = new(int);
    std::cout<<a<<"----"<<a+1<<"\n";
    int b= 5;
    int c = 12;
    int* d = new(int);
    a = &b;
    d = a+1;
    d=&c;
    std::cout<<*a<<"----"<<*(a+1)<<"\n";
    std::cout<<a<<"\n";
    std::cout<<d<<"\n";
    a=d;
    d=(d+1);
    std::cout<<a<<"\n";
    std::cout<<d<<"\n";
    void* e = 0;
    std::cout<<"Valor de AM a priori:- "<<MM.AviableMem<<"\n";
    e = MM.xMalloc(2);
    std::cout<<"valor de e:- "<<e<<"\n";
    std::cout<<"Valor de AM:- "<<MM.AviableMem<<"\n";
     */

    /*{
        cereal::JSONInputArchive iarchive(ss); // Create an input archive

        xObject Person = xObject("B", "H", 21, "nigga");
        iarchive(Person); // Read the data from the archive
    }
}*/