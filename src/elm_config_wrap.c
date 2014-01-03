#include "include.h"

PREFIX value ml_elm_config_cache_flush_interval_get(value v_unit)
{
        return Val_int(elm_config_cache_flush_interval_get());
}

PREFIX value ml_elm_config_cache_flush_interval_set(value v_x)
{
        elm_config_cache_flush_interval_set(Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_cache_flush_enabled_get(value v_unit)
{
        return Val_bool(elm_config_cache_flush_enabled_get());
}

PREFIX value ml_elm_config_cache_flush_enabled_set(value v_flag)
{
        elm_config_cache_flush_enabled_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_cache_font_cache_size_get(value v_unit)
{
        return Val_int(elm_config_cache_font_cache_size_get());
}

PREFIX value ml_elm_config_cache_font_cache_size_set(value v_x)
{
        elm_config_cache_font_cache_size_set(Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_cache_image_cache_size_get(value v_unit)
{
        return Val_int(elm_config_cache_image_cache_size_get());
}

PREFIX value ml_elm_config_cache_image_cache_size_set(value v_x)
{
        elm_config_cache_image_cache_size_set(Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_cache_edje_file_cache_size_get(value v_unit)
{
        return Val_int(elm_config_cache_edje_file_cache_size_get());
}

PREFIX value ml_elm_config_cache_edje_file_cache_size_set(value v_x)
{
        elm_config_cache_edje_file_cache_size_set(Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_cache_edje_collection_cache_size_get(value v_unit)
{
        return Val_int(elm_config_cache_edje_collection_cache_size_get());
}

PREFIX value ml_elm_config_cache_edje_collection_cache_size_set(value v_x)
{
        elm_config_cache_edje_collection_cache_size_set(Int_val(v_x));
        return Val_unit;
}

PREFIX value ml_elm_config_cursor_engine_only_get(value v_unit)
{
        return Val_bool(elm_config_cursor_engine_only_get());
}

PREFIX value ml_elm_config_cursor_engine_only_set(value v_flag)
{
        elm_config_cursor_engine_only_set(Bool_val(v_flag));
        return Val_unit;
}

/* Elementary Config */

PREFIX value ml_elm_config_save(value v_unit)
{
        return Val_bool(elm_config_save());
}

PREFIX value ml_elm_config_reload(value v_unit)
{
        elm_config_reload();
        return Val_unit;
}

PREFIX value ml_elm_config_all_flush(value v_unit)
{
        elm_config_all_flush();
        return Val_unit;
}

/* Elementary Engine */

PREFIX value ml_elm_config_engine_get(value v_unit)
{
        return copy_string(elm_config_engine_get());
}

PREFIX value ml_elm_config_engine_set(value v_engine)
{
        elm_config_engine_set(String_val(v_engine));
        return Val_unit;
}

PREFIX value ml_elm_config_preferred_engine_get(value v_unit)
{
        return copy_string(elm_config_preferred_engine_get());
}

PREFIX value ml_elm_config_preferred_engine_set(value v_preferred_engine)
{
        elm_config_preferred_engine_set(String_val(v_preferred_engine));
        return Val_unit;
}

PREFIX value ml_elm_config_access_get(value v_unit)
{
        return Val_bool(elm_config_access_get());
}

PREFIX value ml_elm_config_access_set(value v_flag)
{
        elm_config_access_set(Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_config_mirrored_get(value v_unit)
{
        return Val_bool(elm_config_mirrored_get());
}

PREFIX value ml_elm_config_mirrored_set(value v_flag)
{
        elm_config_mirrored_set(Bool_val(v_flag));
        return Val_unit;
}

/* Elementary Fonts */

PREFIX value copy_Elm_Text_Class(Elm_Text_Class* c)
{
        CAMLparam0();
        CAMLlocal1(v);
        Store_field(v, 0, copy_string(c->name));
        Store_field(v, 1, copy_string(c->desc));
        CAMLreturn(v);
}

PREFIX inline value copy_Eina_List_Elm_Text_Class(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal3(v, v1, v_s);
        Eina_List* it;
        Elm_Text_Class* s;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, s) {
                v1 = v;
                v_s = copy_Elm_Text_Class(s);
                v = caml_alloc(2, 0);
                Store_field(v, 0, v_s);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

