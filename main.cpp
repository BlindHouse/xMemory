#include <iostream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>

#include "xObject.h"
#include "xMemoryManager/xMemoryManager.h"


int main() {
    std::stringstream ss;
    {
        cereal::JSONOutputArchive oarchive(std::cout); // Create an output archive

        xObject Person = xObject("B", "H", 21, "nigga");
        oarchive(Person); // Write the data to the archive
        cout << ss << endl;
    }
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


    /*{
        cereal::JSONInputArchive iarchive(ss); // Create an input archive

        xObject Person = xObject("B", "H", 21, "nigga");
        iarchive(Person); // Read the data from the archive
    }*/
}
