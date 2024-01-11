#include "image.h"
#include "parsing.h"
#include "executor.h"

int main(int argc, char** argv) {
    Parsing parse(argc, argv);
    Image image(0, 0);
    image.Read(parse.input_file);
    Executor(image, parse.args);
    image.Export(parse.output_file);
    return 0;
}
