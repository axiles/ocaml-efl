#include "include.h"

PREFIX value ml_elm_menu_add(value v_parent)
{
        Evas_Object* obj = elm_menu_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_menu_add");
        return (value) obj;
}

PREFIX value ml_elm_menu_parent_set(value v_obj, value v_parent)
{
        elm_menu_parent_set((Evas_Object*) v_obj, (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_menu_parent_get(value v_obj)
{
        return (value) elm_menu_parent_get((Evas_Object*) v_obj);
}

