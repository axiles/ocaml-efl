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

