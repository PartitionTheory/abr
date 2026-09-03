#include <stdio.h>
#include <string.h>
#include "abr_plugin_loader.h"
#include "abr_plugin.h"
#include "abr_plugin_registry.h"

int cli_split_main(int argc, char **argv);
int cli_join_main(int argc, char **argv);

int abr_cli_dispatch(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr,
            "usage:\n"
            "  abr split <file|-> <bitWidth>\n"
            "  abr join  <hexFile|-> <bitWidth> <originalBits>\n"
        );
        return 1;
    }

    const char *cmd = argv[1];

    if (strcmp(cmd, "split") == 0)
        return cli_split_main(argc, argv);

    if (strcmp(cmd, "join") == 0)
        return cli_join_main(argc, argv);
	if (strcmp(cmd, "plugin") == 0) {
	    if (argc < 3) {
		fprintf(stderr, "usage: abr plugin <name|--class tag>\n");
		return 1;
	    }

	    /* class-based routing */
	    if (strcmp(argv[2], "--class") == 0 && argc >= 4) {
		const char* class_tag = argv[3];
		abr_plugin* p = abr_plugin_registry_find_by_class(class_tag);

		if (!p) {
		    fprintf(stderr, "error: no plugin with class '%s'\n", class_tag);
		    return 1;
		}

		abr_plugin_input input = { .json = "{}" };
		abr_plugin_result result = p->execute(&input);

		printf("%s\n", result.json);
		return 0;
	    }

	    /* name-based routing */
	    const char* name = argv[2];
            abr_plugin* p = abr_plugin_registry_find_by_name(name);

	    if (!p) {
		fprintf(stderr, "error: no plugin named '%s'\n", name);
		return 1;
	    }

	    abr_plugin_input input = { .json = "{}" };
	    abr_plugin_result result = p->execute(&input);

	    printf("%s\n", result.json);
	    return 0;
	}
    fprintf(stderr, "ABR: invalid command '%s'\n", cmd);
    return 1;
}

