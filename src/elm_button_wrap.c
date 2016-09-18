#include "include.h"

PREFIX value ml_elm_button_add(value v_parent)
{
        Evas_Object* button = elm_button_add(Evas_Object_val(v_parent));
        if(button == NULL) caml_failwith("elm_button_add");
        return copy_Evas_Object(button);
}

