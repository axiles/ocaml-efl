#include "include.h"

PREFIX value ml_elm_menu_add(value v_parent)
{
        Evas_Object* obj = elm_menu_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_menu_add");
        return (value) obj;
}

PREFIX value ml_elm_menu_parent_set(value v_obj, value v_parent)
{
        elm_menu_parent_set((Evas_Object*) v_obj, (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_menu_parent_get(value v_obj)
{
        return (value) elm_menu_parent_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_menu_move(value v_obj, value v_x, value v_y)
{
        elm_menu_move((Evas_Object*) v_obj, Int_val(v_x), Int_val(v_y));
        return Val_unit;
}

PREFIX value ml_elm_menu_close(value v_obj)
{
        elm_menu_close((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_menu_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_menu_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_menu_item_object_get(value v_item)
{
        return (value) elm_menu_item_object_get((Elm_Object_Item*) v_item);
}

PREFIX value ml_elm_menu_item_add_native(
        value v_obj, value v_parent, value v_icon, value v_label, value v_func,
        value v_unit)
{
        Elm_Object_Item* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        else parent = (Elm_Object_Item*) Field(v_parent, 0);
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
                data = caml_stat_alloc(sizeof(value));
                *data = Field(v_func, 0);
                caml_register_global_root(data);
        }
        Elm_Object_Item* item = elm_menu_item_add((Evas_Object*) v_obj, parent,
                icon, label, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_menu_item_add");
        }
        return (value) item;
}

PREFIX value ml_elm_menu_item_add_byte(value* argv, int argn)
{
        return ml_elm_menu_item_add_native(argv[0], argv[1], argv[2], argv[3],
                argv[4], argv[5]);
}

PREFIX value ml_elm_menu_item_icon_name_set(value v_it, value v_icon)
{
        elm_menu_item_icon_name_set((Elm_Object_Item*) v_it,
                String_val(v_icon));
        return Val_unit;
}

PREFIX value ml_elm_menu_item_icon_name_get(value v_it)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* icon = elm_menu_item_icon_name_get((Elm_Object_Item*) v_it);
        if(icon == NULL) CAMLreturn(Val_int(0));
        v = caml_alloc(1, 0);
        Store_field(v, 0, copy_string(icon));
        CAMLreturn(v);
}

PREFIX value ml_elm_menu_item_selected_set(value v_it, value v_flag)
{
        elm_menu_item_selected_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_menu_item_selected_get(value v_it)
{
        return Val_Eina_Bool(elm_menu_item_selected_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_menu_item_separator_add(value v_obj, value v_parent)
{
        Elm_Object_Item* it = elm_menu_item_separator_add((Evas_Object*) v_obj,
                (Elm_Object_Item*) v_parent);
        if(it == NULL) caml_failwith("elm_menu_item_separator_add");
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_menu_item_is_separator(value v_it)
{
        return Val_Eina_Bool(elm_menu_item_is_separator(
                (Elm_Object_Item*) v_it)); 
}

PREFIX value ml_elm_menu_item_subitems_get(value v_it)
{
        return copy_Eina_List_Elm_Object_Item(elm_menu_item_subitems_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_menu_item_index_get(value v_it)
{
        return Val_int(elm_menu_item_index_get((Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_menu_selected_item_get(value v_obj)
{
        Elm_Object_Item* it = elm_menu_selected_item_get((Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

