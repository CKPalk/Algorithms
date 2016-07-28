
META = $(patsubst %,../Metadata/%,metadata.h)
SORT_DIR = Sorting
SORT = $(SORT_DIR)/sorting_controller.c


all: sorting


sorting: $(SORT) $(SORT_DIR)/Selection/*.c $(SORT_DIR)/Selection/*.h
	gcc -o ../sorting $(SORT) $(SORT_DIR)/Selection/*.c -I./$(SORT_DIR)/Selection


.PHONY: all sorting clean

clean:
	rm *.o
