
/*
 * This file is part of outputStream
 * Licensed under the MIT License 
 * Copyright (c) 2022 Kshitej Jadhav
 */
#ifndef TERMDEFS_HPP
#define TERMDEFS_HPP
#include <array>

#define TERMINAL_OPTIONS \
TERM_OPS ( none , ""), \
TERM_OPS (black, "\033[30m"),\
TERM_OPS (red, "\033[31m"),\
TERM_OPS (green, "\033[32m"),\
TERM_OPS (orange, "\033[33m"),\
TERM_OPS (blue, "\033[34m"),\
TERM_OPS (purple, "\033[35m"),\
TERM_OPS (cyan, "\033[36m"),\
TERM_OPS (gray, "\033[37m"),\
TERM_OPS (white, "\033[97m"),\
TERM_OPS (dk_gray, "\033[90m"),\
TERM_OPS (lt_red, "\033[91m"),\
TERM_OPS (lt_green, "\033[92m"),\
TERM_OPS (yellow, "\033[93m"),\
TERM_OPS (lt_blue, "\033[94m"),\
TERM_OPS (lt_purple, "\033[95m"),\
TERM_OPS (lt_cyan, "\033[96m"),\
TERM_OPS (bg_black, "\033[40m"),\
TERM_OPS (bg_red, "\033[41m"),\
TERM_OPS (bg_green, "\033[42m"),\
TERM_OPS (bg_orange, "\033[43m"),\
TERM_OPS (bg_cyan, "\033[44m"),\
TERM_OPS (bg_purple, "\033[45m"),\
TERM_OPS (bg_blue, "\033[46m"),\
TERM_OPS (bg_gray, "\033[47m"),\
TERM_OPS (bg_dk_gray, "\033[100m"),\
TERM_OPS (bg_lt_red, "\033[101m"),\
TERM_OPS (bg_lt_green, "\033[102m"),\
TERM_OPS (bg_yellow, "\033[103m"),\
TERM_OPS (bg_lt_blue, "\033[104m"),\
TERM_OPS (bg_lt_purple, "\033[105m"),\
TERM_OPS (bg_lt_cyan, "\033[106m"),\
TERM_OPS (bg_white, "\033[107m"),\
TERM_OPS (bd_black, "\033[1;30m"),\
TERM_OPS (bd_red, "\033[1;31m"),\
TERM_OPS (bd_green, "\033[1;32m"),\
TERM_OPS (bd_orange, "\033[1;33m"),\
TERM_OPS (bd_blue, "\033[1;34m"),\
TERM_OPS (bd_purple, "\033[1;35m"),\
TERM_OPS (bd_cyan, "\033[1;36m"),\
TERM_OPS (bd_gray, "\033[1;37m"),\
TERM_OPS (bold, "\033[1m" ),\
TERM_OPS (faint, "\033[2m" ),\
TERM_OPS (italics, "\033[3m" ),\
TERM_OPS (underlined, "\033[4m" ),\
TERM_OPS (blink, "\033[5m" ),\
TERM_OPS (inverse, "\033[7m" ),\
TERM_OPS (invisible, "\033[8m" ),\
TERM_OPS (crossed, "\033[9m" ),\
TERM_OPS (d_underlined, "\033[21m"),\
TERM_OPS (bell, "\x07" ),\
TERM_OPS (backspace, "\b" ),\
TERM_OPS (newline, "\n" ),\
TERM_OPS (tab, "\t" ),\
TERM_OPS (carriage_return, "\r" ),\
TERM_OPS (form_feed, "\f" ),\
TERM_OPS (vertical_tab, "\v" ),\
TERM_OPS (escape, "\033" ),\
TERM_OPS (null, "\0" ),\
TERM_OPS (space, " " ),\
TERM_OPS (hide_cursor, "\033[?25l" ),\
TERM_OPS (show_cursor, "\033[?25h" ),\
TERM_OPS (rst_all, "\033[0m" ),\
TERM_OPS (rst_bold, "\033[21m" ),\
TERM_OPS (rst_italics, "\033[23m" ),\
TERM_OPS (rst_underlined, "\033[24m" ),\
TERM_OPS (rst_blink, "\033[25m" ),\
TERM_OPS (rst_inverse, "\033[27m" ),\
TERM_OPS (rst_crossed, "\033[29m" ),\
TERM_OPS (rst_color, "\033[39m" ),\
TERM_OPS (rst_bg_color, "\033[49m" ),\
TERM_OPS (rst_bd_color, "\033[22m \033[39m" ),\
TERM_OPS (clear_screen, "\033[2J\033[H" ),\
TERM_OPS (clear_line, "\033[2K\033[0G" ),\
TERM_OPS (clear_to_end, "\033[0K" ),\
TERM_OPS (clear_to_end_of_line, "\033[K" ),\
TERM_OPS (clear , "\033[2J\033[H" ),\
TERM_OPS (cursor_up, "\033[%dA" ),\
TERM_OPS (cursor_down, "\033[%dB" ),\
TERM_OPS (cursor_forward, "\033[%dC" ),\
TERM_OPS (cursor_backward, "\033[%dD" ),\
TERM_OPS (cursor_home, "\033[H" ),

#define TERM_OPS(name, value) name
enum class t_ops {
TERMINAL_OPTIONS

MAX_OPTIONS
};
#undef TERM_OPS

constexpr std::array<const char*, (unsigned int)(t_ops::MAX_OPTIONS)> ops_array = {
#define TERM_OPS(name, value) value
    TERMINAL_OPTIONS
#undef TERM_OPS
};

#endif