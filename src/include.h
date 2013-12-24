#ifndef INCLUDE_H
#define INCLUDE_H

/* Common headers */

#include <stdio.h>

/* OCaml headers */

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/threads.h>

/* EFL headers */

#include <Elementary.h>

/* Prefix used on all functions */

#define PREFIX CAMLprim EAPI

/* Convenient macros */

#define CAMLparam0Acquire() \
  caml_acquire_runtime_system(); \
  struct caml__roots_block *caml__frame = caml_local_roots

#define CAMLparam1Acquire(x) \
  CAMLparam0Acquire(); \
  CAMLxparam1(x)

#define CAMLparam2Acquire(x, y) \
  CAMLparam0Acquire(); \
  CAMLxparam2(x, y)

#define CAMLparam3Acquire(x, y, z) \
  CAMLparam0Acquire(); \
  CAMLxparam3(x, y, z)


#define CAMLparam4Acquire(x, y, z, t) \
  CAMLparam0Acquire(); \
  CAMLxparam4(x, y, z, t)

#define CAMLparam5Acquire(x, y, z, t, u) \
  CAMLparam0Acquire(); \
  CAMLxparam5(x, y, z, t, u)

#define CAMLparamNRelease(x, size) \
  CAMLparam0Acquire (); \
  CAMLxparamN (x, (size))

#define CAMLreturn0Release do{ \
  caml_local_roots = caml__frame; \
  caml_release_runtime_system(); \
  return; \
}while (0)

#define CAMLreturnTRelease(type, result) do{ \
  type caml__temp_result = (result); \
  caml_local_roots = caml__frame; \
  caml_release_runtime_system(); \
  return (caml__temp_result); \
}while(0)

/* Local headers */

#include "variants.h"
#include "eina_wrap.h"
#include "evas_wrap.h"
#include "ecore_wrap.h"
#include "edje_wrap.h"
#include "elm_wrap.h"
#include "elm_object_wrap.h"
#include "elm_gen_wrap.h"
#include "elm_scroller_wrap.h"
#include "elm_list_wrap.h"
#include "elm_tooltip_wrap.h"

#endif

