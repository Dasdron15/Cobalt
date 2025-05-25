#include "editor.h"
#include "utils/fileio.h"
#include <curses.h>
#include <pthread.h>
#include <unistd.h>

struct Editor_State* state;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    state = malloc(sizeof(struct Editor_State));
    state->filename = argv[1];

    printf("\033]0;%s\007", state->filename);
    fflush(stdout);

    load_file(argv[1], state);
    init_editor(state);

    while (1) {
        draw_editor(state);
        int key = getch();
        move_cursor(key, state);
        handle_key(key, state);
    }

    endwin();
    return 0;
}
