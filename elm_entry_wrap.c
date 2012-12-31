#include "include.h"

PREFIX value ml_elm_entry_add(value v_parent)
{
        Evas_Object* entry = elm_entry_add((Evas_Object*) v_parent);
        if(entry == NULL) caml_failwith("ml_elm_entry_add");
        return (value) entry;
}

PREFIX value ml_elm_entry_text_style_user_push(value v_obj, value v_style)
{
        elm_entry_text_style_user_push((Evas_Object*) v_obj,
                (const char*) String_val(v_style));
        return Val_unit;
}

PREFIX value ml_elm_entry_text_style_user_pop(value v_obj)
{
        elm_entry_text_style_user_pop((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_text_style_user_peek(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        char* text = (char*) elm_entry_text_style_user_peek(
                (Evas_Object*) v_obj);
        if(text == NULL) return Val_int(0);
        v = caml_alloc(1, 0);
        Store_field(v, 0, copy_string(text));
        CAMLreturn(v);
}

PREFIX value ml_elm_entry_single_line_set(value v_obj, value v_flag)
{
        elm_entry_single_line_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_single_line_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_single_line_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_password_set(value v_obj, value v_flag) {
        elm_entry_password_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_password_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_password_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_entry_set(value v_obj, value v_entry)
{
        elm_entry_entry_set((Evas_Object*) v_obj, String_val(v_entry));
        return Val_unit;
}

PREFIX value ml_elm_entry_entry_get(value v_obj)
{
        return copy_string(elm_entry_entry_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_entry_append(value v_obj, value v_entry)
{
        elm_entry_entry_append((Evas_Object*) v_obj, String_val(v_entry));
        return Val_unit;
}

PREFIX value ml_elm_entry_is_empty(value v_obj)
{
        return Val_Eina_Bool(elm_entry_is_empty((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_selection_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* text = elm_entry_selection_get((Evas_Object*) v_obj);
        v = caml_alloc(1, 0);
        Store_field(v, 0, copy_string(text));
        CAMLreturn(v);
}

PREFIX value ml_elm_entry_textblock_get(value v_obj)
{
        return (value) elm_entry_textblock_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_entry_calc_force(value v_obj)
{
        elm_entry_calc_force((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_entry_insert(value v_obj, value v_entry)
{
        elm_entry_entry_insert((Evas_Object*) v_obj, String_val(v_entry));
        return Val_unit;
}

PREFIX value ml_elm_entry_line_wrap_set(value v_obj, value v_wrap)
{
        elm_entry_line_wrap_set((Evas_Object*) v_obj,
                Elm_Wrap_Type_val(v_wrap));
        return Val_unit;
}

PREFIX value ml_elm_entry_line_wrap_get(value v_obj)
{
        return Val_Elm_Wrap_Type(elm_entry_line_wrap_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_editable_set(value v_obj, value v_flag)
{
        elm_entry_editable_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_editable_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_editable_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_select_none(value v_obj) {
        elm_entry_select_none((Evas_Object*) v_obj);
        return Val_unit;
}

