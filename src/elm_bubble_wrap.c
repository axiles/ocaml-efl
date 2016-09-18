#include "include.h"

PREFIX value ml_elm_bubble_add(value v_parent)
{
        Evas_Object* bubble = elm_bubble_add(Evas_Object_val(v_parent));
        if(bubble == NULL) caml_failwith("elm_bubble_add");
        return copy_Evas_Object(bubble);
}

