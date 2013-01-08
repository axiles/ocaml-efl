#include "include.h"

PREFIX void ml_Edje_Signal_Cb(
        void* data, Evas_Object* obj, const char* emission, const char* source)
{
        CAMLparam0();
        CAMLlocal2(v_emission, v_source);
        value* v_fun = (value*) data;
        v_emission = copy_string(emission);
        v_source = copy_string(source);
        caml_callback3(*v_fun, (value) obj, v_emission, v_source);
        CAMLreturn0;
}

PREFIX value ml_edje_file_collection_list(value v_theme)
{
        Eina_List* list = edje_file_collection_list(String_val(v_theme));
        value v_list = copy_Eina_List_string(list);
        edje_file_collection_list_free(list);
        return v_list;
}

