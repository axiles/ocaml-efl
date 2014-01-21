#include "include.h"

PREFIX inline Elm_Panel_Orient Elm_Panel_Orient_val(value v)
{
        switch(v) {
                case Val_top: return ELM_PANEL_ORIENT_TOP;
                case Val_bottom: return ELM_PANEL_ORIENT_BOTTOM;
                case Val_left: return ELM_PANEL_ORIENT_LEFT;
                case Val_right: return ELM_PANEL_ORIENT_RIGHT;
                default: break;
        }
        caml_failwith("Elm_Panel_Orient_val");
        return ELM_PANEL_ORIENT_TOP;
}

PREFIX inline value Val_Elm_Panel_Orient(Elm_Panel_Orient o)
{
        switch(o) {
                case ELM_PANEL_ORIENT_TOP: return Val_top;
                case ELM_PANEL_ORIENT_BOTTOM: return Val_bottom;
                case ELM_PANEL_ORIENT_LEFT: return Val_left;
                case ELM_PANEL_ORIENT_RIGHT: return Val_right;
        }
        caml_failwith("Val_Elm_Panel_Orient");
        return Val_top;
}

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

