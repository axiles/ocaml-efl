#include "include.h"

PREFIX Elm_Notify_Orient Elm_Notify_Orient_val(value v_o)
{
        switch(v_o) {
                case Val_top: return ELM_NOTIFY_ORIENT_TOP;
                case Val_center: return ELM_NOTIFY_ORIENT_CENTER;
                case Val_bottom: return ELM_NOTIFY_ORIENT_BOTTOM;
                case Val_left: return ELM_NOTIFY_ORIENT_LEFT;
                case Val_right: return ELM_NOTIFY_ORIENT_RIGHT;
                case Val_top_left: return ELM_NOTIFY_ORIENT_TOP_LEFT;
                case Val_top_right: return ELM_NOTIFY_ORIENT_TOP_RIGHT;
                case Val_bottom_left: return ELM_NOTIFY_ORIENT_TOP_LEFT;
                case Val_bottom_right: return ELM_NOTIFY_ORIENT_BOTTOM_RIGHT;
                case Val_last: return ELM_NOTIFY_ORIENT_LAST;
        }
        caml_failwith("Elm_Notify_Orient_val");
        return ELM_NOTIFY_ORIENT_TOP;
}

PREFIX value ml_elm_notify_add(value v_parent)
{
        Evas_Object* obj = elm_notify_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_notify_add");
        return (value) obj;
}

PREFIX value ml_elm_notify_parent_set(value v_obj, value v_parent)
{
        elm_notify_parent_set((Evas_Object*) v_obj, (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_notify_orient_set(value v_obj, value v_o)
{
        elm_notify_orient_set((Evas_Object*) v_obj, Elm_Notify_Orient_val(v_o));
        return Val_unit;
}

PREFIX value ml_elm_notify_allow_events_set(value v_obj, value v_flag)
{
        elm_notify_allow_events_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
}

