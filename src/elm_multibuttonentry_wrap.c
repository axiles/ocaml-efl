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

PREFIX value ml_elm_multibuttonentry_item_insert_before(
        value v_obj, value v_before, value v_label, value v_func, value v_unit)
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
        Elm_Object_Item* item = elm_multibuttonentry_item_insert_before(
                (Evas_Object*) v_obj, (Elm_Object_Item*) v_before,
                label, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_multibuttonentry_item_insert_before");
        }
        return (value) item;
}

PREFIX value ml_elm_multibuttonentry_item_insert_after(
        value v_obj, value v_after, value v_label, value v_func, value v_unit)
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
        Elm_Object_Item* item = elm_multibuttonentry_item_insert_after(
                (Evas_Object*) v_obj, (Elm_Object_Item*) v_after,
                label, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_multibuttonentry_item_insert_after");
        }
        return (value) item;
}

PREFIX value ml_elm_multibuttonentry_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_multibuttonentry_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_multibuttonentry_first_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_multibuttonentry_first_item_get(
                (Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_multibuttonentry_last_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_multibuttonentry_last_item_get(
                (Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_multibuttonentry_selected_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_multibuttonentry_selected_item_get((Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_multibuttonentry_item_selected_set(value v_it, value v_flag)
{
        elm_multibuttonentry_item_selected_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_multibuttonentry_item_selected_get(value v_it)
{
        return Val_bool(elm_multibuttonentry_item_selected_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_multibuttonentry_clear(value v_obj)
{
        elm_multibuttonentry_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_multibuttonentry_item_prev_get(value v_it)
{
        Elm_Object_Item* it1 = elm_multibuttonentry_item_prev_get(
                (Elm_Object_Item*) v_it);
        if(it1 == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it1);
        return v;
}

PREFIX value ml_elm_multibuttonentry_item_next_get(value v_it)
{
        Elm_Object_Item* it1 = elm_multibuttonentry_item_next_get(
                (Elm_Object_Item*) v_it);
        if(it1 == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it1);
        return v;
}

PREFIX value ml_elm_multibuttonentry_editable_set(value v_obj, value v_flag)
{
        elm_multibuttonentry_editable_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_multibuttonentry_editable_get(value v_obj)
{
        return Val_bool(elm_multibuttonentry_editable_get(
                (Evas_Object*) v_obj));
}

