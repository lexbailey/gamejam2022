#      --lib-path            <path> use this path to search for libraries
#      --out-fmt-ihx         Output in Intel hex format
#      --out-fmt-s19         Output in S19 hex format
#      --xram-loc            <nnnn> External Ram start location
#      --xram-size           <nnnn> External Ram size
#      --iram-size           <nnnn> Internal Ram size
#      --xstack-loc          <nnnn> External Stack start location
#      --code-loc            <nnnn> Code Segment Location
#      --code-size           <nnnn> Code Segment size
#      --stack-loc           <nnnn> Stack pointer initial value
#      --data-loc            <nnnn> Direct data start location
#      --idata-loc  

main.tap: main.c
	zcc +zx $< -create-app
	mv a.tap main.tap
