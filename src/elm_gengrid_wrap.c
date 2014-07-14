#include "include.h"

PREFIX void ml_Elm_Gengrid_Item_Class(
        Elm_Gen_Item_Class** class, void** data, value v)
{
        Elm_Gen_Item_Class* c = elm_gengrid_item_class_new();
        if(c == NULL) caml_raise_out_of_memory();

        c->item_style = String_val(Field(v, 0));
        c->func.text_get = ml_Elm_Gen_Item_Text_Get_Cb;
        c->func.content_get = ml_Elm_Gen_Item_Content_Get_Cb;
        c->func.state_get = ml_Elm_Gen_Item_State_Get_Cb;
        c->func.del = ml_Elm_Gen_Item_Del_Cb_free;

        value* v_data = ml_register_value(v);

        *class = c;
        *data = v_data;
}

PREFIX value ml_elm_gengrid_add(value v_parent)
{
        Evas_Object* obj = elm_gengrid_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_gengrid_add");
        return (value) obj;
}

PREFIX value ml_elm_gengrid_clear(value v_obj)
{
        elm_gengrid_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_gengrid_multi_select_set(value v_obj, value v_flag)
{
        elm_gengrid_multi_select_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_multi_select_get(value v_obj)
{
        return Val_Eina_Bool(elm_gengrid_multi_select_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_multi_select_mode_set(value v_obj, value v_flag)
{
        elm_gengrid_multi_select_mode_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_multi_select_mode_get(value v_obj)
{
        return Val_bool(elm_gengrid_multi_select_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_horizontal_set(value v_obj, value v_flag)
{
        elm_gengrid_horizontal_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_horizontal_get(value v_obj)
{
        return Val_bool(elm_gengrid_horizontal_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_item_append(
        value v_obj, value v_class, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = ml_register_value(v_func);

        Elm_Object_Item* item = elm_gengrid_item_append((Evas_Object*) v_obj,
                class, data, ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) {
                ml_remove_value(data);
                ml_remove_value(data_func);
        }
        ml_Elm_Object_Item_gc_value(item, data_func);
        return (value) item;
}

PREFIX value ml_elm_gengrid_item_prepend(
        value v_obj, value v_class, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = ml_register_value(v_func);

        Elm_Object_Item* item = elm_gengrid_item_prepend((Evas_Object*) v_obj,
                class, data, ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) {
                ml_remove_value(data);
                ml_remove_value(data_func);
                caml_failwith("elm_gengrid_item_prepend");
        }
        ml_Elm_Object_Item_gc_value(item, data_func);
        return (value) item;
}

PREFIX value ml_elm_gengrid_item_insert_before(
        value v_obj, value v_class, value v_rel, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = ml_register_value(v_func);

        Elm_Object_Item* item = elm_gengrid_item_insert_before(
                (Evas_Object*) v_obj, class, data, (Elm_Object_Item*) v_rel,
                ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) {
                ml_remove_value(data);
                ml_remove_value(data_func);
                caml_failwith("elm_gengrid_item_insert_before");
        }
        ml_Elm_Object_Item_gc_value(item, data_func);
        return (value) item;
}

PREFIX value ml_elm_gengrid_item_insert_after(
        value v_obj, value v_class, value v_rel, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = ml_register_value(v_func);

        Elm_Object_Item* item = elm_gengrid_item_insert_after(
                (Evas_Object*) v_obj, class, data, (Elm_Object_Item*) v_rel,
                ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) {
                ml_remove_value(data);
                ml_remove_value(data_func);
                caml_failwith("elm_gengrid_item_insert_after");
        }
        ml_Elm_Object_Item_gc_value(item, data_func);
        return (value) item;
}

PREFIX value ml_elm_gengrid_selected_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_gengrid_selected_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_gengrid_selected_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_gengrid_selected_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_realized_items_get(value v_obj)
{
        Eina_List* list = elm_gengrid_realized_items_get((Evas_Object*) v_obj);
        value v = copy_Eina_List_Elm_Object_Item(list);
        eina_list_free(list);
        return v;
}

PREFIX value ml_elm_gengrid_first_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_gengrid_first_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_gengrid_last_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_gengrid_last_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_gengrid_item_next_get(value v_it)
{
        Elm_Object_Item* next = elm_gengrid_item_next_get(
                (Elm_Object_Item*) v_it);
        if(next == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) next);
        return v;
}

PREFIX value ml_elm_gengrid_item_prev_get(value v_it)
{
        Elm_Object_Item* prev = elm_gengrid_item_prev_get(
                (Elm_Object_Item*) v_it);
        if(prev == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) prev);
        return v;
}

PREFIX value ml_elm_gengrid_item_selected_set(value v_it, value v_flag)
{
        elm_gengrid_item_selected_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_selected_get(value v_it)
{
        return Val_Eina_Bool(elm_gengrid_item_selected_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_gengrid_item_show(value v_it, value v_type)
{
        elm_gengrid_item_show((Elm_Object_Item*) v_it,
                Elm_Gengrid_Item_Scrollto_Type_val(v_type));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_bring_in(value v_it, value v_type)
{
        elm_gengrid_item_bring_in((Elm_Object_Item*) v_it,
                Elm_Gengrid_Item_Scrollto_Type_val(v_type));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_update(value v_it)
{
        elm_gengrid_item_update((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_index_get(value v_it)
{
        return Val_int(elm_gengrid_item_index_get((Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_gengrid_items_count(value v_obj)
{
        return Val_int(elm_gengrid_items_count((Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_item_tooltip_text_set(value v_it, value v_text)
{
        elm_gengrid_item_tooltip_text_set((Elm_Object_Item*) v_it,
                String_val(v_text));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_tooltip_content_cb_set(
        value v_it, value v_func, value v_del_cb)
{
        CAMLparam3(v_it, v_func, v_del_cb);
        value* data = caml_stat_alloc(sizeof(value));
        *data = caml_alloc(2, 0);
        Store_field(*data, 0, v_func);
        Store_field(*data, 1, v_del_cb);
        caml_register_generational_global_root(data);
        elm_gengrid_item_tooltip_content_cb_set((Elm_Object_Item*) v_it,
                ml_Elm_Tooltip_Item_Content_Cb_0, data,
                ml_Evas_Smart_Cb_1_free);
        CAMLreturn(Val_unit);
}

PREFIX value ml_elm_gengrid_item_tooltip_unset(value v_it)
{
        elm_gengrid_item_tooltip_unset((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_tooltip_style_set(value v_it, value v_style)
{
        elm_gengrid_item_tooltip_style_set((Elm_Object_Item*) v_it,
                String_val(v_style));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_tooltip_style_get(value v_it)
{
        return copy_string(elm_gengrid_item_tooltip_style_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_gengrid_item_tooltip_window_mode_set(
        value v_it, value v_flag)
{
        elm_gengrid_item_tooltip_window_mode_set((Elm_Object_Item*) v_it,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_tooltip_window_mode_get(value v_it)
{
        return Val_bool(elm_gengrid_item_tooltip_window_mode_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_gengrid_item_cursor_set(value v_it, value v_cursor)
{
        char* cursor = String_val(v_cursor);
        elm_gengrid_item_cursor_set((Elm_Object_Item*) v_it, cursor);
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_cursor_get(value v_it)
{
        CAMLparam1(v_it);
        CAMLlocal1(v_cursor);
        const char* cursor =
                elm_gengrid_item_cursor_get((Elm_Object_Item*) v_it);
        if(cursor == NULL) v_cursor = Val_int(0);
        else {
                v_cursor = caml_alloc(1, 0);
                Store_field(v_cursor, 0, copy_string(cursor));
        }
        CAMLreturn(v_cursor);
}

PREFIX value ml_elm_gengrid_item_cursor_unset(value v_it)
{
        elm_gengrid_item_cursor_unset((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_cursor_style_set(value v_it, value v_style)
{
        elm_gengrid_item_cursor_style_set((Elm_Object_Item*) v_it,
                String_val(v_style));
        return Val_unit;
}


PREFIX value ml_elm_gengrid_item_cursor_style_get(value v_it)
{
        CAMLparam1(v_it);
        CAMLlocal1(v_style);
        const char* style =
                elm_gengrid_item_cursor_style_get((Elm_Object_Item*) v_it);
        if(style == NULL) v_style = Val_int(0);
        else {
                v_style = caml_alloc(1, 0);
                Store_field(v_style, 0, copy_string(style));
        }
        CAMLreturn(v_style);
}

PREFIX value ml_elm_gengrid_item_cursor_engine_only_set(
        value v_it, value v_flag)
{
        elm_gengrid_item_cursor_engine_only_set((Elm_Object_Item*) v_it,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_cursor_engine_only_get(value v_it)
{
        return Val_bool(elm_gengrid_item_cursor_engine_only_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_gengrid_item_size_set(value v_obj, value v_w, value v_h)
{
        elm_gengrid_item_size_set((Evas_Object*) v_obj, Int_val(v_w),
                Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_size_get(value v_obj)
{
        Evas_Coord w, h;
        elm_gengrid_item_size_get((Evas_Object*) v_obj, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

PREFIX value ml_elm_gengrid_group_item_size_set(value v_obj, value v_w, value v_h)
{
        elm_gengrid_group_item_size_set((Evas_Object*) v_obj, Int_val(v_w),
                Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_group_item_size_get(value v_obj)
{
        Evas_Coord w, h;
        elm_gengrid_group_item_size_get((Evas_Object*) v_obj, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

PREFIX value ml_elm_gengrid_align_set(value v_obj, value v_x, value v_y)
{
        elm_gengrid_align_set((Evas_Object*) v_obj, Double_val(v_x),
                Double_val(v_y));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_align_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double x, y;
        elm_gengrid_align_get((Evas_Object*) v_obj, &x, &y);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(x));
        Store_field(v_r, 1, copy_double(y));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_gengrid_reorder_mode_set(value v_obj, value v_flag)
{
        elm_gengrid_reorder_mode_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_reorder_mode_get(value v_obj)
{
        return Val_bool(elm_gengrid_reorder_mode_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_page_show(value v_obj, value v_h, value v_v)
{
        elm_gengrid_page_show((Evas_Object*) v_obj, Int_val(v_h),
                Int_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_pos_get(value v_it)
{
        unsigned int x, y;
        elm_gengrid_item_pos_get((Elm_Object_Item*) v_it, &x, &y);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(x));
        Store_field(v_r, 1, Val_int(y));
        return v_r;
}

PREFIX value ml_elm_gengrid_filled_set(value v_obj, value v_flag)
{
        elm_gengrid_filled_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_filled_get(value v_obj)
{
        return Val_bool(elm_gengrid_filled_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_select_mode_set(value v_obj, value v_mode)
{
        elm_gengrid_select_mode_set((Evas_Object*) v_obj,
                Elm_Object_Select_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_select_mode_get(value v_obj)
{
        return Val_Elm_Object_Select_Mode(elm_gengrid_select_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_highlight_mode_set(value v_obj, value v_flag)
{
        elm_gengrid_highlight_mode_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_highlight_mode_get(value v_obj)
{
        return Val_bool(elm_gengrid_highlight_mode_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_nth_item_get(value v_obj, value v_k)
{
        Elm_Object_Item* it = elm_gengrid_nth_item_get((Evas_Object*) v_obj,
                Int_val(v_k));
        if(it == NULL) return Val_int(0);
        value v_r = caml_alloc(1, 0);
        Store_field(v_r, 0, (value) it);
        return v_r;
}

PREFIX value ml_elm_gengrid_item_select_mode_set(value v_it, value v_mode)
{
        elm_gengrid_item_select_mode_set((Elm_Object_Item*) v_it,
                Elm_Object_Select_Mode_val(v_mode));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_item_select_mode_get(value v_it)
{
        return Val_Elm_Object_Select_Mode(elm_gengrid_item_select_mode_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_gengrid_reorder_mode_start(value v_obj, value v_m)
{
        elm_gengrid_reorder_mode_start((Evas_Object*) v_obj,
                Ecore_Pos_Map_val(v_m));
        return Val_unit;
}

PREFIX value ml_elm_gengrid_reorder_mode_stop(value v_obj)
{
        elm_gengrid_reorder_mode_stop((Evas_Object*) v_obj);
        return Val_unit;
}

