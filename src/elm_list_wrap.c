#include "include.h"

PREFIX value ml_elm_list_add(value v_parent)
{
        Evas_Object* obj = elm_list_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_list_add");
        return (value) obj;
}

PREFIX value ml_elm_list_go(value v_obj)
{
        elm_list_go((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_list_multi_select_set(value v_obj, value v_flag)
{
        elm_list_multi_select_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_list_multi_select_get(value v_obj)
{
        return Val_Eina_Bool(elm_list_multi_select_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_list_mode_set(value v_obj, value v_mode)
{
        elm_list_mode_set((Evas_Object*) v_obj, Elm_List_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_list_mode_get(value v_obj)
{
        return Val_Elm_List_Mode(elm_list_mode_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_list_horizontal_set(value v_obj, value v_flag)
{
        elm_list_horizontal_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_list_horizontal_get(value v_obj)
{
        return Val_Eina_Bool(elm_list_horizontal_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_list_select_mode_set(value v_obj, value v_mode)
{
        elm_list_select_mode_set((Evas_Object*) v_obj,
                Elm_Object_Select_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_list_select_mode_get(value v_obj)
{
        return Val_Elm_Object_Select_Mode(elm_list_select_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_list_item_append_native(
        value v_obj, value v_label, value v_icon, value v_end, value v_func,
        value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = (Evas_Object*) Field(v_icon, 0);
        Evas_Object* end;
        if(v_end == Val_int(0)) end = NULL;
        else end = (Evas_Object*) Field(v_end, 0);
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_list_item_append((Evas_Object*) v_obj,
                label, icon, end, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_list_item_append");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return (value) item;
}

PREFIX value ml_elm_list_item_append_byte(value* argv, int argn)
{
        return ml_elm_list_item_append_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_list_item_prepend_native(
        value v_obj, value v_label, value v_icon, value v_end, value v_func,
        value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = (Evas_Object*) Field(v_icon, 0);
        Evas_Object* end;
        if(v_end == Val_int(0)) end = NULL;
        else end = (Evas_Object*) Field(v_end, 0);
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_list_item_prepend((Evas_Object*) v_obj,
                label, icon, end, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_list_item_prepend");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return (value) item;
}

PREFIX value ml_elm_list_item_prepend_byte(value* argv, int argn)
{
        return ml_elm_list_item_prepend_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_list_item_insert_before_native(
        value v_obj, value v_before, value v_label, value v_icon, value v_end,
        value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = (Evas_Object*) Field(v_icon, 0);
        Evas_Object* end;
        if(v_end == Val_int(0)) end = NULL;
        else end = (Evas_Object*) Field(v_end, 0);
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_list_item_insert_before(
                (Evas_Object*) v_obj, (Elm_Object_Item*) v_before, label, icon,
                end, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_list_item_insert_before");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return (value) item;
}

PREFIX value ml_elm_list_item_insert_before_byte(value* argv, int argn)
{
        return ml_elm_list_item_insert_before_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5], argv[6]);
}

PREFIX value ml_elm_list_item_insert_after_native(
        value v_obj, value v_after, value v_label, value v_icon, value v_end,
        value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        Evas_Object* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = (Evas_Object*) Field(v_icon, 0);
        Evas_Object* end;
        if(v_end == Val_int(0)) end = NULL;
        else end = (Evas_Object*) Field(v_end, 0);
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_list_item_insert_after((Evas_Object*) v_obj,
                (Elm_Object_Item*) v_after, label, icon, end, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_list_item_insert_after");
        }
        if(data != NULL)
                elm_object_item_del_cb_set(item, ml_Evas_Smart_Cb_on_del);
        return (value) item;
}

PREFIX value ml_elm_list_item_insert_after_byte(value* argv, int argn)
{
        return ml_elm_list_item_insert_after_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5], argv[6]);
}

PREFIX value ml_elm_list_clear(value v_obj)
{
        elm_list_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_list_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_list_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_list_selected_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_list_selected_item_get((Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_list_selected_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_list_selected_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_list_item_selected_set(value v_it, value v_flag)
{
        elm_list_item_selected_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_list_item_selected_get(value v_it)
{
        return Val_bool(elm_list_item_selected_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_list_item_separator_set(value v_it, value v_flag)
{
        elm_list_item_separator_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_list_item_separator_get(value v_it, value v_flag)
{
        return Val_Eina_Bool(elm_list_item_separator_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_list_item_show(value v_it)
{
        elm_list_item_show((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_list_item_bring_in(value v_it)
{
        elm_list_item_bring_in((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_list_item_object_get(value v_it)
{
        return (value) elm_list_item_object_get((Elm_Object_Item*) v_it);
}

PREFIX value ml_elm_list_item_prev(value v_it)
{
        Elm_Object_Item* it1 = elm_list_item_prev((Elm_Object_Item*) v_it);
        if(it1 == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it1);
        return v;
}

PREFIX value ml_elm_list_item_next(value v_it)
{
        Elm_Object_Item* it1 = elm_list_item_next((Elm_Object_Item*) v_it);
        if(it1 == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it1);
        return v;
}

PREFIX value ml_elm_list_first_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_list_first_item_get((Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_list_last_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_list_last_item_get((Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

