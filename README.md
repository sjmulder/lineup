lineup
======
Format tabular files.

**lineup** [**-d** *delim*] [*file*]

Formats a tabular file (e.g. tab or colon-separated) so that the
columns line up.  The field delimiter *delim* defaults to the tab
character.

Example
-------
Format */etc/passwd*:

    lineup -d: /etc/passwd

Bugs
----
Doesn't account for tabs, control characters, double-width characters,
composable characters, etc. Can't read from a pipe. Missing some useful
features.

See [TODO.md](TODO.md)

Compiling
---------
Should work on Linux, BSDs, macOS, etc:

    make
    make check

Author
------
Sijmen J. Mulder (<ik@sjmulder.nl>). See [LICENSE.md](LICENSE.md).
