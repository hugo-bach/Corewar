#!/usr/bin/env python3
##
## EPITECH PROJECT, 2018
## ascii_art.py
## File description:
## ascii art generator
##

import sys
from pyfiglet import Figlet

def main():
    if len(sys.argv) != 2:
        strs = "Champion"
    else:
        strs = sys.argv[1]
    if len(strs) > 8:
        strs = strs[:8]
    custom_fig = Figlet(font='larry3d')
    test = custom_fig.renderText(strs)
    fd = open("ascii_name.txt", "w")
    fd.write(test)

if __name__ == '__main__':
    main()
