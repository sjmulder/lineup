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

    $ lineup -d: /etc/passwd

    root     * 0     0    Charlie &                    /root               /bin/ksh
    toor     * 0     0    Bourne-again Superuser       /root               /rescue/sh
    daemon   * 1     1    The devil himself            /                   /sbin/nologin
    operator * 2     5    System &                     /usr/guest/operator /sbin/nologin
    bin      * 3     7    Binaries Commands and Source /                   /sbin/nologin
    games    * 7     13   & pseudo-user                /usr/games          /sbin/nologin
    ...

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
