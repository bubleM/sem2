#include "List.h"
#include <cstdlib>

bool Object::Insert(void* data) {
    bool rc = false;
    if (!Head) {
        Head = new Element(nullptr, data, nullptr);
        rc = true;
    }
    else {
        Head = (Head->Prev = new Element(nullptr, data, Head));
        rc = true;
    }
    return rc;
}

Element* Object::Search(void* data) {
    Element* rc = Head;
    while (rc && rc->Data != data)
        rc = rc->Next;
    return rc;
}

void Object::PrintList(void(*f)(void*)) {
    Element* e = Head;
    while (e) {
        f(e->Data);
        e = e->Next;
    }
}

bool Object::Delete(Element* e) {
    if (!e) return false;
    if (e->Next) e->Next->Prev = e->Prev;
    if (e->Prev) e->Prev->Next = e->Next;
    else Head = e->Next;
    delete e;
    return true;
}

bool Object::Delete(void* data) {
    return Delete(Search(data));
}

int Object::CountList() {
    int count = 0;
    Element* current = Head;
    while (current) {
        count++;
        current = current->Next;
    }
    return count;
}

bool Object::DeleteList() {
    Element* current = Head;
    while (current) {
        Element* next = current->Next;
        delete current;
        current = next;
    }
    Head = nullptr;
    return true;
}

Object Create() {
    return *(new Object());
}
