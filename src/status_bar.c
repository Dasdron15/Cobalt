#include "status_bar.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curses.h>

#include "editor.h"
#include "cursor.h"
#include "common.h"

void draw_status_bar() {
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);

    int pos = cursor.x - editor.margin + cursor.x_offset;

    char path[64];
    char cursor_info[64];

    sprintf(path, " %s%s", get_filename(editor.filename),
            editor.is_saved ? "" : " [+]");
    sprintf(cursor_info, "Ln %d, Col %d", cursor.y + cursor.y_offset + 1,
            pos + 1);

    int space_length = max_x - strlen(path) - strlen(cursor_info);

    if (space_length < 0) {
        space_length = 0;
    }

    char *padding = mult_char(' ', space_length);
    mvprintw(max_y - 2, 0, "%s%s%s", path, padding, cursor_info);
    free(padding);
}
