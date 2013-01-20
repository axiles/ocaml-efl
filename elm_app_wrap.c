#include "include.h"

PREFIX value ml_elm_app_info_set(value v_name, value v_checkfile, value v_unit)
{
        const char* checkfile;
        if(v_checkfile == Val_int(0)) checkfile = NULL;
        else checkfile = String_val(Field(v_checkfile, 0));
        elm_app_info_set(NULL, String_val(v_name), checkfile);
        return Val_unit;
}

