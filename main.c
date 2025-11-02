#include <termbox2.h>
#include <stdlib.h>

int main() {
    // Initialize Termbox2
    if (tb_init() != 0) {
        return 1;
    }

    // Get terminal size
    int w = tb_width();
    int h = tb_height();

    // Fill the entire screen with black background
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            tb_set_cell(x, y, ' ', TB_DEFAULT, TB_BLACK);
        }
    }

    // Draw '@' at (10,5) with green foreground and black background
    tb_set_cell(10, 5, '@', TB_GREEN, TB_BLACK);

    tb_present();

    // Wait for a key event (blocks until key pressed)
    struct tb_event ev;
    tb_peek_event(&ev, -1);

    tb_shutdown();
    return 0;
}
