#include "include.h"

PREFIX inline value copy_Elm_Font_Properties(Elm_Font_Properties* p)
{
        CAMLparam0();
        CAMLlocal1(v);
        Store_field(v, 0, copy_string(p->name));
        Store_field(v, 1, copy_Eina_List_string(p->styles));
        CAMLreturn(v);
}

PREFIX value ml_elm_font_properties_get(value v_font)
{
        Elm_Font_Properties* fp = elm_font_properties_get(String_val(v_font));
        value v_fp = copy_Elm_Font_Properties(fp);
        elm_font_properties_free(fp);
        return v_fp;
}

PREFIX value ml_elm_font_fontconfig_name_get(value v_name, value v_style)
{
        const char* style;
        if(v_style == Val_int(0)) style = NULL;
        else style = String_val(Field(v_style, 0));
        char* s = elm_font_fontconfig_name_get(String_val(v_name), style);
        if(s == NULL) caml_failwith("elm_fontconfig_name_get");
        value v_s = copy_string(s);
        elm_font_fontconfig_name_free(s);
        return v_s;
}

