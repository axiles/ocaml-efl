OCAMLFIND_OPT= -destdir $(DESTDIR)$(OCAMLFIND_DESTDIR) \
	-ldconf $(DESTDIR)$(OCAMLFIND_LDCONF)

all-local:
	@$(OCAMLBUILD) src/efl.cma src/efl.cmxa src/efl.cmxs

install-exec-local:
	@mkdir -p $(DESTDIR)$(OCAMLFIND_DESTDIR)
	@$(OCAMLFIND) install $(OCAMLFIND_OPT) efl src/META _build/src/efl.cma \
		_build/src/efl.cmi _build/src/efl.cmxa  _build/src/efl.cmxs \
		_build/src/dllefl_stubs.so _build/src/libefl_stubs.a _build/src/efl.a

uninstall-local:
	@$(OCAMLFIND) remove $(OCAMLFIND_OPT) efl

clean-local:
	@$(OCAMLBUILD) -clean
	@echo ""

