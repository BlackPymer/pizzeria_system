#!/usr/bin/env python3
import glob
import os
import re
import subprocess
import sys

BUILD = sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "build")
ROOT = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
GCDA_BASE = os.path.join(BUILD, "CMakeFiles", "run_tests.dir")


def run_gcov(rel_gcda):
    return subprocess.run(
        ["gcov", "-b", "-c", rel_gcda],
        cwd=GCDA_BASE,
        capture_output=True,
        text=True,
    ).stdout


def parse(gcov_out):
    """Return {abs_file: {'lines_total':, 'lines_exec':, 'br_total':, 'br_exec':}}"""
    results = {}
    cur = None
    in_block = False
    for line in gcov_out.splitlines():
        m = re.match(r"File '(.+)'", line)
        if m:
            cur = m.group(1)
            results.setdefault(cur, {})
            in_block = True
            continue
        if in_block and (line.startswith("Creating ") or line.startswith("Removing ")):
            in_block = False
            continue
        if not in_block or cur is None:
            continue
        m = re.match(r"Lines executed:([\d.]+)% of (\d+)", line)
        if m:
            total = int(m.group(2))
            execd = round(float(m.group(1)) / 100.0 * total)
            results[cur].update(lines_total=total, lines_exec=execd)
            continue
        m = re.match(r"Branches executed:([\d.]+)% of (\d+)", line)
        if m:
            total = int(m.group(2))
            execd = round(float(m.group(1)) / 100.0 * total)
            results[cur].update(br_total=total, br_exec=execd)
    return results


def main():
    if not os.path.isdir(GCDA_BASE):
        print(f"gcda dir not found: {GCDA_BASE}", file=sys.stderr)
        return 1

    aggregated = {}
    for gcda in sorted(glob.glob(os.path.join(GCDA_BASE, "**", "*.gcda"), recursive=True)):
        rel = os.path.relpath(gcda, GCDA_BASE)
        src = os.path.join(ROOT, rel[: -len(".gcda")])
        if not src.endswith(".cpp") or os.path.sep + "tests" + os.path.sep in src:
            continue
        for path, st in parse(run_gcov(rel)).items():
            if not st or path not in src:
                continue
            aggregated[path] = st

    rows = sorted(aggregated.items())
    if not rows:
        print("No project sources with coverage data found.", file=sys.stderr)
        return 1

    l_tot = l_exec = b_tot = b_exec = 0
    print("File                                         Lines        Branches")
    print("-------------------------------------------- ----------  ----------")
    for path, st in rows:
        lt, le, bt, be = st.get("lines_total", 0), st.get("lines_exec", 0), st.get("br_total", 0), st.get("br_exec", 0)
        lp = f"{100.0 * le / lt:.1f}%" if lt else "-"
        bp = f"{100.0 * be / bt:.1f}%" if bt else "-"
        l_tot += lt; l_exec += le; b_tot += bt; b_exec += be
        print(f"{path.replace(ROOT + os.sep, ''):44s} {le:>3}/{lt:<3} {lp:>5}   {be:>3}/{bt:<3} {bp:>5}")

    print("-" * 66)
    print(f"{'TOTAL':44s} {l_exec:>3}/{l_tot:<3} {100.0*l_exec/l_tot:>5.1f}%   {b_exec:>3}/{b_tot:<3} {100.0*b_exec/b_tot:>5.1f}%")
    print()
    print(f"Line coverage:     {l_exec}/{l_tot} lines ({100.0*l_exec/l_tot:.1f}%)")
    print(f"Branch coverage:   {b_exec}/{b_tot} branches ({100.0*b_exec/b_tot:.1f}%)")
    return 0


if __name__ == "__main__":
    sys.exit(main())