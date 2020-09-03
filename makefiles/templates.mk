define COMPILE_template
$(OBJ_DIR)/%.o: $(1)/src/%.cpp $(1)/inc/%.h $(DEP_DIR)/%.d | $(DEP_DIR)
	$(CPP) $(COMPILE_FLAGS) $(DEP_FLAGS) -c -o $$@ $$<

$(1)/inc/%.h: $(1)/src/%.o
endef
