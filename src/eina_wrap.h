#ifndef EINA_H
#define EINA_H

#include "include.h"

PREFIX inline Eina_Bool Eina_Bool_val(value v);
PREFIX inline value Val_Eina_Bool(Eina_Bool b);

PREFIX inline value copy_Eina_List_string(const Eina_List* list);
PREFIX inline Eina_List* Eina_List_string_val(value v);
PREFIX inline Eina_List* Eina_List_string_malloc_val(value v);

PREFIX inline value copy_Eina_List_Evas_Object(const Eina_List* list);
PREFIX inline Eina_List* Eina_List_Evas_Object_val(value v_list);

PREFIX inline value copy_Eina_List_Elm_Object_Item(const Eina_List* list);

PREFIX inline value copy_Elm_Object_Item_opt(const Elm_Object_Item* it);

PREFIX inline value copy_string_opt(const char* s);

PREFIX inline value copy_Evas_Object_opt(const Evas_Object* obj);

#endif
