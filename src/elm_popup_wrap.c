#include "include.h"

PREFIX value ml_elm_popup_add(value v_parent)
{
        Evas_Object* popup = elm_popup_add((Evas_Object*) v_parent);
        if(popup == NULL) caml_failwith("elm_popup_add");
        return (value) popup;
}

