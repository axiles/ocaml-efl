#include "include.h"

PREFIX value ml_elm_check_add(value v_parent)
{
        Evas_Object* obj = elm_check_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_check_add");
        return (value) obj;
}

