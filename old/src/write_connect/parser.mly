%token REF EOF

%token<string> IDENT STRING

%type<Expr.Signal.t> signal
%type<Expr.Signal.t list> signal_list
%type<Expr.t> widget

%start widget

%%

signal:
| STRING {{Expr.Signal.name = $1; ty = None}}
| STRING IDENT {{Expr.Signal.name = $1; ty = Some $2}}

signal_list:
| signal {[$1]}
| signal_list signal {$2 :: $1}

widget:
| IDENT signal_list EOF {{Expr.name = $1; signals = List.rev $2}}

