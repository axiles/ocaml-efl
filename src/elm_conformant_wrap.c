#include "include.h"

PREFIX value ml_elm_conformant_add(value v_parent)
{
        Evas_Object* obj = elm_conformant_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_conformant_add");
        return copy_Evas_Object(obj);
}

