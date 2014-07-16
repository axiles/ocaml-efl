%{
  open Expr
%}

%token LB RB SECTION ENUM EOF
%token<string> IDENT
%token<int> INT

%type<string> variant
%type<string list> variant_list
%type<enum> enum
%type<enum list> enum_list
%type<section> section
%type<section list> section_list
%type<Expr.t> expr

%start expr

%%

expr: section_list EOF { List.rev $1 }

section_list:
| section { [ $1 ] }
| section_list section { $2 :: $1 }

section: SECTION IDENT LB enum_list RB { {name = $2; enums = List.rev $4} }

enum_list:
| enum { [ $1 ] }
| enum_list enum { $2 :: $1 }

enum:
| ENUM IDENT IDENT INT LB variant_list RB {
  {ml_name = $2; c_name = $3; prefix_length = Some $4; variants = List.rev $6}
}
| ENUM IDENT IDENT LB variant_list RB {
  {ml_name = $2; c_name = $3; prefix_length = None; variants = List.rev $5}
}

variant_list:
| variant { [ $1 ] }
| variant_list variant { $2 :: $1 }

variant: IDENT { $1 }

