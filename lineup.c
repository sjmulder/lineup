 /* libc */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdnoreturn.h>
 /* unix */
#include <unistd.h>
#include <getopt.h>
#include <sysexits.h>
#include <err.h>

static noreturn void
usage(void)
{
	fprintf(stderr, "usage: lineup [-d delim] [file]\n");
	exit(EX_USAGE);
}

int
main(int argc, char **argv)
{
	static int widths[512];
	int n_cols=1, col=0, width=0, c;
	char sep=' ', *in_name="<stdin>";
	FILE *in_file=stdin;

	while ((c = getopt(argc, argv, "hd:")) != -1)
		switch (c) {
		case 'd':
			if (strlen(optarg) != 1)
				errx(EX_USAGE, "-d takes one char");
			sep = optarg[0];
			break;
		case 'h':
		case '?':
		default:
			usage();
		}
	
	argc -= optind;
	argv += optind;

	if (argc > 1)
		errx(EX_USAGE, "too many arguments (see -h)");
	if (argc == 0 && isatty(STDIN_FILENO))
		errx(EX_USAGE, "stdin is a TTY, specify a file or '-'");
	if (argc == 1 && strcmp(argv[0], "-") != 0) {
		in_name = argv[0];
		if (!(in_file = fopen(in_name, "r")))
			err(1, "%s", argv[0]);
	}

	while ((c = fgetc(in_file)) != EOF)
		if (c == '\n')
			width = col = 0;
		else if (c == sep) {
			if (++col > n_cols)
				n_cols = col;
			width = 0;
		} else if (++width > widths[col])
			widths[col] = width;

	if (ferror(in_file))
		err(1, "%s", in_name);
	if (fseek(in_file, 0, SEEK_SET) == -1)
		err(1, "fseek(%s)", in_name);
	
	width = col = 0;
	while ((c = fgetc(in_file)) != EOF)
		if (c == '\n') {
			fputc('\n', stdout);
			width = col = 0;
		} else if (c == sep) {
			for (; width <= widths[col]; width++)
				fputc(' ', stdout);
			width = 0;
			col++;
		} else {
			fputc(c, stdout);
			width++;
		}

	if (ferror(in_file))
		err(1, "%s", in_name);

	return 0;
}
