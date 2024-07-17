#include "garrulus/asserts.h"
#include "garrulus/logger.h"

int main(int argc, char *argv[]) {
    G_FATAL("this is fatal: %d", 43)
    G_ERROR("this is error: %d", 43)
    G_WARN( "this is warn: %d" , 43)
    G_INFO( "this is info: %d" , 43)
    G_DEBUG("this is debug: %d", 43)
    G_TRACE("this is trace: %d", 43)

    G_ASSERT_MSG(1 != 0, "This should be true")
    G_ASSERT_MSG(1 == 0, "This should be false")
    return 0;
}
