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

