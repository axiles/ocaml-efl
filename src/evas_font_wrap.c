#include "include.h"

inline Evas_Font_Hinting_Flags Evas_Font_Hinting_Flags_val(value v)
{
        switch(v) {
                case Val_none: return EVAS_FONT_HINTING_NONE;
                case Val_auto: return EVAS_FONT_HINTING_AUTO;
                case Val_bytecode: return EVAS_FONT_HINTING_BYTECODE;
                default: break;
        }
        caml_failwith("Evas_Font_Hinting_Flags_val");
        return EVAS_FONT_HINTING_NONE;
}

inline value Val_Evas_Font_Hinting_Flags(Evas_Font_Hinting_Flags f)
{
        switch(f) {
                case EVAS_FONT_HINTING_NONE: return Val_none;
                case EVAS_FONT_HINTING_AUTO: return Val_auto;
                case EVAS_FONT_HINTING_BYTECODE: return Val_bytecode;
        }
        caml_failwith("Val_Evas_Font_Hinting_Flags");
        return Val_none;
}

PREFIX value ml_evas_font_hinting_set(value v_e, value v_h)
{
        evas_font_hinting_set((Evas*) v_e, Evas_Font_Hinting_Flags_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_font_hinting_get(value v_e)
{
        return Val_Evas_Font_Hinting_Flags(evas_font_hinting_get((Evas*) v_e));
}

PREFIX value ml_evas_font_hinting_can_hint(value v_e, value v_h)
{
        return Val_bool(evas_font_hinting_can_hint((Evas*) v_e,
                Evas_Font_Hinting_Flags_val(v_h)));
}

PREFIX value ml_evas_font_cache_flush(value v_e)
{
        evas_font_cache_flush((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_font_cache_set(value v_e, value v_size)
{
        evas_font_cache_set((Evas*) v_e, Int_val(v_size));
        return Val_unit;
}

PREFIX value ml_evas_font_cache_get(value v_e)
{
        return Val_int(evas_font_cache_get((Evas*) v_e));
}

PREFIX value ml_evas_font_available_list(value v_e)
{
        Eina_List* list = evas_font_available_list((Evas*) v_e);
        value v_list = copy_Eina_List_string(list);
        evas_font_available_list_free((Evas*) v_e, list);
        return v_list;
}

PREFIX value ml_evas_font_path_clear(value v_e)
{
        evas_font_path_clear((Evas*) v_e);
        return Val_unit;
}

PREFIX value ml_evas_font_path_append(value v_e, value v_path)
{
        evas_font_path_append((Evas*) v_e, String_val(v_path));
        return Val_unit;
}

PREFIX value ml_evas_font_path_prepend(value v_e, value v_path)
{
        evas_font_path_prepend((Evas*) v_e, String_val(v_path));
        return Val_unit;
}

PREFIX value ml_evas_font_path_list(value v_e)
{
        return copy_Eina_List_string(evas_font_path_list((Evas*) v_e));
}

