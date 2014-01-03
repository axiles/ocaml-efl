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

