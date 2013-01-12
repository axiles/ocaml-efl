#include "include.h"

typedef struct _value_ptr_list {
        value* hd;
        struct _value_ptr_list* tl;
} value_ptr_list;

PREFIX value ml_elm_layout_add(value v_parent)
{
        Evas_Object* layout = elm_layout_add((Evas_Object*) v_parent);
        if(layout == NULL) caml_failwith("layout");
        return (value) layout;
}

PREFIX ml_elm_layout_file_set_with_bool(
        value v_obj, value v_file, value v_group)
{
        return Val_Eina_Bool(elm_layout_file_set((Evas_Object*) v_obj,
                String_val(v_file), String_val(v_group)));
}

PREFIX ml_elm_layout_theme_set_with_bool(
        value v_obj, value v_clas, value v_group, value v_style)
{
        return Val_Eina_Bool(elm_layout_theme_set((Evas_Object*) v_obj,
                String_val(v_clas), String_val(v_group), String_val(v_style)));
}

PREFIX ml_elm_layout_signal_emit(value v_obj, value v_emission, value v_source)
{
        elm_layout_signal_emit((Evas_Object*) v_obj, String_val(v_emission),
                String_val(v_source));
        return Val_unit;
}

PREFIX ml_elm_layout_signal_callback_add(
        value v_obj, value v_emission, value v_source, value v_fun)
{
        value *data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_layout_signal_callback_add((Evas_Object*) v_obj,
                String_val(v_emission), String_val(v_source),
                ml_Edje_Signal_Cb, data);
        return Val_unit;
}

PREFIX ml_elm_layout_signal_callback_del(
        value v_obj, value v_emission, value v_source, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        const char* emission = (const char*) String_val(v_emission);
        const char* source = (const char*) String_val(v_source);
        value* data;
        value_ptr_list* list = NULL;
        value_ptr_list* list1;
        while(1) {
                data = elm_layout_signal_callback_del(obj, emission, source,
                        ml_Edje_Signal_Cb);
                if(*data == v_fun) {
                        caml_remove_global_root(data);
                        free(data);
                        break;
                } else {
                        list1 = list;
                        list = caml_stat_alloc(sizeof(value_ptr_list));
                        list->hd = data;
                        list->tl = list1;
                }
        }
        while(list != NULL) {
                elm_layout_signal_callback_add(obj, emission, source,
                        ml_Edje_Signal_Cb, list->hd);
                list1 = list->tl;
                free(list1);
                list = list1;
        }
        return Val_unit;
}

PREFIX value ml_elm_layout_box_append_with_bool(
        value v_obj, value v_part, value v_child)
{
        return Val_Eina_Bool(elm_layout_box_append((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child));
}

PREFIX value ml_elm_layout_box_prepend_with_bool(
        value v_obj, value v_part, value v_child)
{
        return Val_Eina_Bool(elm_layout_box_prepend((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child));
}

PREFIX value ml_elm_layout_box_insert_before_with_bool(
        value v_obj, value v_part, value v_child, value v_ref)
{
        return Val_Eina_Bool(elm_layout_box_insert_before((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child,
                (Evas_Object*) v_ref));
}


PREFIX value ml_elm_layout_box_insert_at_with_bool(
        value v_obj, value v_part, value v_child, value v_pos)
{
        return Val_Eina_Bool(elm_layout_box_insert_at((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child,
                Int_val(v_pos)));
}

PREFIX value ml_elm_layout_box_remove(value v_obj, value v_part, value v_child)
{
        Evas_Object* obj = elm_layout_box_remove((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child);
        value v;
        if(obj == NULL) return Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, (value) obj);
                return Val_unit;
        }
}

PREFIX value ml_elm_layout_box_remove_all_with_bool(
        value v_obj, value v_part, value v_clear)
{
        return Val_Eina_Bool(elm_layout_box_remove_all((Evas_Object*) v_obj,
                String_val(v_part), Eina_Bool_val(v_clear)));
}

PREFIX value ml_elm_layout_table_pack_with_bool_native(
        value v_obj, value v_part, value v_child, value v_col, value v_row,
        value v_colspan, value v_rowspan)
{
        return Val_Eina_Bool(elm_layout_table_pack((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child, Int_val(v_col),
                Int_val(v_row), Int_val(v_colspan), Int_val(v_rowspan)));
}

PREFIX value ml_elm_layout_table_pack_with_bool_byte(value* argv, int argn)
{
        return ml_elm_layout_table_pack_with_bool_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5], argv[6]);
}

PREFIX value ml_elm_layout_table_unpack(
        value v_obj, value v_part, value v_child)
{
        Evas_Object* obj = elm_layout_table_unpack((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child);
        value v;
        if(obj == NULL) return Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, (value) obj);
                return v;
        }
}

PREFIX value ml_elm_layout_table_clear_with_bool(
        value v_obj, value v_part, value v_clear)
{
        return Val_Eina_Bool(elm_layout_table_clear((Evas_Object*) v_obj,
                String_val(v_part), Eina_Bool_val(v_clear)));
}

PREFIX value ml_elm_layout_edje_get(value v_obj)
{
        return (value) elm_layout_edje_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_layout_data_get(value v_obj, value v_key)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* data = elm_layout_data_get((Evas_Object*) v_obj,
                String_val(v_key));
        if(data == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, copy_string(data));
        }
        CAMLreturn(v);
}

PREFIX value ml_elm_layout_sizing_eval(value v_obj)
{
        elm_layout_sizing_eval((Evas_Object*) v_obj);
        return Val_unit;
}

