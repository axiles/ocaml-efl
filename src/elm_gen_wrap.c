#include "include.h"

char* ml_Elm_Gen_Item_Text_Get_Cb(
        void* data, Evas_Object* obj, const char* part)
{
        CAMLparam0();
        CAMLlocal3(v_obj, v_part, v);
        value* v_class = data;
        v_obj = copy_Evas_Object(obj);
        v_part = copy_string(part);
        v = caml_callback2(Field(*v_class, 1), v_obj, v_part);
        char* r = strdup(String_val(v));
        if(r == NULL) caml_raise_out_of_memory();
        CAMLreturnT(char*, r);
}

Evas_Object* ml_Elm_Gen_Item_Content_Get_Cb(
        void* data, Evas_Object* obj, const char* part)
{
        CAMLparam0();
        CAMLlocal3(v_obj, v_part, v);
        value* v_class = data;
        v_part = copy_string(part);
        v_obj = copy_Evas_Object(obj);
        v = caml_callback2(Field(*v_class, 2), v_obj, v_part);
        if(v == Val_int(0)) CAMLreturnT(Evas_Object*, NULL);
        else CAMLreturnT(Evas_Object*, Evas_Object_val(Field(v, 0)));
}

Eina_Bool ml_Elm_Gen_Item_State_Get_Cb(
        void* data, Evas_Object* obj, const char* part)
{
        CAMLparam0();
        CAMLlocal3(v_obj, v_part, v);
        value* v_class = data;
        v_obj = copy_Evas_Object(obj);
        v_part = copy_string(part);
        v = caml_callback2(Field(*v_class, 3), v_obj, v_part);
        CAMLreturnT(Eina_Bool, Eina_Bool_val(v));
}

void ml_Elm_Gen_Item_Del_Cb_free(void* data, Evas_Object* obj)
{
        CAMLparam0();
        CAMLlocal1(v_obj);
        value* v_class = data;
        v_obj = copy_Evas_Object(obj);
        caml_callback(Field(*v_class, 4), v_obj);
        ml_remove_value(v_class);
        CAMLreturn0;
}

