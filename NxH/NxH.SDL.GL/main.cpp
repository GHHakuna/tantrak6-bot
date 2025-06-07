#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "nuklear/nuklear.h"
#include "nuklear/nuklear_sdl_gl2.h"

#define NK_IMPLEMENTATION
#define NK_SDL_GL2_IMPLEMENTATION
#define SDL_MAIN_HANDLED
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// WinMain para Windows
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Nuklear + SDL2 + OpenGL",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        SDL_Quit();
        return -1;
    }

    struct nk_context* ctx = nk_sdl_init(window);

    struct nk_colorf bg;
    bg.r = 0.1f;
    bg.g = 0.18f;
    bg.b = 0.24f;
    bg.a = 1.0f;

    // Cargar fuentes si lo deseas
    struct nk_font_atlas* atlas;
    nk_sdl_font_stash_begin(&atlas);
    nk_sdl_font_stash_end();

    bool running = true;
    SDL_Event evt;

    while (running) {
        // Entrada
        nk_sdl_handle_event(&evt);
        while (SDL_PollEvent(&evt)) {
            if (evt.type == SDL_QUIT)
                running = false;
        }

        nk_sdl_render(NK_ANTI_ALIASING_ON);

        // Interfaz gráfica
        if (nk_begin(ctx, "Ventana Transparente", nk_rect(50, 50, 400, 300),
            NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_TITLE)) {

            nk_layout_row_dynamic(ctx, 25, 1);
            nk_label(ctx, "Contenido de la ventana", NK_TEXT_LEFT);
        }
        nk_end(ctx);

        // Transparencia simulada (mezclado OpenGL)
        glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
        glClearColor(bg.r, bg.g, bg.b, bg.a);
        glClear(GL_COLOR_BUFFER_BIT);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Simulación de blur básico (oscurecido semitransparente)
        glColor4f(0.0f, 0.0f, 0.0f, 0.2f);
        glBegin(GL_QUADS);
        glVertex2f(-1.f, -1.f);
        glVertex2f(1.f, -1.f);
        glVertex2f(1.f, 1.f);
        glVertex2f(-1.f, 1.f);
        glEnd();

        nk_sdl_render(NK_ANTI_ALIASING_ON);
        SDL_GL_SwapWindow(window);
    }

    nk_sdl_shutdown();
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
