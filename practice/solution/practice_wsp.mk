.PHONY: clean All

All:
	@echo "----------Building project:[ quora - Debug ]----------"
	@cd "E:\Varun\GitHub\learn\challenges\quora\solution" && $(MAKE) -f  "quora.mk"
clean:
	@echo "----------Cleaning project:[ quora - Debug ]----------"
	@cd "E:\Varun\GitHub\learn\challenges\quora\solution" && $(MAKE) -f  "quora.mk" clean
