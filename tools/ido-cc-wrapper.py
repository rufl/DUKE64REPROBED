#!/usr/bin/env python3
import os
import subprocess
import sys
import tempfile

args = sys.argv[1:]
source_index = len(args) - 1
source = args[source_index]
source_dir = os.path.dirname(os.path.abspath(source))
with open(source, "rb") as source_file:
    source_bytes = source_file.read().replace(b"\r\n", b"\n")
with tempfile.NamedTemporaryFile(suffix=".c", delete=False) as normalized:
    normalized.write(source_bytes)
    normalized_source = normalized.name
ido_args = ["-I", source_dir, *args]
ido_args[-1] = normalized_source
try:
    if subprocess.run([os.environ["IDO_CC"], *ido_args]).returncode == 0:
        raise SystemExit(0)
    preprocess_args = ["-D_LANGUAGE_C"]
    skip_next = False
    for arg in ido_args[:-1]:
        if skip_next:
            skip_next = False
            continue
        if arg in {"-mips2", "-mips3", "-non_shared", "-Xcpluscomm", "-o32"} or arg.startswith("-Wab,"):
            continue
        if arg in {"-G", "-Olimit"}:
            skip_next = True
            continue
        if arg == "-o":
            skip_next = True
            continue
        preprocess_args.append(arg)
    with tempfile.NamedTemporaryFile(suffix=".c", delete=False) as temp:
        preprocessed = temp.name
    try:
        subprocess.run(["gcc", "-E", "-P", *preprocess_args, normalized_source, "-o", preprocessed], check=True)
        ido_args[-1] = preprocessed
        subprocess.run([os.environ["IDO_CC"], *ido_args], check=True)
    finally:
        if os.path.exists(preprocessed):
            os.unlink(preprocessed)
finally:
    if os.path.exists(normalized_source):
        os.unlink(normalized_source)
