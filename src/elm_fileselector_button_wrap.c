#include "include.h"

PREFIX value ml_elm_fileselector_button_add(value v_parent)
{
        Evas_Object* obj = elm_fileselector_button_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_filesselector_button_add");
        return (value) obj;
}

