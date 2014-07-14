#include "include.h"

PREFIX value ml_elm_panel_add(value v_parent)
{
        Evas_Object* panel = elm_panel_add((Evas_Object*) v_parent);
        if(panel == NULL) caml_failwith("elm_panel_add");
        return (value) panel;
}

PREFIX value ml_elm_panel_orient_set(value v_obj, value v_orient)
{
        elm_panel_orient_set((Evas_Object*) v_obj,
                Elm_Panel_Orient_val(v_orient));
        return Val_unit;
}

PREFIX value ml_elm_panel_orient_get(value v_obj)
{
        return Val_Elm_Panel_Orient(elm_panel_orient_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_panel_hidden_set(value v_obj, value v_flag)
{
        elm_panel_hidden_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_panel_hidden_get(value v_obj)
{
        return Val_bool(elm_panel_hidden_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_panel_toggle(value v_obj)
{
        elm_panel_toggle((Evas_Object*) v_obj);
        return Val_unit;
}

