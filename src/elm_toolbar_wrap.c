#include "include.h"

PREFIX value ml_elm_toolbar_add(value v_parent)
{
        Evas_Object* obj = elm_toolbar_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_toolbar_add");
        return (value) obj;
}

PREFIX value ml_elm_toolbar_icon_size_set(value v_obj, value v_size)
{
        elm_toolbar_icon_size_set((Evas_Object*) v_obj, Int_val(v_size));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_icon_size_get(value v_obj)
{
        return Val_int(elm_toolbar_icon_size_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_icon_order_lookup_set(value v_obj, value v_order)
{
        elm_toolbar_icon_order_lookup_set((Evas_Object*) v_obj,
                Elm_Icon_Lookup_Order_val(v_order));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_icon_order_lookup_get(value v_obj)
{
        return Val_Elm_Icon_Lookup_Order(elm_toolbar_icon_order_lookup_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_toolbar_item_append(
        value v_obj, value v_icon, value v_label, value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        const char* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = String_val(Field(v_icon, 0));
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
        Elm_Object_Item* item = elm_toolbar_item_append((Evas_Object*) v_obj,
                icon, label, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_toolbar_item_append");
        }
        return (value) item;
}

PREFIX value ml_elm_toolbar_item_prepend(
        value v_obj, value v_icon, value v_label, value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        const char* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = String_val(Field(v_icon, 0));
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
        Elm_Object_Item* item = elm_toolbar_item_prepend((Evas_Object*) v_obj,
                icon, label, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_toolbar_item_prepend");
        }
        return (value) item;
}

PREFIX value ml_elm_toolbar_item_insert_before_native(
        value v_obj, value v_before, value v_icon, value v_label, value v_func,
        value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        const char* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = String_val(Field(v_icon, 0));
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
        Elm_Object_Item* item = elm_toolbar_item_insert_before(
                (Evas_Object*) v_obj, (Elm_Object_Item*) v_before, icon, label,
                func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_toolbar_item_insert_before");
        }
        return (value) item;
}

PREFIX value ml_elm_toolbar_item_insert_before_byte(value* argv, int argn)
{
        return ml_elm_toolbar_item_insert_before_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_toolbar_item_insert_after_native(
        value v_obj, value v_after, value v_icon, value v_label, value v_func,
        value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        const char* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = String_val(Field(v_icon, 0));
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
        Elm_Object_Item* item = elm_toolbar_item_insert_after(
                (Evas_Object*) v_obj, (Elm_Object_Item*) v_after, icon, label,
                func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_toolbar_item_insert_after");
        }
        return (value) item;
}

PREFIX value ml_elm_toolbar_item_insert_after_byte(value* argv, int argn)
{
        return ml_elm_toolbar_item_insert_after_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_toolbar_first_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_toolbar_first_item_get((Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_toolbar_last_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_toolbar_last_item_get((Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_toolbar_item_next_get(value v_it)
{
        Elm_Object_Item* it1 = elm_toolbar_item_next_get(
                (Elm_Object_Item*) v_it);
        if(it1 == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it1);
        return v;
}

PREFIX value ml_elm_toolbar_item_prev_get(value v_it)
{
        Elm_Object_Item* it1 = elm_toolbar_item_prev_get(
                (Elm_Object_Item*) v_it);
        if(it1 == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it1);
        return v;
}

PREFIX value ml_elm_toolbar_item_priority_set(value v_it, value v_x)
{
        elm_toolbar_item_priority_set((Elm_Object_Item*) v_it, Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_item_priority_get(value v_it)
{
        return Val_int(elm_toolbar_item_priority_get((Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_toolbar_item_find_by_label(value v_obj, value v_label)
{
       Elm_Object_Item* it = elm_toolbar_item_find_by_label(
               (Evas_Object*) v_obj, String_val(v_label));
       if(it == NULL) return Val_int(0);
       value v_it = caml_alloc(1, 0);
       Store_field(v_it, 0, (value) it);
       return (value) v_it;
}

PREFIX value ml_elm_toolbar_selected_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_toolbar_selected_item_get((Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_toolbar_more_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_toolbar_more_item_get((Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_toolbar_item_icon_set(value v_it, value v_icon)
{
        elm_toolbar_item_icon_set((Elm_Object_Item*) v_it, String_val(v_icon));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_item_icon_get(value v_it)
{
        const char* icon = elm_toolbar_item_icon_get((Elm_Object_Item*) v_it);
        if(icon == NULL) caml_failwith("elm_toolbar_item_icon_get");
        return copy_string(icon);
}

PREFIX value ml_elm_toolbar_item_object_get(value v_it)
{
        Evas_Object* obj = elm_toolbar_item_object_get((Elm_Object_Item*) v_it);
        if(obj == NULL) caml_failwith("elm_toolbar_item_object_get");
        return (value) obj;
}

PREFIX value ml_elm_toolbar_item_icon_object_get(value v_it)
{
        Evas_Object* obj = elm_toolbar_item_icon_object_get(
                (Elm_Object_Item*) v_it);
        if(obj == NULL) caml_failwith("elm_toolbar_item_icon_object_get");
        return (value) obj;
}

