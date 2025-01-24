#!/usr/bin/python3

import os
import argparse
import pathlib
import subprocess

# Get current absolute path
def get_absolute_sdk_path():
    p = pathlib.Path(os.path.dirname(os.path.realpath(__file__)))

    return p

def generate_compiler_commands_from_settings(settings: dict[str, str], args) -> list[str]:
    commands = []
    commands += ["-nostdlib", "-fno-builtin"]
    commands += ["-fno-pic", "-fno-pie"]
    commands += ["-m32", "-march=i386"]  # Force generate 32-bit code
    
    if not settings["compiler_flavor"].startswith("clang"):
        commands += ["-fuse-ld=lld"]   # Use LLVM ld instead of gcc's builtin linker
    
    commands += ["-ffreestanding", "-mno-red-zone", "-fno-stack-protector"]  # Use them to remove unneccesary code
    
    commands += [f"-I{get_absolute_sdk_path()}/../nocturneos/include"]  # Default argument, used everywhere

    commands += args

    if not settings["is_output_object"]:
        commands += [f"{get_absolute_sdk_path()}/../nocturneos/lib/libNocturneC.a",
                     f"-T{get_absolute_sdk_path()}/../nocturneos/share/link.ld"]

    return commands

def main():
    parser = argparse.ArgumentParser(description='Compiler wrapper for NocturneOS SDK')

    # NCC just does nothing, but receives compiler command.
    # NCC just need to add some flags such as `-IInclude` and others
    # Compiler command must come after `--`

    # Example usage of NCC:
    # nocturneos-cc -- clang hello.c -o hello.o

    # Capture all arguments that come after '--' (for the compiler)
    parser.add_argument('--verbose', action='store_true', help='Be verbose')
    parser.add_argument('compiler_args', nargs='*', help="Compiler command and arguments")


    # Parse args

    args: argparse.Namespace = parser.parse_args()

    print(args.compiler_args)
    print(get_absolute_sdk_path())

    # Inject custom arguments

    cc, *nargs = args.compiler_args

    settings = {
        "compiler_flavor": cc,
        "is_output_object": bool([i for i in nargs if i == '-c'])
    }

    nargs = generate_compiler_commands_from_settings(settings, nargs)


    if args.verbose:
        print("COMMAND =>", cc, *nargs)

    subprocess.call([cc, *nargs])  # Run compiler
    


if __name__ == "__main__":
    main()