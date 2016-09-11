#include "include.h"

PREFIX value ml_elm_panel_add(value v_parent)
{
        Evas_Object* panel = elm_panel_add(Evas_Object_val(v_parent));
        if(panel == NULL) caml_failwith("elm_panel_add");
        return copy_Evas_Object(panel);
}

