#include <criterion/criterion.h>
#include "cub3d.h"

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

Test(parse_colors, accepts_valid_colors)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"tests/fixtures/valid/simple.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) == 0);
	free_all(&file, &app);
}

Test(parse_colors, rejects_when_colors_missing_both)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/invalid/color_none.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) != 0);
	free_all(&file, &app);
}

Test(parse_colors, rejects_when_one_identifier_missing)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/invalid/color_missing.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) != 0);
	free_all(&file, &app);
}

Test(parse_colors, rejects_missing_floor_rgb_component)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/invalid/color_missing_floor_rgb.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) != 0);
	free_all(&file, &app);
}

Test(parse_colors, rejects_missing_ceiling_rgb_component)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/invalid/color_missing_ceiling_rgb.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) != 0);
	free_all(&file, &app);
}

Test(parse_colors, rejects_invalid_rgb_value)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/invalid/color_invalid_rgb.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) != 0);
	free_all(&file, &app);
}

Test(parse_map, accepts_map_only_file)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/invalid/map_only.cub", NULL}, &file) == 0);
	cr_assert(parse_map(&app, &file) == 0);
	cr_assert(file.map != NULL);
	cr_assert(file.map_height > 0);
	cr_assert(file.map_width > 0);
	free_file(&file);
}

Test(parse_map, rejects_missing_map)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/invalid/empty.cub", NULL}, &file) == 0);
	cr_assert(parse_map(&app, &file) != 0);
	free_file(&file);
}

Test(parse_map, rejects_invalid_map_character)
{
	t_file	file;
	int		start;
	int		end;

	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"tests/fixtures/invalid/invalid_map_char.cub", NULL}, &file) == 0);
	cr_assert(find_map_range(&file, &start, &end) == 1);
	cr_assert(validate_map_range(&file, start, end) == 0);
	free_file(&file);
}

Test(map_validation, accepts_closed_map)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/valid/simple.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) == 0);
	cr_assert(parse_map(&app, &file) == 0);
	cr_assert(validate_map_closed(&file) == 0);
	free_textures(&app.tex);
	free_file(&file);
}

Test(map_validation, rejects_open_map_wall_hole)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/invalid/wall_hole_north.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) == 0);
	cr_assert(parse_map(&app, &file) == 0);
	cr_assert(validate_map_closed(&file) != 0);
	free_textures(&app.tex);
	free_file(&file);
}

Test(map_validation, rejects_map_too_small)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/invalid/map_too_small.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) == 0);
	cr_assert(parse_map(&app, &file) == 0);
	cr_assert(validate_map_closed(&file) != 0);
	free_textures(&app.tex);
	free_file(&file);
}

Test(player_spawn, rejects_missing_spawn)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/invalid/map_too_small.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) == 0);
	cr_assert(parse_map(&app, &file) == 0);
	cr_assert(validate_player_spawn(&app, &file) != 0);
	free_all(&file, &app);
}

Test(player_spawn, rejects_multiple_spawns)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/invalid/multiple_players.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) == 0);
	cr_assert(parse_map(&app, &file) == 0);
	cr_assert(validate_player_spawn(&app, &file) != 0);
	free_all(&file, &app);
}

Test(player_spawn, accepts_single_spawn_and_stores_it)
{
	t_file	file;
	t_app	app;

	ft_bzero(&app, sizeof(app));
	cr_assert(parse_cub_file(2, (char *[]) {"./cub3D",
		"maps/valid/simple.cub", NULL}, &file) == 0);
	cr_assert(parse_textures(&app, &file) == 0);
	cr_assert(parse_colors(&app, &file) == 0);
	cr_assert(parse_map(&app, &file) == 0);
	cr_assert(validate_player_spawn(&app, &file) == 0);
	cr_assert(app.spawn_dir != 0);
	cr_assert(app.spawn_x >= 0);
	cr_assert(app.spawn_y >= 0);
	cr_assert(file.map[app.spawn_y][app.spawn_x] == '0');
	free_all(&file, &app);
}
