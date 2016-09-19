#ifndef EINA_H
#define EINA_H

#include "include.h"

 Eina_Bool Eina_Bool_val(value v);
 value Val_Eina_Bool(Eina_Bool b);

 value copy_Eina_List_string(const Eina_List* list);
 Eina_List* Eina_List_string_val(value v);
 Eina_List* Eina_List_string_malloc_val(value v);

 value copy_Eina_List_Evas_Object(const Eina_List* list);
 Eina_List* Eina_List_Evas_Object_val(value v_list);

 value copy_Eina_List_Elm_Object_Item(const Eina_List* list);

 Elm_Object_Item* Elm_Object_Item_opt_val(value v);
 value copy_Elm_Object_Item_opt(const Elm_Object_Item* it);

 value copy_string_opt(const char* s);

 value copy_Evas_Object_opt(const Evas_Object* obj);

 Evas_Object* Evas_Object_opt_val(value v);
 const char* String_opt_val(value v);

 int Int_opt_val(value v);

 value copy_Eina_List_Eina_Rectangle(const Eina_List* list);

 value Val_Eina_Bool_ptr(Eina_Bool* ptr);
 value copy_double_ptr(double* ptr);
 value copy_string_string(char** x);

value copy_voidp(void* p);
void* voidp_val(value v);

#endif
