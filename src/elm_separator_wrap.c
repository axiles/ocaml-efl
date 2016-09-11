#include "include.h"

PREFIX value ml_elm_separator_add(value v_parent)
{
        Evas_Object* obj = elm_separator_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_separator_add");
        return copy_Evas_Object(obj);
}

