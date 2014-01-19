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

PREFIX value ml_elm_ctxpopup_item_append(
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
                data = (value*) caml_stat_alloc(sizeof(value));
                *data = Field(v_func, 0);
                caml_register_global_root(data);
        }
        Elm_Object_Item* item = elm_ctxpopup_item_append((Evas_Object*) v_obj,
                label, icon, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_ctxpopup_item_append");
        }
        return (value) item;
}

