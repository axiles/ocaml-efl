{
  open Parser
}

rule token = parse
| "Section" { SECTION }
| "Struct" { STRUCT }
| "{" { LB }
| "}" { RB }
| "module" { MODULE }
| "*" { STAR }
| ";" { SC }
| ['a'-'z' 'A'-'Z']['a'-'z' 'A'-'Z' '0'-'9' '_' '.']* as s { IDENT s }
| ' ' | '\t' | '\n' { token lexbuf }
| eof { EOF }

