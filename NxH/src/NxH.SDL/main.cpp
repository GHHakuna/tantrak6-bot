#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT

#include "nuklear.h"
#include "nuklear_sdl_gl2.h"

#include <SDL.h>
#include <SDL_opengl.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
    // Inicializar SDL con soporte OpenGL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* win = SDL_CreateWindow("Nuklear + SDL2 GL2",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    SDL_GLContext glContext = SDL_GL_CreateContext(win);

    // Inicializar Nuklear con la ventana
    struct nk_context* ctx = nk_sdl_init(win);

    // Color de fondo
    struct nk_colorf bg;
    bg.r = 0.10f; bg.g = 0.18f; bg.b = 0.24f; bg.a = 1.0f;

    int running = 1;
    while (running) {
        SDL_Event evt;
        while (SDL_PollEvent(&evt)) {
            if (evt.type == SDL_QUIT)
                running = 0;
            nk_sdl_handle_event(&evt);
        }

        // Entrada
        nk_input_begin(ctx);
        nk_input_end(ctx);

        // Dibujar UI
        if (nk_begin(ctx, "Demo", nk_rect(50, 50, 230, 250),
            NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_SCALABLE |
            NK_WINDOW_MINIMIZABLE | NK_WINDOW_TITLE)) {
            nk_layout_row_static(ctx, 30, 80, 1);
            if (nk_button_label(ctx, "Hola")) {
                SDL_Log("¡Botón presionado!");
            }
        }
        nk_end(ctx);

        // Render
        glViewport(0, 0, 800, 600);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(bg.r, bg.g, bg.b, bg.a);
        nk_sdl_render(NK_ANTI_ALIASING_ON);
        SDL_GL_SwapWindow(win);
    }

    // Limpiar
    nk_sdl_shutdown();
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
