#include "include.h"

PREFIX value ml_elm_multibuttonentry_add(value v_parent)
{
        Evas_Object* obj = elm_multibuttonentry_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_multibuttonentry_add");
        return (value) obj;
}

