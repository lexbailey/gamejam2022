#!/usr/bin/env python3
from PIL import Image

def to_vals(l):
    l = ''.join(map(str,l))
    a = int(l[0:8],2)
    b = int(l[8:],2)
    return '0x%02x, 0x%02x, ' % (a, b)

def do_image(name):
    im = Image.open(name);
    if im.size != (16,16):
        print(f'Error: {name} is not 16x16 pixels')
    print(f'// {name}')
    for y in range(8):
        row1 = [1-int(im.getpixel((x,y))[0]/255) for x in range(16)]
        row2 = [1-int(im.getpixel((x,y+8))[0]/255) for x in range(16)]
        print(to_vals(row1) + to_vals(row2))
        
for name in ['assets/bat.png', 'assets/ghost.png', 'assets/spider.png']:
    do_image(name)
