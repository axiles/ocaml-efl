{
  open Parser
}

rule token = parse
| "\""['a'-'z' 'A'-'Z' '0'-'9' ',' '_']*"\"" as s {STRING s}
| ['a'-'z' 'A'-'Z']['a'-'z' 'A'-'Z' '0'-'9' '_']* as s {IDENT s}
| ' ' | '\t' | '\n' {token lexbuf}
| eof {EOF}
