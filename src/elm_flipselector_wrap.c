#include "include.h"

PREFIX value ml_elm_flipselector_add(value v_parent)
{
        Evas_Object* flipselector = elm_flipselector_add(
                Evas_Object_val(v_parent));
        if(flipselector == NULL) caml_failwith("elm_flipselector_add");
        return copy_Evas_Object(flipselector);
}

PREFIX value ml_elm_flipselector_item_append(
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
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_flipselector_item_append(
                Evas_Object_val(v_obj), label, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_flipselector_item_append");
        }
        if(data != NULL)
                ml_Elm_Object_Item_gc_value(item, data);
        return (value) item;
}

PREFIX value ml_elm_flipselector_item_prepend(
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
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_flipselector_item_prepend(
                Evas_Object_val(v_obj), label, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_flipselector_item_prepend");
        }
        if(data != NULL)
                ml_Elm_Object_Item_gc_value(item, data);
        return (value) item;
}

PREFIX value ml_elm_flipselector_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_flipselector_items_get(
                Evas_Object_val(v_obj)));
}

PREFIX value ml_elm_flipselector_first_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_flipselector_first_item_get(
                Evas_Object_val(v_obj));
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_flipselector_last_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_flipselector_last_item_get(
                Evas_Object_val(v_obj));
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_flipselector_selected_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_flipselector_selected_item_get(Evas_Object_val(v_obj));
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_flipselector_item_prev_get(value v_it)
{
        Elm_Object_Item* it1 = elm_flipselector_item_prev_get(
                (Elm_Object_Item*) v_it);
        if(it1 == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it1);
        return v;
}

PREFIX value ml_elm_flipselector_item_next_get(value v_it)
{
        Elm_Object_Item* it1 = elm_flipselector_item_next_get(
                (Elm_Object_Item*) v_it);
        if(it1 == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it1);
        return v;
}

