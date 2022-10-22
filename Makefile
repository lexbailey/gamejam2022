
main.bin: main.c
	zcc +zx $< -o main.bin

main.tap: main.c
	zcc +zx $< -create-app -m -s --list
	mv a.tap main.tap
