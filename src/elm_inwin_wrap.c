#include "include.h"

PREFIX value ml_elm_win_inwin_add(value v_parent)
{
        Evas_Object* obj = elm_win_inwin_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_win_inwin_add");
        return (value) obj;
}

PREFIX value ml_elm_win_inwin_activate(value v_obj)
{
        elm_win_inwin_activate((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_inwin_content_set(value v_obj, value v_content)
{
        elm_win_inwin_content_set((Evas_Object*) v_obj,
                (Evas_Object*) v_content);
        return Val_unit;
}

