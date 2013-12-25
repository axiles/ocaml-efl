#include "include.h"

PREFIX void ml_Elm_Genlist_Item_Class(
        Elm_Gen_Item_Class** class, void** data, value v)
{
        Elm_Gen_Item_Class* c = elm_genlist_item_class_new();
        if(c == NULL) caml_raise_out_of_memory();

        c->item_style = String_val(Field(v, 0));
        c->func.text_get = ml_Elm_Gen_Item_Text_Get_Cb;
        c->func.content_get = ml_Elm_Gen_Item_Content_Get_Cb;
        c->func.state_get = ml_Elm_Gen_Item_State_Get_Cb;
        c->func.del = ml_Elm_Gen_Item_Del_Cb;

        value* v_data = caml_stat_alloc(sizeof(value));
        *v_data = v;
        caml_register_global_root(v_data);

        *class = c;
        *data = v_data;
}

PREFIX inline Elm_Genlist_Item_Type Elm_Genlist_Item_Type_val(value v)
{
        switch(v) {
                case Val_none: return ELM_GENLIST_ITEM_NONE;
                case Val_tree: return ELM_GENLIST_ITEM_TREE;
                case Val_group: return ELM_GENLIST_ITEM_GROUP;
        }
        caml_failwith("Elm_Genlist_Item_Type_val");
        return ELM_GENLIST_ITEM_NONE;
}

PREFIX inline Elm_Genlist_Item_Scrollto_Type
Elm_Genlist_Item_Scrollto_Type_val(value v)
{
        switch(v) {
                case Val_none: return ELM_GENLIST_ITEM_SCROLLTO_NONE;
                case Val_in: return ELM_GENLIST_ITEM_SCROLLTO_IN;
                case Val_top: return ELM_GENLIST_ITEM_SCROLLTO_TOP;
                case Val_middle: return ELM_GENLIST_ITEM_SCROLLTO_MIDDLE;
        }
        caml_failwith("Elm_Genlist_Item_Scrollto_Type_val");
        return ELM_GENLIST_ITEM_SCROLLTO_NONE;
}

PREFIX value ml_elm_genlist_add(value v_parent)
{
        Evas_Object* obj = elm_genlist_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_genlist_add");
        return (value) obj;
}

PREFIX value ml_elm_genlist_clear(value v_obj)
{
        elm_genlist_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_genlist_multi_select_set(value v_obj, value v_flag)
{
        elm_genlist_multi_select_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_genlist_multi_select_get(value v_obj)
{
        return Val_Eina_Bool(elm_genlist_multi_select_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_genlist_mode_set(value v_obj, value v_mode)
{
        elm_genlist_mode_set((Evas_Object*) v_obj, Elm_List_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_genlist_mode_get(value v_obj)
{
        return Val_Elm_List_Mode(elm_genlist_mode_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_genlist_item_append(
        value v_obj, value v_itc, value v_parent, value v_type, value v_func)
{
        Elm_Genlist_Item_Class* itc;
        void* data;
        ml_Elm_Genlist_Item_Class(&itc, &data, v_itc);

        Elm_Object_Item* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        else parent = (Elm_Object_Item*) Field(v_parent, 0);

        value* func_data = caml_stat_alloc(sizeof(value));
        *func_data = v_func;
        caml_register_global_root(data);

        Elm_Object_Item* item = elm_genlist_item_append((Evas_Object*) v_obj,
                itc, data, parent, Elm_Genlist_Item_Type_val(v_type),
                ml_Evas_Smart_Cb, func_data);
        elm_genlist_item_class_free(itc);

        if(item == NULL) {
                caml_remove_global_root((value*) data);
                caml_remove_global_root(func_data);
                free(data);
                free(func_data);
                caml_failwith("elm_genlist_item_append");
        }
        return (value) item;
}

PREFIX value ml_elm_genlist_item_prepend(
        value v_obj, value v_itc, value v_parent, value v_type, value v_func)
{
        Elm_Genlist_Item_Class* itc;
        void* data;
        ml_Elm_Genlist_Item_Class(&itc, &data, v_itc);

        Elm_Object_Item* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        else parent = (Elm_Object_Item*) Field(v_parent, 0);

        value* func_data = caml_stat_alloc(sizeof(value));
        *func_data = v_func;
        caml_register_global_root(data);

        Elm_Object_Item* item = elm_genlist_item_prepend((Evas_Object*) v_obj,
                itc, data, parent, Elm_Genlist_Item_Type_val(v_type),
                ml_Evas_Smart_Cb, func_data);
        elm_genlist_item_class_free(itc);

        if(item == NULL) {
                caml_remove_global_root((value*) data);
                caml_remove_global_root(func_data);
                free(data);
                free(func_data);
                caml_failwith("elm_genlist_item_prepend");
        }
        return (value) item;
}

PREFIX value ml_elm_genlist_item_insert_before_native(
        value v_obj, value v_itc, value v_parent, value v_before, value v_type,
        value v_func)
{
        Elm_Genlist_Item_Class* itc;
        void* data;
        ml_Elm_Genlist_Item_Class(&itc, &data, v_itc);

        Elm_Object_Item* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        else parent = (Elm_Object_Item*) Field(v_parent, 0);

        value* func_data = caml_stat_alloc(sizeof(value));
        *func_data = v_func;
        caml_register_global_root(data);

        Elm_Object_Item* item = elm_genlist_item_insert_before(
                (Evas_Object*) v_obj, itc, data, parent,
                (Elm_Object_Item*) v_before, Elm_Genlist_Item_Type_val(v_type),
                ml_Evas_Smart_Cb, func_data);
        elm_genlist_item_class_free(itc);

        if(item == NULL) {
                caml_remove_global_root((value*) data);
                caml_remove_global_root(func_data);
                free(data);
                free(func_data);
                caml_failwith("elm_genlist_item_insert_before");
        }
        return (value) item;
}

PREFIX value ml_elm_genlist_item_insert_before_byte(value* argv, int argn)
{
        return ml_elm_genlist_item_insert_before_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_genlist_item_insert_after_native(
        value v_obj, value v_itc, value v_parent, value v_after, value v_type,
        value v_func)
{
        Elm_Genlist_Item_Class* itc;
        void* data;
        ml_Elm_Genlist_Item_Class(&itc, &data, v_itc);

        Elm_Object_Item* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        else parent = (Elm_Object_Item*) Field(v_parent, 0);

        value* func_data = caml_stat_alloc(sizeof(value));
        *func_data = v_func;
        caml_register_global_root(data);

        Elm_Object_Item* item = elm_genlist_item_insert_after(
                (Evas_Object*) v_obj, itc, data, parent,
                (Elm_Object_Item*) v_after, Elm_Genlist_Item_Type_val(v_type),
                ml_Evas_Smart_Cb, func_data);
        elm_genlist_item_class_free(itc);

        if(item == NULL) {
                caml_remove_global_root((value*) data);
                caml_remove_global_root(func_data);
                free(data);
                free(func_data);
                caml_failwith("elm_genlist_item_insert_after");
        }
        return (value) item;
}

PREFIX value ml_elm_genlist_item_insert_after_byte(value* argv, int argn)
{
        return ml_elm_genlist_item_insert_after_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5]);
}

PREFIX value ml_elm_genlist_selected_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_genlist_selected_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_genlist_selected_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_genlist_selected_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_genlist_realized_items_get(value v_obj)
{
        Eina_List* list = elm_genlist_realized_items_get((Evas_Object*) v_obj);
        value v = copy_Eina_List_Elm_Object_Item(list);
        eina_list_free(list);
        return v;
}

PREFIX value ml_elm_genlist_first_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_genlist_first_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_genlist_last_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_genlist_last_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_genlist_item_next_get(value v_it)
{
        Elm_Object_Item* next = elm_genlist_item_next_get(
                (Elm_Object_Item*) v_it);
        if(next == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) next);
        return v;
}

PREFIX value ml_elm_genlist_item_prev_get(value v_it)
{
        Elm_Object_Item* prev = elm_genlist_item_prev_get(
                (Elm_Object_Item*) v_it);
        if(prev == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) prev);
        return v;
}

PREFIX value ml_elm_genlist_item_selected_set(value v_it, value v_flag)
{
        elm_genlist_item_selected_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_genlist_item_selected_get(value v_it)
{
        return Val_Eina_Bool(elm_genlist_item_selected_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_genlist_item_show(value v_it, value v_type)
{
        elm_genlist_item_show((Elm_Object_Item*) v_it,
                Elm_Genlist_Item_Scrollto_Type_val(v_type));
        return Val_unit;
}

PREFIX value ml_elm_genlist_item_bring_in(value v_it, value v_type)
{
        elm_genlist_item_bring_in((Elm_Object_Item*) v_it,
                Elm_Genlist_Item_Scrollto_Type_val(v_type));
        return Val_unit;
}

PREFIX value ml_elm_genlist_item_update(value v_it)
{
        elm_genlist_item_update((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_genlist_item_index_get(value v_it)
{
        return Val_int(elm_genlist_item_index_get((Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_genlist_realized_items_update(value v_obj)
{
        elm_genlist_realized_items_update((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_genlist_items_count(value v_obj)
{
        return Val_int(elm_genlist_items_count((Evas_Object*) v_obj));
}

PREFIX value ml_elm_genlist_item_tooltip_text_set(value v_it, value v_text)
{
        elm_genlist_item_tooltip_text_set((Elm_Object_Item*) v_it,
                String_val(v_text));
        return Val_unit;
}

PREFIX value ml_elm_genlist_item_tooltip_content_cb_set(
        value v_it, value v_func, value v_del_cb)
{
        CAMLparam3(v_it, v_func, v_del_cb);
        value* data = caml_stat_alloc(sizeof(value));
        *data = caml_alloc(2, 0);
        Store_field(*data, 0, v_func);
        Store_field(*data, 1, v_del_cb);
        caml_register_global_root(data);
        elm_genlist_item_tooltip_content_cb_set((Elm_Object_Item*) v_it,
                ml_Elm_Tooltip_Item_Content_Cb_0, data, ml_Evas_Smart_Cb_1);
        CAMLreturn(Val_unit);
}

PREFIX value ml_elm_genlist_item_tooltip_unset(value v_it)
{
        elm_genlist_item_tooltip_unset((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_genlist_item_tooltip_style_set(value v_it, value v_style)
{
        elm_genlist_item_tooltip_style_set((Elm_Object_Item*) v_it,
                String_val(v_style));
        return Val_unit;
}

PREFIX value ml_elm_genlist_item_tooltip_style_get(value v_it)
{
        return copy_string(elm_genlist_item_tooltip_style_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_genlist_item_tooltip_window_mode_set(
        value v_it, value v_flag)
{
        elm_genlist_item_tooltip_window_mode_set((Elm_Object_Item*) v_it,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_genlist_item_tooltip_window_mode_get(value v_it)
{
        return Val_bool(elm_genlist_item_tooltip_window_mode_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_genlist_item_cursor_set(value v_it, value v_cursor)
{
        char* cursor = String_val(v_cursor);
        elm_genlist_item_cursor_set((Elm_Object_Item*) v_it, cursor);
        return Val_unit;
}

PREFIX value ml_elm_genlist_item_cursor_get(value v_it)
{
        CAMLparam1(v_it);
        CAMLlocal1(v_cursor);
        const char* cursor =
                elm_genlist_item_cursor_get((Elm_Object_Item*) v_it);
        if(cursor == NULL) v_cursor = Val_int(0);
        else {
                v_cursor = caml_alloc(1, 0);
                Store_field(v_cursor, 0, copy_string(cursor));
        }
        CAMLreturn(v_cursor);
}

PREFIX value ml_elm_genlist_item_cursor_unset(value v_it)
{
        elm_genlist_item_cursor_unset((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_genlist_item_cursor_style_set(value v_it, value v_style)
{
        elm_genlist_item_cursor_style_set((Elm_Object_Item*) v_it,
                String_val(v_style));
        return Val_unit;
}


PREFIX value ml_elm_genlist_item_cursor_style_get(value v_it)
{
        CAMLparam1(v_it);
        CAMLlocal1(v_style);
        const char* style =
                elm_genlist_item_cursor_style_get((Elm_Object_Item*) v_it);
        if(style == NULL) v_style = Val_int(0);
        else {
                v_style = caml_alloc(1, 0);
                Store_field(v_style, 0, copy_string(style));
        }
        CAMLreturn(v_style);
}

PREFIX value ml_elm_genlist_item_cursor_engine_only_set(
        value v_it, value v_flag)
{
        elm_genlist_item_cursor_engine_only_set((Elm_Object_Item*) v_it,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_genlist_item_cursor_engine_only_get(value v_it)
{
        return Val_bool(elm_genlist_item_cursor_engine_only_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_genlist_homogeneous_set(value v_obj, value v_flag)
{
        elm_genlist_homogeneous_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_genlist_homogeneous_get(value v_obj)
{
        return Val_bool(elm_genlist_homogeneous_get((Evas_Object*) v_obj));
}

