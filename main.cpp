#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main(int argc, const char* const* argv) {
    doctest::Context context;
    
    context.applyCommandLine(argc, argv);

    int res = context.run(); // Run the tests
    if (context.shouldExit()) {
        return res; // Exit if requested
    }
    return res;
}