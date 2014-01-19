#include "include.h"

PREFIX value ml_elm_ctxpopup_add(value v_parent)
{
        Evas_Object* ctxpopup = elm_ctxpopup_add((Evas_Object*) v_parent);
        if(ctxpopup == NULL) caml_failwith("elm_ctxpopup_add");
        return (value) ctxpopup;
}

PREFIX value ml_elm_ctxpopup_hover_parent_set(value v_obj, value v_parent)
{
        elm_ctxpopup_hover_parent_set((Evas_Object*) v_obj,
                (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_ctxpopup_hover_parent_get(value v_obj)
{
        return (value) elm_ctxpopup_hover_parent_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_ctxpopup_clear(value v_obj)
{
        elm_ctxpopup_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_ctxpopup_horizontal_set(value v_box, value v_flag)
{
        elm_ctxpopup_horizontal_set((Evas_Object*) v_box, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_ctxpopup_horizontal_get(value v_obj)
{
        return Val_bool(elm_ctxpopup_horizontal_get((Evas_Object*) v_obj));
}

