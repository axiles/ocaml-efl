{
  open Parser
}

rule token = parse
| "{" { LB }
| "}" { RB }
| "Section" { SECTION }
| "Enum" { ENUM }
| eof { EOF }
| ' ' | '\t' | '\n' {token lexbuf}
| ['a'-'z' 'A'-'Z']['a'-'z' 'A'-'Z' '0'-'9' '_']* as s { IDENT s }
| ['0'-'9']+ as s {INT (int_of_string s) }

