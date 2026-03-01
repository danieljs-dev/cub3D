#include <criterion/criterion.h>
#include "../../../include/cub3d.h"

static void	free_all(t_file *file, t_app *app)
{
	free_textures(&app->tex);
	free_file(file);
}

Test(parse_file, rejects_wrong_extension)
{
	t_file	file;

	cr_assert(parse_cub_file(2, (char *[]){"./cub3D",
		"tests/fixtures/invalid/bad_map_ext.ber", NULL}, &file) != 0);
}

Test(parse_file, reads_valid_file)
{
	t_file	file;

	cr_assert(parse_cub_file(2, (char *[]){"./cub3D",
		"tests/fixtures/valid/simple.cub", NULL}, &file) == 0);
	cr_assert(file.lines != NULL);
	cr_assert(file.line_count > 0);
	free_file(&file);
}

Test(parse_textures, accepts_all_texture_ids)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]){"./cub3D",
		"tests/fixtures/valid/simple.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(app.tex.no != NULL);
	cr_assert(app.tex.so != NULL);
	cr_assert(app.tex.we != NULL);
	cr_assert(app.tex.ea != NULL);
	free_all(&file, &app);
}

Test(parse_textures, rejects_duplicate_identifier)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]){"./cub3D",
		"tests/fixtures/invalid/dup_no.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) != 0);
	free_all(&file, &app);
}

Test(parse_textures, rejects_non_xpm_texture_path)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]){"./cub3D",
		"tests/fixtures/invalid/bad_texture_ext.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) != 0);
	free_all(&file, &app);
}
