#include "xPointer.h"

template <class t>
xPointer<t>::xPointer(long ID) {

    MemTable * Manager;
    ObjectID = ID;
    InitialPosition = Manager->GetPosition(ID);
    CurrentPosition = InitialPosition;
    Size = Manager->GetSize(ID);
}

template <class t>
int xPointer<t>::add(t item) {
    int space = sizeof(item);

    return 0;
}


