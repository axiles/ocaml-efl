#include "include.h"

inline Elm_Toolbar_Item_Scrollto_Type
Elm_Toolbar_Item_Scrollto_Type_val_list(value v)
{
        Elm_Toolbar_Item_Scrollto_Type r = ELM_TOOLBAR_ITEM_SCROLLTO_NONE;
        value v_tmp = v;
        while(v_tmp != Val_int(0)) {
                r = r | Elm_Toolbar_Item_Scrollto_Type_val(Field(v_tmp, 0));
                v_tmp = Field(v_tmp, 1);
        }
        return r;
}

PREFIX value ml_elm_toolbar_add(value v_parent)
{
        Evas_Object* obj = elm_toolbar_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_toolbar_add");
        return copy_Evas_Object(obj);
}

PREFIX value ml_elm_toolbar_item_append(
        value v_obj, value v_icon, value v_label, value v_func, value v_unit CAMLunused)
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
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_toolbar_item_append(Evas_Object_val(v_obj),
                icon, label, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_toolbar_item_append");
        }
        if(data != NULL)
                ml_Elm_Object_Item_gc_value(item, data);
        return copy_Elm_Object_Item(item);
}

PREFIX value ml_elm_toolbar_item_prepend(
        value v_obj, value v_icon, value v_label, value v_func, value v_unit CAMLunused)
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
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_toolbar_item_prepend(Evas_Object_val(v_obj),
                icon, label, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_toolbar_item_prepend");
        }
        if(data != NULL)
                ml_Elm_Object_Item_gc_value(item, data);
        return copy_Elm_Object_Item(item);
}

PREFIX value ml_elm_toolbar_item_insert_before_native(
        value v_obj, value v_before, value v_icon, value v_label, value v_func,
        value v_unit CAMLunused)
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
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_toolbar_item_insert_before(
                Evas_Object_val(v_obj), Elm_Object_Item_val(v_before), icon,
                label, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_toolbar_item_insert_before");
        }
        if(data != NULL)
                ml_Elm_Object_Item_gc_value(item, data);
        return copy_Elm_Object_Item(item);
}

PREFIX value ml_elm_toolbar_item_insert_before_byte(value* argv, int argn CAMLunused)
{
        return ml_elm_toolbar_item_insert_before_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_toolbar_item_insert_after_native(
        value v_obj, value v_after, value v_icon, value v_label, value v_func,
        value v_unit CAMLunused)
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
                data = ml_register_value(Field(v_func, 0));
        }
        Elm_Object_Item* item = elm_toolbar_item_insert_after(
                Evas_Object_val(v_obj), Elm_Object_Item_val(v_after), icon,
                label, func, data);
        if(item == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_toolbar_item_insert_after");
        }
        if(data != NULL)
                ml_Elm_Object_Item_gc_value(item, data);
        return copy_Elm_Object_Item(item);
}

PREFIX value ml_elm_toolbar_item_insert_after_byte(value* argv, int argn CAMLunused)
{
        return ml_elm_toolbar_item_insert_after_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_toolbar_first_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_toolbar_first_item_get(
                Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(it);
}

PREFIX value ml_elm_toolbar_last_item_get(value v_obj)
{
        Elm_Object_Item *it = elm_toolbar_last_item_get(Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(it);
}

PREFIX value ml_elm_toolbar_item_next_get(value v_it)
{
        Elm_Object_Item* it1 = elm_toolbar_item_next_get(
                Elm_Object_Item_val(v_it));
        return copy_Elm_Object_Item_opt(it1);
}

PREFIX value ml_elm_toolbar_item_prev_get(value v_it)
{
        Elm_Object_Item* it1 = elm_toolbar_item_prev_get(
                Elm_Object_Item_val(v_it));
        return copy_Elm_Object_Item_opt(it1);
}

PREFIX value ml_elm_toolbar_item_show(value v_it, value v_t)
{
        elm_toolbar_item_show(Elm_Object_Item_val(v_it),
                Elm_Toolbar_Item_Scrollto_Type_val_list(v_t));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_item_bring_in(value v_it, value v_t)
{
        elm_toolbar_item_bring_in(Elm_Object_Item_val(v_it),
                Elm_Toolbar_Item_Scrollto_Type_val_list(v_t));
        return Val_unit;
}

PREFIX value ml_elm_toolbar_item_find_by_label(value v_obj, value v_label)
{
       Elm_Object_Item* it = elm_toolbar_item_find_by_label(
               Evas_Object_val(v_obj), String_val(v_label));
       return copy_Elm_Object_Item_opt(it);
}

PREFIX value ml_elm_toolbar_selected_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_toolbar_selected_item_get(Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(item);
}

PREFIX value ml_elm_toolbar_more_item_get(value v_obj)
{
        Elm_Object_Item* item =
                elm_toolbar_more_item_get(Evas_Object_val(v_obj));
        return copy_Elm_Object_Item_opt(item);
}

PREFIX value ml_elm_toolbar_item_icon_object_get(value v_it)
{
        Evas_Object* obj = elm_toolbar_item_icon_object_get(
                Elm_Object_Item_val(v_it));
        if(obj == NULL) caml_failwith("elm_toolbar_item_icon_object_get");
        return copy_Evas_Object(obj);
}

PREFIX value ml_elm_toolbar_item_icon_file_set(
        value v_it, value v_file, value v_key, value v_unit CAMLunused)
{
        const char* key;
        if(v_key == Val_int(0)) key = NULL;
        else key = String_val(Field(v_key, 0));
        return Val_bool(elm_toolbar_item_icon_file_set(
                Elm_Object_Item_val(v_it), String_val(v_file), key));
}

PREFIX value ml_elm_toolbar_menu_parent_get(value v_obj)
{
        return copy_Evas_Object(
                elm_toolbar_menu_parent_get(Evas_Object_val(v_obj)));
}

PREFIX value ml_elm_toolbar_item_menu_get(value v_it)
{
        Evas_Object* obj = elm_toolbar_item_menu_get(Elm_Object_Item_val(v_it));
        return copy_Evas_Object_opt(obj);
}

PREFIX value ml_elm_toolbar_item_state_add(
        value v_it, value v_icon, value v_label, value v_func, value v_unit CAMLunused)
{
        Elm_Object_Item* it = Elm_Object_Item_val(v_it);
        const char* icon;
        if(v_icon == Val_int(0)) icon = NULL;
        else icon = String_val(Field(v_icon, 0));
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
        Elm_Toolbar_Item_State* state = elm_toolbar_item_state_add(it, icon,
                label, func, data);
        if(state == NULL) {
                if(data != NULL) ml_remove_value(data);
                caml_failwith("elm_toolbar_item_state_add");
        }
        if(data != NULL)
                ml_Elm_Object_Item_gc_value(it, data);
        return copy_Elm_Toolbar_Item_State(state);
}

PREFIX value ml_elm_toolbar_item_state_set_null(value v_it)
{
        return Bool_val(elm_toolbar_item_state_set(Elm_Object_Item_val(v_it),
                NULL));
}

PREFIX value ml_elm_toolbar_item_state_get(value v_it)
{
        Elm_Toolbar_Item_State* state = elm_toolbar_item_state_get(
                Elm_Object_Item_val(v_it));
        return copy_Elm_Toolbar_Item_State_opt(state);
}

PREFIX value ml_elm_toolbar_item_state_next(value v_it)
{
        Elm_Toolbar_Item_State* state = elm_toolbar_item_state_next(
                Elm_Object_Item_val(v_it));
        return copy_Elm_Toolbar_Item_State_opt(state);
}

PREFIX value ml_elm_toolbar_item_state_prev(value v_it)
{
        Elm_Toolbar_Item_State* state = elm_toolbar_item_state_prev(
                Elm_Object_Item_val(v_it));
        return copy_Elm_Toolbar_Item_State(state);
}

