#include "include.h"

inline Eina_Bool Eina_Bool_val(value v) {
        return (Eina_Bool) Int_val(v);
}

inline value Val_Eina_Bool(Eina_Bool b) {
        return Val_int (b);
}

inline value copy_Eina_List_string(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal3(v, v1, v_s);
        Eina_List* it;
        char* s;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, s) {
                v1 = v;
                v_s = copy_string(s);
                v = caml_alloc(2, 0);
                Store_field(v, 0, v_s);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

inline Eina_List* Eina_List_string_val(value v_list)
{
        Eina_List* list = NULL;
        value v = v_list;
        while(v != Val_int(0)) {
                list = eina_list_append(list, String_val(Field(v, 0)));
                v = Field(v, 1);
        }
        return list;
}

inline Eina_List* Eina_List_string_malloc_val(value v_list)
{
        Eina_List* list = NULL;
        value v = v_list;
        while(v != Val_int(0)) {
                list = eina_list_append(list, strdup(String_val(Field(v, 0))));
                v = Field(v, 1);
        }
        return list;
}

inline value copy_Eina_List_Evas_Object(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_List* it;
        Evas_Object* obj;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, obj) {
                v1 = v;
                v = caml_alloc(2, 0);
                Store_field(v, 0, (value) obj);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

inline Eina_List* Eina_List_Evas_Object_val(value v_list)
{
        Eina_List* list = NULL;
        value v = v_list;
        while(v != Val_int(0)) {
                list = eina_list_append(list, (Evas_Object*) Field(v, 0));
                v = Field(v, 1);
        }
        return list;
}

inline value copy_Eina_List_Elm_Object_Item(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_List* it;
        Elm_Object_Item* item;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, item) {
                v1 = v;
                v = caml_alloc(2, 0);
                Store_field(v, 0, (value) item);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

inline Elm_Object_Item* Elm_Object_Item_opt_val(value v)
{
        Elm_Object_Item* it;
        if(v == Val_int(0)) it = NULL;
        else it = Elm_Object_Item_val(Field(v, 0));
        return it;
}

inline value copy_Elm_Object_Item_opt(const Elm_Object_Item* it)
{
        if(it == NULL) return Val_int(0);
        value v_r = caml_alloc(1, 0);
        Store_field(v_r, 0, (value) it);
        return v_r;
}

inline value copy_string_opt(const char* s)
{
        CAMLparam0();
        CAMLlocal1(v);
        if(s == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, copy_string(s));
        }
        CAMLreturn(v);
}

inline value copy_Evas_Object_opt(const Evas_Object* obj)
{
        if(obj == NULL) return Val_int(0);
        value v_r = caml_alloc(1, 0);
        Store_field(v_r, 0, (value) obj);
        return v_r;
}

inline Evas_Object* Evas_Object_opt_val(value v)
{
        if(v == Val_int(0)) return NULL;
        else return (Evas_Object*) Field(v, 0);
}

inline const char* String_opt_val(value v)
{
        if(v == Val_int(0)) return NULL;
        else return String_val(Field(v, 0));
}

inline int Int_opt_val(value v)
{
        if(v == Val_int(0)) return 0;
        else return Int_val(Field(v, 0));
}

inline value* ml_register_value(value v)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v;
        caml_register_generational_global_root(data);
        return data;
}

inline void ml_remove_value(value* data)
{
        caml_remove_generational_global_root(data);
        free(data);
}

inline value copy_Eina_Rectangle(Eina_Rectangle* rect)
{
        value v = caml_alloc(4, 0);
        Store_field(v, 0, rect->x);
        Store_field(v, 1, rect->y);
        Store_field(v, 2, rect->w);
        Store_field(v, 3, rect->h);
        return v;
}

inline value copy_Eina_List_Eina_Rectangle(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal3(v, v1, v_s);
        Eina_List* it;
        Eina_Rectangle* s;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, s) {
                v1 = v;
                v_s = copy_Eina_Rectangle(s);
                v = caml_alloc(2, 0);
                Store_field(v, 0, v_s);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

inline value safe_copy_string(const char* s)
{
        if(s == NULL) return copy_string("");
        else return copy_string(s);
}

inline value safe_copy_string_free(char* s)
{
        value v = safe_copy_string(s);
        free(s);
        return v;
}

inline value Val_Eina_Bool_ptr(Eina_Bool* ptr)
{
        return Val_bool(*ptr);
}


inline value copy_double_ptr(double* ptr)
{
        return copy_double(*ptr);
}

inline value copy_string_string(char** x)
{
        CAMLparam0();
        CAMLlocal1(v);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_string(x[0]));
        Store_field(v, 1, copy_string(x[1]));
        CAMLreturn(v);
}

