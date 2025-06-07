#include "style.h"
#include "nuklear.h"

void apply_ui_style(struct nk_context* ctx) {
	//struct nk_color table[NK_COLOR_COUNT];
// Cambiar fondo de la ventana
	ctx->style.window.fixed_background = nk_style_item_color(nk_rgb(37, 40, 46));

	// Cambiar color de botones normales
	ctx->style.button.normal = nk_style_item_color(nk_rgb(70, 70, 120));

	// Cambiar color de botones al hacer hover
	ctx->style.button.hover = nk_style_item_color(nk_rgb(100, 100, 160));

	// Cambiar color de botones al hacer click
	ctx->style.button.active = nk_style_item_color(nk_rgb(50, 50, 90));

	// Cambiar color del texto de los botones
	ctx->style.button.text_normal = nk_rgb(255, 255, 255);
	ctx->style.button.text_hover = nk_rgb(230, 230, 230);
	ctx->style.button.text_active = nk_rgb(200, 200, 200);

	// Cambiar borde de la ventana
	ctx->style.window.border_color = nk_rgb(40, 40, 40);
	ctx->style.window.border = 1;

	// Cambiar color del título de la ventana
	ctx->style.window.header.normal = nk_style_item_color(nk_rgb(40, 40, 40));
	ctx->style.window.header.hover = nk_style_item_color(nk_rgb(40, 40, 40));
	ctx->style.window.header.active = nk_style_item_color(nk_rgb(167, 49, 70));
	ctx->style.window.header.label_normal = nk_rgb(255, 255, 255);

	//nk_style_default(ctx);
}
