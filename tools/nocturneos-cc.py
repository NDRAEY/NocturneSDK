#!/usr/bin/python3

import os
import argparse
import pathlib
import subprocess


# Get current absolute path
def get_absolute_sdk_path():
    p = pathlib.Path(os.path.dirname(os.path.realpath(__file__)))

    return p.parent


def generate_compiler_commands_from_settings(settings: dict[str, str],
                                             input_file: str,
                                             output_file: str) -> list[str]:
    commands: list[str] = []
    commands += ["-nostdlib", "-fno-builtin", "-ggdb3", "-O0"]
    commands += ["-fno-pie"]
    commands += ["-m32", "-march=i386"]  # Force generate 32-bit code

    if not settings["compiler_flavor"].startswith("clang"):
        # Use LLVM ld instead of gcc's builtin linker
        commands += ["-fuse-ld=lld"]

    # Use them to remove unneccesary code
    commands += ["-ffreestanding", "-mno-red-zone", "-fno-stack-protector"]

    # Default argument, used everywhere
    commands += [f"-I{get_absolute_sdk_path()}/../nocturneos/include"]

    commands += ["-c"]
    commands += ["-fno-pic"]

    return commands


def main():
    parser = argparse.ArgumentParser(
                    description='Compiler wrapper for NocturneOS SDK')

    # NCC just does nothing, but receives compiler command.

    # Example usage of NCC is almost equal as GCC:
    # nocturneos-cc hello.c -o hello.o

    # Capture all arguments that come after '--' (for the compiler)
    parser.add_argument('--verbose', action='store_true', help='Be verbose')
    parser.add_argument('--print-sdk-path', action='store_true', help='Print SDK path and exit')
    parser.add_argument('--linclude', default="", type=str, help='Include other Nocturne libraries (for example --linclude="M" will add libNocturneM.a (math library))')
    parser.add_argument('-c', action='store_true', help='Compile into object file')
    parser.add_argument('-o', help='Output file')
    parser.add_argument('--flags', help='Additional flags to compiler', default="", type=str)
    parser.add_argument('input_file', nargs='*', help="Compiler command and arguments")

    # Parse command line arguments.
    args: argparse.Namespace = parser.parse_args()

    if args.print_sdk_path:
        print(get_absolute_sdk_path())
        exit(0)

    if not args.input_file:
        print("error: no input file")
        exit(1)

    # Inject custom arguments

    cc = "gcc"

    settings: dict[str, str] = {
        "compiler_flavor": cc,
        "is_output_object": args.c
    }

    if not args.o:
        if args.c:
            splitted_args = args.input_file[-1].split("/")[-1].split(".")

            if len(splitted_args) == 1:
                args.o = splitted_args[0]
            else:
                args.o = '.'.join(splitted_args[:-1])
        else:
            args.o = "a.out"

    nargs = generate_compiler_commands_from_settings(
                    settings,
                    input_file=args.input_file,
                    output_file=args.o)

    if args.verbose:
        print("COMMAND =>", cc, *nargs)

    commands: list[str] = [cc,
                             *nargs,
                             args.flags,
                             *args.input_file,
                             "-o",
                             args.o + ".o"
                             ]

    commands = [command for command in commands if command]

    print(commands)
    # Run compiler
    status = subprocess.call(commands)

    if status != 0:
        print("Compilation failed")
        exit(status)

    add_libs: list[str] = args.linclude.split(',')

    # If we are compiling into a program instead of object, we run linker then.
    if not settings["is_output_object"]:
        subprocess.call([
            "ld.lld",
            args.o + ".o",
            f"{get_absolute_sdk_path()}/lib/libNocturneCrti.a",
            f"{get_absolute_sdk_path()}/lib/libNocturneC.a",
            *[f"{get_absolute_sdk_path()}/lib/libNocturne{lib}.a" for lib in add_libs if lib],
            f"-T{get_absolute_sdk_path()}/share/link.ld",
            "-o",
            args.o
        ])

        # And remove the object file.
        os.remove(args.o + ".o")


if __name__ == "__main__":
    main()
