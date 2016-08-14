#include <stdio.h>
#include <stdlib.h>
#include <program.h>
#include <argdata.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void program_main(const argdata_t *) {
	dprintf(0, "Init starting up.\n");

	int exec_test_fd = openat(3, "exec_test", O_RDONLY);
	if(exec_test_fd < 0) {
		dprintf(0, "Failed to open exec_test: %s\n", strerror(errno));
		exit(1);
	}

	dprintf(0, "Going to program_exec() exec_test...\n");

	int error = program_exec(exec_test_fd, &argdata_null);
	dprintf(0, "Failed to program_exec: %s\n", strerror(error));
	exit(2);

	// 1. Open the init-binaries directory fd from argdata
	// 2. Read some configuration from the kernel cmdline
	// 3. Start the necessary applications (like dhcpcd)
	// 4. Keep track of their status using poll() / poll_fd()
	//    (so that the application actually always blocks)
	// 5. If needed, open an init RPC socket so that applications or the
	//    kernel can always ask for extra services
}
