OCAMLFIND_OPT= -destdir $(DESTDIR)$(OCAMLFIND_DESTDIR) \
	-ldconf $(DESTDIR)$(OCAMLFIND_LDCONF)

.PHONY:examples

EXTRA_DIST=src examples/*.ml _tags

all-local:
	@$(OCAMLBUILD) src/efl.cma src/efl.cmxa src/efl.cmxs

byte:
	@$(OCAMLBUILD) src/efl.cma

native:
	@$(OCAMLBUILD) src/efl.cmxa src/efl.cmxs

install:
	@mkdir -p $(DESTDIR)$(OCAMLFIND_DESTDIR)
	@$(OCAMLFIND) install $(OCAMLFIND_OPT) efl META _build/src/efl.cma \
		_build/src/efl.cmi -optional _build/src/efl.cmxa \
		-optional _build/src/efl.cmxs _build/src/dllefl_stubs.so \
		-optional _build/src/libefl_stubs.a -optional _build/src/efl.a
	@src/install-doc.sh $(DESTDIR)$(docdir)
	@examples/install.sh $(DESTDIR)$(bindir)/ocaml-efl_

uninstall:
	@$(OCAMLFIND) remove $(OCAMLFIND_OPT) efl
	@src/uninstall-doc.sh $(DESTDIR)$(docdir)
	@examples/uninstall.sh $(DESTDIR)$(bindir)/ocaml-efl_

doc:
	@$(OCAMLBUILD) src/efl_doc.docdir/index.html

examples:
	@$(OCAMLBUILD) ex

clean-local:
	@$(OCAMLBUILD) -clean
	@echo ""

distclean-local:
	rm -f examples/list.txt

distcheck: dist
	tar -xzf $(PACKAGE_NAME)-$(PACKAGE_VERSION).tar.gz
	cd $(PACKAGE_NAME)-$(PACKAGE_VERSION) && \
		./configure && make && make doc && make examples && make distclean
	rm -rf $(PACKAGE_NAME)-$(PACKAGE_VERSION)

