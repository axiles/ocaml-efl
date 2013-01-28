#include "include.h"

PREFIX value ml_elm_config_engine_get(value v_unit)
{
        return copy_string(elm_config_engine_get());
}

