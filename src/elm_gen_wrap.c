#include "include.h"

PREFIX char* ml_Elm_Gen_Item_Text_Get_Cb(
        void* data, Evas_Object* obj, const char* part)
{
        CAMLparam0Acquire();
        CAMLlocal2(v_part, v);
        value* v_class = (value*) data;
        v_part = copy_string(part);
        v = caml_callback2(Field(*v_class, 1), (value) obj, v_part);
        char* r = strdup(String_val(v));
        if(r == NULL) caml_raise_out_of_memory();
        CAMLreturnTRelease(char*, r);
}

PREFIX Evas_Object* ml_Elm_Gen_Item_Content_Get_Cb(
        void* data, Evas_Object* obj, const char* part)
{
        CAMLparam0Acquire();
        CAMLlocal2(v_part, v);
        value* v_class = (value*) data;
        v_part = copy_string(part);
        v = caml_callback2(Field(*v_class, 2), (value) obj, v_part);
        if(v == Val_int(0)) CAMLreturnTRelease(Evas_Object*, NULL);
        else CAMLreturnTRelease(Evas_Object*, (Evas_Object*) Field(v, 0));
}

PREFIX Eina_Bool ml_Elm_Gen_Item_State_Get_Cb(
        void* data, Evas_Object* obj, const char* part)
{
        CAMLparam0Acquire();
        CAMLlocal2(v_part, v);
        value* v_class = (value*) data;
        v_part = copy_string(part);
        v = caml_callback2(Field(*v_class, 3), (value) obj, v_part);
        CAMLreturnTRelease(Eina_Bool, Eina_Bool_val(v));
}

PREFIX void ml_Elm_Gen_Item_Del_Cb(void* data, Evas_Object* obj)
{
        caml_acquire_runtime_system();
        value* v_class = (value*) data;
        caml_callback(Field(*v_class, 4), (value) obj);
        caml_release_runtime_system();
}

