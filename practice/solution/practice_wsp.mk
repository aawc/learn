.PHONY: clean All

All:
	@echo "----------Building project:[ practice - Debug ]----------"
	@$(MAKE) -f  "practice.mk"
clean:
	@echo "----------Cleaning project:[ practice - Debug ]----------"
	@$(MAKE) -f  "practice.mk" clean
