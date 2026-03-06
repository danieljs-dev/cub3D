#include <criterion/criterion.h>
#include "cub3d.h"

Test(extension, cub_extension_ok)
{
	cr_assert(ft_has_cub_extension("map.cub") == 1);
	cr_assert(ft_has_cub_extension("a/b/cub.cub") == 1);
}

Test(extension, cub_extension_bad)
{
	cr_assert(ft_has_cub_extension("map.ber") == 0);
	cr_assert(ft_has_cub_extension("cub") == 0);
	cr_assert(ft_has_cub_extension(NULL) == 0);
}

Test(extension, xpm_extension_ok)
{
	cr_assert(ft_has_xpm_extension("tex.xpm") == 1);
	cr_assert(ft_has_xpm_extension("a/b/tex.xpm") == 1);
}

Test(extension, xpm_extension_bad)
{
	cr_assert(ft_has_xpm_extension("tex.png") == 0);
	cr_assert(ft_has_xpm_extension("xpm") == 0);
	cr_assert(ft_has_xpm_extension(NULL) == 0);
}
