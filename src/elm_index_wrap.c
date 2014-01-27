#include "include.h"

PREFIX value ml_elm_index_add(value v_parent)
{
        Evas_Object* obj = elm_index_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_index_add");
        return (value) obj;
}

