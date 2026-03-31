#!/usr/bin/env python3
import re
import sys

def die(msg: str) -> None:
    print(msg, file=sys.stderr)
    sys.exit(1)

def extract_strings(lines):
    out = []
    for line in lines:
        out.extend(re.findall(r'"([^\"]*)"', line))
    return out

def parse_header(h: str):
    parts = h.strip().split()
    if len(parts) < 4:
        die("invalid xpm header")
    w = int(parts[0])
    hgt = int(parts[1])
    n = int(parts[2])
    cpp = int(parts[3])
    if w <= 0 or hgt <= 0 or n <= 0 or cpp <= 0:
        die("invalid xpm header values")
    return w, hgt, n, cpp

def parse_color(line: str, cpp: int):
    if len(line) < cpp:
        die("invalid color line")
    key = line[:cpp]
    rest = line[cpp:].strip()

    tokens = rest.split()
    color = None
    i = 0
    while i < len(tokens):
        if tokens[i] == 'c' and i + 1 < len(tokens):
            color = tokens[i + 1]
            break
        i += 1

    if color is None and tokens:
        color = tokens[-1]

    if not color:
        die("missing color value")

    color_lower = color.lower()
    if color_lower == 'none':
        return key, "#00000000"
    if color.startswith('#'):
        hexpart = color[1:]
        if len(hexpart) == 6:
            return key, "#" + hexpart.upper() + "FF"
        if len(hexpart) == 8:
            return key, "#" + hexpart.upper()
    die("unsupported color format")

def main():
    if len(sys.argv) != 2:
        die("usage: xpm_to_xpm42.py <file.xpm>")
    src = sys.argv[1]
    if not src.endswith('.xpm'):
        die("not a .xpm file")

    with open(src, 'r', encoding='utf-8', errors='replace') as f:
        lines = f.readlines()

    strings = extract_strings(lines)
    if not strings:
        die("no xpm data found")

    width, height, colors_count, cpp = parse_header(strings[0])
    if len(strings) < 1 + colors_count + height:
        die("truncated xpm")

    color_lines = strings[1:1 + colors_count]
    pixel_lines = strings[1 + colors_count:1 + colors_count + height]

    dst = src + "42"
    with open(dst, 'w', encoding='utf-8') as out:
        out.write("!XPM42\n")
        out.write(f"{width} {height} {colors_count} {cpp} c\n")
        for cl in color_lines:
            key, rgba = parse_color(cl, cpp)
            out.write(f"{key} {rgba}\n")
        for pl in pixel_lines:
            if len(pl) != width * cpp:
                die("invalid pixel row length")
            out.write(pl + "\n")

if __name__ == '__main__':
    main()
