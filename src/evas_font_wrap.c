#include "include.h"

PREFIX value ml_evas_font_hinting_set(value v_e, value v_h)
{
        evas_font_hinting_set(Evas_val(v_e), Evas_Font_Hinting_Flags_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_font_hinting_get(value v_e)
{
        return Val_Evas_Font_Hinting_Flags(evas_font_hinting_get(
                Evas_val(v_e)));
}

PREFIX value ml_evas_font_hinting_can_hint(value v_e, value v_h)
{
        return Val_bool(evas_font_hinting_can_hint(Evas_val(v_e),
                Evas_Font_Hinting_Flags_val(v_h)));
}

PREFIX value ml_evas_font_cache_flush(value v_e)
{
        evas_font_cache_flush(Evas_val(v_e));
        return Val_unit;
}

PREFIX value ml_evas_font_cache_set(value v_e, value v_size)
{
        evas_font_cache_set(Evas_val(v_e), Int_val(v_size));
        return Val_unit;
}

PREFIX value ml_evas_font_cache_get(value v_e)
{
        return Val_int(evas_font_cache_get(Evas_val(v_e)));
}

PREFIX value ml_evas_font_available_list(value v_e)
{
        Eina_List* list = evas_font_available_list(Evas_val(v_e));
        value v_list = copy_Eina_List_string(list);
        evas_font_available_list_free(Evas_val(v_e), list);
        return v_list;
}

PREFIX value ml_evas_font_path_clear(value v_e)
{
        evas_font_path_clear(Evas_val(v_e));
        return Val_unit;
}

PREFIX value ml_evas_font_path_append(value v_e, value v_path)
{
        evas_font_path_append(Evas_val(v_e), String_val(v_path));
        return Val_unit;
}

PREFIX value ml_evas_font_path_prepend(value v_e, value v_path)
{
        evas_font_path_prepend(Evas_val(v_e), String_val(v_path));
        return Val_unit;
}

PREFIX value ml_evas_font_path_list(value v_e)
{
        return copy_Eina_List_string(evas_font_path_list(Evas_val(v_e)));
}

