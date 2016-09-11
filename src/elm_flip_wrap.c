#include "include.h"

PREFIX value ml_elm_flip_add(value v_parent)
{
        Evas_Object* flip = elm_flip_add(Evas_Object_val(v_parent));
        if(flip == NULL) caml_failwith("elm_flip_add");
        return copy_Evas_Object(flip);
}

