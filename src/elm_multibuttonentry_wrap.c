#include "include.h"

PREFIX value ml_elm_multibuttonentry_add(value v_parent)
{
        Evas_Object* obj = elm_multibuttonentry_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_multibuttonentry_add");
        return (value) obj;
}

PREFIX value ml_elm_multibuttonentry_entry_get(value v_obj)
{
        return copy_Evas_Object_opt(elm_multibuttonentry_entry_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_multibuttonentry_expanded_get(value v_obj)
{
        return Val_bool(elm_multibuttonentry_expanded_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_multibuttonentry_expanded_set(value v_obj, value v_flag)
{
        elm_multibuttonentry_expanded_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_multibuttonentry_item_prepend(
        value v_obj, value v_label, value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
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
        Elm_Object_Item* item = elm_multibuttonentry_item_prepend(
                (Evas_Object*) v_obj, label, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_multibuttonentry_item_prepend");
        }
        return (value) item;
}

PREFIX value ml_elm_multibuttonentry_item_append(
        value v_obj, value v_label, value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
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
        Elm_Object_Item* item = elm_multibuttonentry_item_append(
                (Evas_Object*) v_obj, label, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_multibuttonentry_item_append");
        }
        return (value) item;
}

