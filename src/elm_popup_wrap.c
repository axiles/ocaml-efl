#include "include.h"

PREFIX inline Elm_Popup_Orient Elm_Popup_Orient_val(value v)
{
        switch(v) {
                case Val_top: return ELM_POPUP_ORIENT_TOP;
                case Val_center: return ELM_POPUP_ORIENT_CENTER;
                case Val_bottom: return ELM_POPUP_ORIENT_BOTTOM;
                case Val_left: return ELM_POPUP_ORIENT_LEFT;
                case Val_right: return ELM_POPUP_ORIENT_RIGHT;
                case Val_top_left: return ELM_POPUP_ORIENT_TOP_LEFT;
                case Val_top_right: return ELM_POPUP_ORIENT_TOP_RIGHT;
                case Val_bottom_left: return ELM_POPUP_ORIENT_BOTTOM_LEFT;
                case Val_bottom_right: return ELM_POPUP_ORIENT_BOTTOM_RIGHT;
                case Val_last: return ELM_POPUP_ORIENT_LAST;
                default: break;
        }
        caml_failwith("Elm_Popup_Orient_val");
        return ELM_POPUP_ORIENT_TOP;
}

PREFIX inline value Val_Elm_Popup_Orient(Elm_Popup_Orient o)
{
        switch(o) {
                case ELM_POPUP_ORIENT_TOP: return Val_top;
                case ELM_POPUP_ORIENT_CENTER: return Val_center;
                case ELM_POPUP_ORIENT_BOTTOM: return Val_bottom;
                case ELM_POPUP_ORIENT_LEFT: return Val_left;
                case ELM_POPUP_ORIENT_RIGHT: return Val_right;
                case ELM_POPUP_ORIENT_TOP_LEFT: return Val_top_left;
                case ELM_POPUP_ORIENT_TOP_RIGHT: return Val_top_right;
                case ELM_POPUP_ORIENT_BOTTOM_LEFT: return Val_bottom_left;
                case ELM_POPUP_ORIENT_BOTTOM_RIGHT: return Val_bottom_right;
                case ELM_POPUP_ORIENT_LAST: return Val_last;
        }
        caml_failwith("Val_Elm_Popup_Orient");
        return Val_top;
}

PREFIX value ml_elm_popup_add(value v_parent)
{
        Evas_Object* popup = elm_popup_add((Evas_Object*) v_parent);
        if(popup == NULL) caml_failwith("elm_popup_add");
        return (value) popup;
}

PREFIX value ml_elm_popup_item_append(
        value v_obj, value v_label, value v_icon, value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = (Evas_Object*) Field(v_icon, 0);
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_popup_item_append((Evas_Object*) v_obj,
                label, icon, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_popup_item_append");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return (value) item;
}

PREFIX value ml_elm_popup_content_text_wrap_type_set(value v_obj, value v_wrap)
{
        elm_popup_content_text_wrap_type_set((Evas_Object*) v_obj,
                Elm_Wrap_Type_val(v_wrap));
        return Val_unit;
}

PREFIX value ml_elm_popup_content_text_wrap_type_get(value v_obj)
{
        return Val_Elm_Wrap_Type(elm_popup_content_text_wrap_type_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_popup_orient_set(value v_obj, value v_orient)
{
        elm_popup_orient_set((Evas_Object*) v_obj,
                Elm_Popup_Orient_val(v_orient));
        return Val_unit;
}

PREFIX value ml_elm_popup_orient_get(value v_obj)
{
        return Val_Elm_Popup_Orient(elm_popup_orient_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_popup_timeout_set(value v_obj, value v_x)
{
        elm_popup_timeout_set((Evas_Object*) v_obj, Double_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_popup_timeout_get(value v_obj)
{
        return copy_double(elm_popup_timeout_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_popup_allow_events_set(value v_obj, value v_flag)
{
        elm_popup_allow_events_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_popup_allow_events_get(value v_obj)
{
        return Val_Eina_Bool(elm_popup_allow_events_get((Evas_Object*) v_obj));
}

