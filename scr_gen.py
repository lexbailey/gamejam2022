#!/usr/bin/env python3
with open('title_screen.scr', 'rb') as f:
    for b in f.read():
        print("0x%02x,"%b)
