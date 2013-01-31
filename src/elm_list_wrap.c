#include "include.h"

PREFIX ml_elm_list_add(value v_parent)
{
        Evas_Object* obj = elm_list_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_list_add");
        return (value) obj;
}

