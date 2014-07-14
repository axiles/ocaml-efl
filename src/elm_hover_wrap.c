#include "include.h"

/*inline Elm_Hover_Axis Elm_Hover_Axis_val(value v)
{
        switch(v) {
                case Val_none: return ELM_HOVER_AXIS_NONE;
                case Val_horizontal: return ELM_HOVER_AXIS_HORIZONTAL;
                case Val_vertical: return ELM_HOVER_AXIS_VERTICAL;
                case Val_both: return ELM_HOVER_AXIS_BOTH;
        }
        caml_failwith("Elm_Hover_Axis_val");
        return ELM_HOVER_AXIS_NONE;
}*/

PREFIX value ml_elm_hover_add(value v_parent)
{
        Evas_Object* obj = elm_hover_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_hover_add");
        return (value) obj;
}

PREFIX value ml_elm_hover_target_set(value v_obj, value v_target)
{
        elm_hover_target_set((Evas_Object*) v_obj, (Evas_Object*) v_target);
        return Val_unit;
}

PREFIX value ml_elm_hover_target_get(value v_obj)
{
        Evas_Object* target = elm_hover_target_get((Evas_Object*) v_obj);
        if(target == NULL) caml_failwith("elm_hover_target_get");
        return (value) target;
}

PREFIX value ml_elm_hover_parent_set(value v_obj, value v_parent)
{
        elm_hover_parent_set((Evas_Object*) v_obj, (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_hover_parent_get(value v_obj)
{
        Evas_Object* parent = elm_hover_parent_get((Evas_Object*) v_obj);
        if(parent == NULL) caml_failwith("elm_hover_parent_get");
        return (value) parent;
}

PREFIX value ml_elm_hover_best_content_location_get(value v_obj, value v_axis)
{
        CAMLparam2(v_obj, v_axis);
        CAMLlocal1(v_loc);
        const char* loc = elm_hover_best_content_location_get(
                (Evas_Object*) v_obj, Elm_Hover_Axis_val(v_axis));
        if(loc == NULL) v_loc = Val_int(0);
        else {
                v_loc = caml_alloc(1, 0);
                Store_field(v_loc, 0, copy_string(loc));
        }
        CAMLreturn(v_loc);
}

PREFIX value ml_elm_hover_dismiss(value v_obj)
{
        elm_hover_dismiss((Evas_Object*) v_obj);
        return Val_unit;
}

