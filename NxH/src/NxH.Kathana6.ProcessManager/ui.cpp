#include "ui.h"
#include <windows.h>
#include "window.h"
#include "nuklear.h"

static int checked = 0;
static char text[64] = "";
static float value = 0.5f;
static int checkbox_checked = 0;
static int radio_active = 0;
static int combo_selected = 0;

void render_ui(struct nk_context* ctx, int* running) {
    if (nk_begin(ctx, "Tantra Kathana 6", nk_rect(0, 40, WINDOW_WIDTH, WINDOW_HEIGHT - 40),
        NK_WINDOW_NO_SCROLLBAR | NK_WINDOW_BORDER  | NK_WINDOW_MOVABLE)) {
       
        nk_layout_row_dynamic(ctx, 30, 1);
        nk_label(ctx, "Ventana con controles:", NK_TEXT_LEFT);

        // Checkbox
        nk_checkbox_label(ctx, "Habilitar opción", &checkbox_checked);

        // Radio buttons
        nk_label(ctx, "Elige una opción:", NK_TEXT_LEFT);
        if (nk_option_label(ctx, "Opción 1", radio_active == 0)) radio_active = 0;
        if (nk_option_label(ctx, "Opción 2", radio_active == 1)) radio_active = 1;

        // Combo box
        static const char* opciones[] = { "Uno", "Dos", "Tres", "Cuatro", "Cinco" };
        combo_selected = nk_combo(ctx, opciones, 5, combo_selected, 25, nk_vec2(200, 200));

        // Mostrar selección actual (opcional)
        nk_label(ctx, opciones[combo_selected], NK_TEXT_LEFT);

    }
    nk_end(ctx);

     // Segunda ventana (derecha)
    /*if (nk_begin(ctx, "Control Panel",
        nk_rect(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT),
        NK_WINDOW_NO_SCROLLBAR | NK_WINDOW_BORDER | NK_WINDOW_MINIMIZABLE |
        NK_WINDOW_MOVABLE | NK_WINDOW_CLOSABLE))
    {
        nk_layout_row_dynamic(ctx, 30, 2);
        nk_label(ctx, "Opción A", NK_TEXT_LEFT);
        nk_button_label(ctx, "Activar");

        nk_label(ctx, "Opción B", NK_TEXT_LEFT);
        nk_button_label(ctx, "Desactivar");
    }
    nk_end(ctx);*/
}
