assets.h: $(wildcard assets/*.png) assets_to_c.py
	./assets_to_c.py > assets.h

main.bin: main.c assets.h
	zcc +zx $< -o main.bin

main.tap: main.c assets.h
	zcc +zx $< -create-app -m -s --list
	mv a.tap main.tap
