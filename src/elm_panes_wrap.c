#include "include.h"

PREFIX value ml_elm_panes_add(value v_parent)
{
        Evas_Object* obj = elm_panes_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_panes_add");
        return copy_Evas_Object(obj);
}

