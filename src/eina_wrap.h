#ifndef EINA_H
#define EINA_H

#include "include.h"

inline Eina_Bool Eina_Bool_val(value v);
inline value Val_Eina_Bool(Eina_Bool b);

inline value copy_Eina_List_string(const Eina_List* list);
inline Eina_List* Eina_List_string_val(value v);
inline Eina_List* Eina_List_string_malloc_val(value v);

inline value copy_Eina_List_Evas_Object(const Eina_List* list);
inline Eina_List* Eina_List_Evas_Object_val(value v_list);

inline value copy_Eina_List_Elm_Object_Item(const Eina_List* list);

inline value copy_Elm_Object_Item_opt(const Elm_Object_Item* it);

inline value copy_string_opt(const char* s);

inline value copy_Evas_Object_opt(const Evas_Object* obj);

inline Evas_Object* Evas_Object_opt_val(value v);
inline const char* String_opt_val(value v);

inline value copy_Eina_List_Eina_Rectangle(const Eina_List* list);

inline value Val_Eina_Bool_ptr(Eina_Bool* ptr);
inline value copy_double_ptr(double* ptr);
inline value copy_string_string(char** x);

#endif
