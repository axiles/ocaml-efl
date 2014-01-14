#include "include.h"

PREFIX value ml_elm_table_add(value v_parent)
{
        Evas_Object* obj = elm_table_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_table_add");
        return (value) obj;
}

