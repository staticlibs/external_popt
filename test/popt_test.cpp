/* 
 * File:   popt_test.cpp
 * Author: alex
 *
 * Created on October 28, 2016, 1:10 PM
 */

#include "popt.h"

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "staticlib/config/assert.hpp"

class Options {
public:
    // options list
    char* config;
    int help;
    int usage;

    std::string parse_error;
    std::vector<std::string> args;
    struct poptOption table[4];
    poptContext ctx;

    Options(int argc, char** argv) :
    // options initialization
    config(NULL),
    help(0),
    usage(0),

    ctx(NULL) {
        // options table
        struct poptOption tb[] = {
            { "config", 'c', POPT_ARG_STRING, &config, static_cast<int> ('c'), "Path to config file", "config.json" },
            { "help", 'h', POPT_ARG_NONE, &help, static_cast<int> ('h'), "Show this help message", NULL },
            { "usage", '\0', POPT_ARG_NONE, &usage, 0, "Display brief usage message", NULL },
            { NULL, 0, 0, NULL, 0, NULL, NULL}
        };
        memcpy(table, tb, sizeof (tb));

        { // create context
            ctx = poptGetContext(NULL, argc, const_cast<const char**> (argv), table, POPT_CONTEXT_NO_EXEC);
            if (!ctx) {
                parse_error.append("'poptGetContext' error");
                return;
            }
        }

        { // parse options
            int val;
            while ((val = poptGetNextOpt(ctx)) >= 0);
            if (val < -1) {
                parse_error.append(poptStrerror(val));
                parse_error.append(": ");
                parse_error.append(poptBadOption(ctx, POPT_BADOPTION_NOALIAS));
                return;
            }
        }

        { // collect arguments
            const char* ar;
            while (NULL != (ar = poptGetArg(ctx))) {
                args.push_back(std::string(ar));
            }
        }
    }

    ~Options() {
        poptFreeContext(ctx);
    }

private:
    Options(const Options& other);

    Options& operator=(const Options& other);

};

void test_linking(int argc, char** argv) {
    Options opts(argc, argv);
    slassert(opts.parse_error.empty());
    if (opts.help) {
        poptPrintHelp(opts.ctx, stderr, 0);
    }
}

int main(int argc, char** argv) {
    try {
        test_linking(argc, argv);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
