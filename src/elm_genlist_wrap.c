#include "include.h"

PREFIX value ml_elm_genlist_add(value v_parent)
{
        Evas_Object* obj = elm_genlist_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_genlist_add");
        return (value) obj;
}

