#include "include.h"

PREFIX value ml_elm_image_add(value v_parent)
{
        Evas_Object* obj = elm_image_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_image_add");
        return copy_Evas_Object(obj);
}

PREFIX value ml_elm_image_file_set(
        value v_obj, value v_file, value v_group, value v_unit)
{
        const char* group;
        if(v_group == Val_int(0)) group = NULL;
        else group = String_val(Field(v_group, 0));
        return Val_Eina_Bool(elm_image_file_set(Evas_Object_val(v_obj),
                String_val(v_file), group));
}

PREFIX value ml_elm_image_file_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        const char *file, *group;
        elm_image_file_get(Evas_Object_val(v_obj), &file, &group);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_string(file));
        if(group == NULL) v1 = Val_int(0);
        else {
                v1 = caml_alloc(1, 0);
                Store_field(v1, 0, copy_string(group));
        }
        Store_field(v, 1, v1);
        CAMLreturn(v);
}

PREFIX value ml_elm_image_object_size_get(value v_obj)
{
        int x, y;
        elm_image_object_size_get(Evas_Object_val(v_obj), &x, &y);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        return v;
}

PREFIX value ml_elm_image_resizable_get(value v_obj)
{
        Eina_Bool up, down;
        elm_image_resizable_get(Evas_Object_val(v_obj), &up, &down);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_Eina_Bool(up));
        Store_field(v, 1, Val_Eina_Bool(down));
        return v;
}

PREFIX value ml_elm_image_object_get(value v_obj)
{
        Evas_Object* obj = elm_image_object_get(Evas_Object_val(v_obj));
        if(obj == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) obj);
        return v;
}

